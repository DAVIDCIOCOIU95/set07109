#include <stdio.h>

int main(int argc, char **argv)
{
	char *message = "Hello World!\n";
	
	__asm
	{
		//first we are push the message into the stack 
		push message
		//then we can call the print function
		call printf
		call printf
		call printf
		push 10
		push 10
		push 10
		push 10
		push 10
		push 10
		push 10
		//last we clear the stack by popping the valies into the ebx register
		pop ebx
	}//end asm
	
	return 0;
}//end main
