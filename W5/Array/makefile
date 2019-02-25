testApp:
	cl /c sort.cpp generate.cpp
	lib /OUT:array.lib sort.obj generate.obj
	cl /c testApp.cpp
	link testApp.obj array.lib 
	testApp

readingBinary:
    cl /c sort.cpp generate.cpp
	lib /OUT:array.lib sort.obj generate.obj
	cl /c readingBinary.cpp
	link readingBinary.obj array.lib 
	readingBinary

writingFile:
	cl /c sort.cpp generate.cpp
	lib /OUT:array.lib sort.obj generate.obj
	cl /c writingFile.cpp
	link writingFile.obj array.lib 
	writingFile
	

clean: 
	del *.obj
	del *.exe
	del *.asm
	del *.lib