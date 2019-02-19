#pragma once

// A structure representing a student 
struct student
{
	unsigned int matric;
	char *name;
	char *address;
};

// Declaration of print student method - not implementation
void print_student(struct student s);