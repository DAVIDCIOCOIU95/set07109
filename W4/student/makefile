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
	
clean: 
	del *.obj
	del *.exe
	del *.asm
	del *.lib