#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//get the length of the grades for numberGrades

double avarageGrade(int gradeSum, int counter)
{
	return gradeSum / counter;
}


int main(int argc, char **argv)
{
  char buffer [50];
  char name [30];
  
  int flag = 1;
  int counter = 0;
  int gradeSum = 0;
  
  
  
  //insert name
  printf("Insert your name: ");
  fgets(name, 30, stdin);
  
  
  while (flag != 0)
	  
	  { 
        //prompt for the grade
        printf("Insert your grade here or enter zero to get the avarage grades.\nGrade: ");
		
        //get the grade
        fgets(buffer, 50, stdin);
	
       //convert to int 
        int grade = atoi(buffer);
		
		//sum the grades
		gradeSum = gradeSum + grade;
	
		//end while loop if grade equals to 0 and give the result
		if(grade == 0) 
		{
			
			
			// couunter check
			//printf("counter: %d", counter);
			
			//set the flag to 0 to exit the while loop
			flag = 0; 
		}
		
		//increment counter (number of grades entered)
		++counter; 
  
	  } //end while
	  
	  //get the result
			double result = avarageGrade(gradeSum, counter); 
			printf("%s , your avarage grade is: %.2f", name, result);
 	
}//end main
