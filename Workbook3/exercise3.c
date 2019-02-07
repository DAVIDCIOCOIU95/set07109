#include <stdio.h>

int main(int argc, char **argv)
{
	
	int x = 0;
	
	__asm
	{
		push 10
		push 3243
		push 325
		push 43
		push 543
		push 4534
		
		mov esp, ebp
		mov esp, ecx
		pop x
		
	}//end asm
	
	printf("The value of x is: %d\n", x);
	
	return 0;
}//end main
