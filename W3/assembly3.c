#include <stdio.h>

int main (int argc, char **argv)
{
	int x = 500;
	int y = 200;
	int z = 0;
	
	//add using assembly
	__asm
	{
		mov ecx, x
		add ecx, y
		mov z, ecx
	}
	
	printf("z = %d\n", z);
	
	//z = x + y;
	
	//subtraction
	__asm
	{
		mov ecx, x
		sub ecx, y
		mov z, ecx
	}
	
	printf("z = %d\n", z);
	
	//multiplication
	__asm 
	{
		mov ecx, x
		imul ecx, y
		mov z, ecx
	}
	
	printf("z = %d\n", z);
	
	return 0;
}