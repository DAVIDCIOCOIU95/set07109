#include<stdio.h>

void main()
{
     int rows,starNo,spaceNo;
     printf("Enter Rows:\n");
     scanf("%d",&rows);
  
      for(int i=1;i<=rows;i++)
     {
         starNo=i*2-1;
         spaceNo=i+rows-starNo;
         for(int j=0;j<spaceNo;j++)
         {
             printf("%c",' ');
         }
         for(int k=0;k<starNo;k++)
         {
             printf("%c",'*');
        }
         printf("\n");
     }
 
     for(int l=0;l<3;l++)
     {
         for(int m=0;m<(rows*2+1)/2;m++)
         {
             printf("%c",' ');
         }
         printf("%c\n",'*');
     }
 }