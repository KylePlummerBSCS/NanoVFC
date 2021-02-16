# NanoVFC2
This program scrubs records to be submitted to the New York State Vaccines for Children system. This system, part of NYSIIS, tracks vaccines administered by physician practices in order to keep a record and to automatically manage inventory. At the time NanoVFC was written VFC would not accept records which were deleted, however, the NextGen EHR would always include these records. When VFC encountered these records, it would throw an error and fail to properly parse the file. 
  
NanoVFC looks for records which were deleted, flagged by a 'D' in the RXA-21 field. Because NYS VFC could not properly parse records with this flag, we decided to identify them and remove the whole record. Previously Application Support team members were scrubbing these files with thousands of records by hand 1-2 times per week before uploading.
 
The initial version was command line based, but was hastily converted to a simple windows GUI when this developer left the company. It was designed in such a way to easily implement other scrubbing operations, but removal of deleted vaccine records was the only one ever implemented. 
 
The program takes an HL7 (Health Language v. 7) text file as input. HL7 is a pipe delimited standard for transmitting information to different healthcare software. Each line begins with a three letter identifier indicating what is contained there. NanoVFC steps through the file line by line identifying each record by the header line identified by "MSH". Each new record is kept separate and further separated into lines and fields. Once parsed, scrubbing can begin.
 
The RXA-21 Delete scrubbing operation searches each message for the RXA line and checks field 21 for a 'D'. If the character is found indicating the record was deleted, that entire record is excluded from the output. 
 
When scrubbing operations are complete the file is reconstituted without the removed records and output in a file marked "OUT". Those records removed are alsp kept, output in a file marked "DEL".
 
 
# Source
The code found in 
