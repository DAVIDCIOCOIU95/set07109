Name of Application: preprocess
Building toolchain: Developer Command Prompt VS 2017
________________________________________________________________________________________________________________________

FILES 

Files available:
- preprocess.c
- makefile

Files required:
- string_functions.h  string_functions.c
- math_functions.h  math_functions.c
________________________________________________________________________________________________________________________

BUILDING

Build from command line inputs: 
nmake preprocess

Cleaning folder from command line:
nmake clean

Options:
preprocess -i name_file.c    	 --> outputs: a preprocessed file(see Description) without comments;
preprocess -i name_file.c -c 	 --> outputs: a preprocessed file(see Description) with comments;

________________________________________________________________________________________________________________________

DESCRIPTION

An App that:
-counts the number of non-empty lines in a .c file;
-counts the number of comments;
-outputs a .o file (in the same folder) without comments(-i command) or with comments (-c command) with the following specifications:
1)the #include "hedear_file.h" is sobstituted with the content of the header file;
2)the #define constant_name value are removed and const_name is replaced with value through the file whenever it appears; 


