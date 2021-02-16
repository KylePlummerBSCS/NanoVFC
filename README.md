# NanoVFC2
This program scrubs records to be submitted to the New York State Vaccines for Children system. This system, part of NYSIIS, tracks vaccines administered by physician practices in order to keep a record and to automatically manage inventory. At the time it was written VFC and NextGen EHR, the medical record used by St. Peter's Health Partners, were not using the same HL7 standard. This caused some problems pertaining to records which were deleted (often doses were entered in error, or declined by parents). 
 
NanoVFC looks for records which were deleted, flagged by a 'D' in the RXA-21 field. Because NYS VFC could not properly parse records with this flag, we decided to identify them and remove the whole record. Previously Application Support team members were scrubbing these files with thousands of records by hand 1-2 times per week before uploading.

The initial version was command line based, but was hastily converted to a simple windows GUI when this developer left the company. It was designed in such a way to easily implement other scrubbing operations, but removal of deleted records was the only one ever implemented. 

The program takes an HL7 (Health Language v. 7) text file as input. HL7 is a pipe delimited standard for transmitting information to different healthcare software. NanoVFC first separates each record delimited by carriage returns. It then separates each line delimited by 

