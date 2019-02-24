# include <stdio.h>
# include < stdlib.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int integerMax = INT_MAX;
	int integerMaxPlusOne = INT_MAX + 1;
	
	int integerMin = INT_MIN;
	int integerMinMinusOne =INT_MIN - 1;
	
	printf("%d\n",integerMax);
	printf("%d\n", integerMaxPlusOne);
	
    printf("%d\n",integerMin);
	printf("%d\n", integerMinMinusOne);
	
	return 0;
}
