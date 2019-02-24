#include <stdio.h> 

int main(int argc, char **argv)
{
	int x = 500;
	int y = 200;
	
	__asm
	{
		push x
		push y
		pop x
		pop y
	}
	
	printf("The value of x and y after assembler are:  x = %d;  y = %d\n", x ,y);
	return 0;
}//end main