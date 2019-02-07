#include <stdio.h>

int sub(int x, int y)
{
	return x - y;
}

int main(int argc, int **argv)
{
	int result = 0;
	
	__asm
	{
		push 500
		push 200
		call sub
		mov result, eax
		//we clean 200 and 500 as the result is stored into the result variable 
		pop ebx
		pop ebx 
	}
	
	printf("result = %d\n", result);
	return 0;
}