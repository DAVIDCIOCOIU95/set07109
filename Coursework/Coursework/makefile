preprocessor:
	cl /c nonEmptyLines.c numberComments.c removeComments.c 
	lib /OUT:preprocessor.lib nonEmptyLines.obj numberComments.obj removeComments.obj 
	cl /c preprocessor.c 
	link preprocessor.obj preprocessor.lib 
	
	
clean: 
	del *.obj
	del *.exe
	del *.asm
	del *.lib
	del *.o