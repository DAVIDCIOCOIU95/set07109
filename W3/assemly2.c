#include <stdio.h>

int main(int argc, char **argv)
{
	int x = 0;
	printf("Before assembly, x = %d\n", x);
	
	__asm
	{
		//same as x = 500;
		mov x, 500
	}
	
	printf("After assembly, x = %d\n", x);
	
	return 0;
}
