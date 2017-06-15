/*
 * Problem Description - 326. Power of Three
 * 		 Given an integer, write a function to determine if it is a power of three.
 *
 * 		 Follow up:
 * 		 Could you do it without using any loop / recursion? 
 *
 * Reference - 
 *		getting log value - https://helloacm.com/cc-coding-exercise-power-of-three-leetcode/ 
 *
 * Notification - 
 * 		Need to include the "stdbool.h" for using bool.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define TEST_TIMES 5

bool isPowerOfThree(int n) 
{
	int power;
	int ans;

	if (n==1)
		return (true);

	if (n==0 || n%3!=0)
		return (false);

	power = abs(ceil(log(n)/log(3)));
	ans = (int)(pow(3.00, power));
	//printf("\npower:%d, result:%d, n:%d\n", power, ans, n);
	if (n==ans)
		return (true);
	else
		return (false);
		
	return (false);
}


int main(void)
{
	int i=0, num[TEST_TIMES]={9, 81, 243, 729, 2187};
	
	srand(time(NULL));
	printf("\n");
	for (i=0; i<TEST_TIMES; i++)
	{
		num[i] = rand()%244;
		printf("Test - %-2d, num: %-4d, result: %-s\n", 
				i+1, num[i], (isPowerOfThree(num[i])) ? "TRUE" : "FALSE" );
	}
	printf("\n\n");

	return (0);
}
