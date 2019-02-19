Name of Application: preprocess
Building toolchain: Developer Command Prompt VS 2017

Files available:
- preprocess.c
- makefile

Files required:
- aFile.c
- aFile.h

Build from command line inputs: 
nmake preprocess

Options:
preprocess -i name_file.c
preprocess -c name_file.c

Description:
an App that counts the number of non-empty lines in a .c file;
counts the number of comments;
outputs a .o file with (-i command) or without (-c command) comments with the following specifications:
1)the #include "hedear_file.h" is sobstituted with the content of the header file;
2)the #define constant_name value are removed and const_name is replaced with value through the file whenever it appers; 


