hello:
	cl hello.c
	cl /c /Fa hello.c
	hello
	
student:
	cl /c student.c
	lib /OUT:student.lib student.obj
	cl /c print_student.c
	link print_student.obj student.lib
	print_student
	
test:
	cl /c search.c sort.c generate.c 
	lib /OUT:array.lib search.obj sort.obj generate.obj
	cl /c test.c
	link test.obj array.lib
	test
	
clean: 
	del *.obj
	del *.exe
	del *.asm
	del *.lib