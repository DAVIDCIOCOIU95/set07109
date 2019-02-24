#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
char *terminator = "TERMINATOR";
char *myLine = "Lorem ipsum dolor sit amet, TERMINATOR consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna.";
char *pointerDefineStart = strstr(myLine, terminator);
printf("%s", pointerDefineStart);
char *pointerDefineEnd = pointerDefineStart + strlen(terminator);
printf("%s", pointerDefineEnd);



return 0;
}