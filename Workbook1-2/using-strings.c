#include <stdio.h>
//contains helper functions for strings
#include <string.h>

int main(int argc, char **argv)
{
  // declare a character array for message
  char msg_1 [5] = {'H','e','l','l','o'};
  // declare a second character array for message
  char msg_2 [8] = " World!";
  //declare a third message
  char msg_3 [9] = "Goodbye!\0";
  // declare a forth message - no sizeof
  char msg_4[] = "Compiler worked out my size!";
  // declare a fifth message - use a pointer
  char *msg_5 = "Compiler worked out my size too!";
  
  // print messages/ 1st message is not null-terminated
  printf("%s\n", msg_1);
  printf("%s\n", msg_2);
  printf("%s\n", msg_3);
  printf("%s\n", msg_4);
  printf("%s\n", msg_5);
  return 0;
}