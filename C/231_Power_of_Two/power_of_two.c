/*
 * Problem Description - 231. Power of Two 
 * 		Given an integer, write a function to determine if it is a power of two. 
 *
 * Reference - 
 *
 *
 * Notification - 
 *	Need to include the "stdbool.h" for using bool.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // defined after C99 for using bool 
#include <time.h>

#define TEST_TIMES 5


bool isPowerOfTwo(int n) 
{
	if (n==1)
		return (true);
	if (n==0)
		return (false);

	while (n!=1) 
 	{
		if (n%2==0)
		{
			if (n/2==1)
				return (true);
			n = n / 2;
		}else
			return (false);
	}

	return (false);
}

int main(void)
{
	int i=0, num=0;
	
	srand(time(NULL));
	printf("\n");
	for (i=0; i<TEST_TIMES; i++)
	{
		num = rand()%129;
		printf("Test - %-2d, num: %-4d, result: %-s\n", 
				i+1, num, (isPowerOfTwo(num)) ? "TRUE" : "FALSE" );
	}
	printf("\n\n");

	return (0);
}
