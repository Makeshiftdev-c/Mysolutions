Question Specification:  
  
Extend the canopen.c program of Section 22.2 so that the user may  
put any number of files on the command line:  
  
canopen foo bar baz  
  
This program shoudl print a separate can be opened or can't be  
message for each file. Have the program terminate with status  
EXIT_FAILURE if one or more of the files can't be opened.
