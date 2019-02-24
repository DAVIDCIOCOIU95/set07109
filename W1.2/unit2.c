#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

/* --enum
*/

enum CHOICE
{
	EXIT = 0,
	HELLO = 1,
	GOODBYE = 2

};

/* ---struct---

struct student
{
	unsigned int matric;
	char *name;
	char *address;
};

void print_student(struct student s)
{
	printf("matric number: %u\n", s.matric);
	printf("name: %s\n", s.name);
	printf("address: %s\n", s.address);
}
*/





int main(int argc, char **argv)
		
/* --- PRINT SIZE OF FORMAT SPECIFIER ---
{
	printf("The size of int is %d bytes\n", sizeof(int));
	printf("The size of int is %d bytes\n", sizeof(char));
	printf("The size of int is %d bytes\n", sizeof(double));
	printf("The size of int is %d bytes\n", sizeof(float));
	
	return 0;
}
*/



/* --- UNSIGNED VALUES ---

{
	int a = -500;
	int y = 6;
	unsigned int b = -500;
	unsigned int c = (unsigned int) a;
	float f = -500;
	
	printf("a signed: %d, a unsigned: %u\n", a, a);
	printf("b signed: %d, b unsigned: %u\n", b, b);
	printf("c signed: %d, c unsigned: %u\n", c, c);
	printf("f signed: %d, f unsigned %u\n", f, f);
    printf("\n");
	printf("0 is false and 1 is true in this case\n");
	printf("a == b: %d\n", a == b);
	printf("a == c: %d\n", a == c);
	printf("a == f: %d\n", a == f);
    printf("a == y: %d\n", a == y);
	
	return 0;
}

*/

/* --- LIMITS ---


{
	printf("unsigned int is %d bytes, min value %u, max value %u\n", sizeof(unsigned int), 0, UINT_MAX);
	printf("int is %d bytes, min value %d, max value %d\n", sizeof(int), INT_MIN, INT_MAX);
	
}
*/
 /*---Casting---

{
	int x = 10;
	char *y = (char*)x;
	printf("%d\n", y);
	
	int a = 20;
	int *p = &a;
	//p has to be assigned an address then we can change th value of a from *p
	*p = 10;
	printf("%d", *p);
	
}

*/

/* ---struct---

{
	//output the size of the struct
	printf("the size of the struct is: %d\n", sizeof(struct student));	
	
	//create a student data structure
	struct student s;
	s.matric = 42001290;
	s.name = "Kevin Chalmers";
	s.address = "School of Computing";
	
	//print student data
	print_student(s);
	
	return 0;
	
}
*/

/*---enum---
*/
{
	int flag = 1; 
while (flag == 1) 
{
	//print menu
	printf("1 - say hello\n");
	printf("2 - say goodbye\n");
	printf("3 - exit\n");
	printf("Enter choiche: ");
	
	//read input
	char buffer[20];
	fgets(buffer, 20, stdin);
	enum CHOICE ch = atoi(buffer);
	
	//work on input
	switch (ch)
	{
		case HELLO:
		    printf("Hello World!\n");
			break;
		case GOODBYE:
		     printf("Goodbye World\n");
			break;
		case EXIT:
		     printf("Exiting...\n");
			 flag = 0;
			break;
		default:
		     printf("invalid input\n");
			break;
	}
	
	return 0;
}


}

