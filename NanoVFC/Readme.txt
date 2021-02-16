This is the source code for NanoVFC2. It is fugly. I originally wrote NanoVFC just for myself 
to do the RXA-21 delete operations and it was just command line controlled. I figured before I 
left someone else in charge of uploading our VFC files to NYSIIS I had to update it to use 
Windows GUI. I took the open file dialog example code from the MS Windows API and just shoved
NanoVFC in there. I had to jiggle some stuff. I'll try to trim out all the extra junk and the 
unfinished operations I had in NanoVFC. It's ugly but it works.

Run NanoVFC2.exe and you are greeted with a prompt to choose a file. Navigate to and select
a .txt or .hl7 file. This should remove any messages that contain the value "D" in segment RXA-21.
Application will output two new files in the same location, "_DEL" and "_OUT". _DEL contains 
anything removed from _OUT. The original file remains untouched. 

Upload the output (..._OUT.txt) file to NYSIIS. 

The comments in Source.cpp are from the code examples I yoinked from MS Windows API. The other 
functions between BasicFileOpen() and wWinMain() are unused and inaccessable to users.