/*header for the search function into an array
it takes 3 parameters:
-value being searched for
-size of the array being searched
-the array being searched (represented by a pointer to the memory location, using *)
*/

//first we avoid repeating the header once passed into the other files
#pragma once 

//we are including only the declaration and not the definition
//this makes easier further definitions
int search(int value, int size, int *data);
