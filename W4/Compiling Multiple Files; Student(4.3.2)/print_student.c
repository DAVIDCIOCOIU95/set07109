#include "student.h"

int main(int argc, char **argv)
{
	struct student s;
	s.matric = 40323;
	s.name = "David Ciocoiu";
	s.address = "Edinburgh Napier University";
	print_student(s);
	
	return 0;
}

