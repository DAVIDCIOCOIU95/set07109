binary: 
	
	cl /c search.c sort.c generate.c 
	lib /OUT:array.lib search.obj sort.obj generate.obj
	cl /c binary.c
	link binary.obj array.lib
	binary
	
writeFile:
	cl /c search.c sort.c generate.c
	lib /OUT:array.lib search.obj sort.obj generate.obj 
	cl /c writeFile.c
	link writeFile.obj array.lib
	writeFile
	
	
clean: 
	del *.obj
	del *.exe
	del *.asm
	del *.lib