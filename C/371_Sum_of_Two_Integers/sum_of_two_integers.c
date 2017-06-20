/*
 * Problem Description - 371. Sum of Two Integers
 * 		Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 * 		Example:
 * 			Given a = 1 and b = 2, return 3. 
 *
 * Reference - 
 *		https://skyyen999.gitbooks.io/-leetcode-with-javascript/content/questions/371md.html 
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_TIMES 3

int getSum(int a, int b) 
{
	int tmp=0;

	if (a==0 || b==0)
		return (a|b);

	while (b!=0)
	{
		tmp = a & b;	
		a = a ^ b;
		b = tmp << 1;
	}

	return (a);
}

int main(void)
{
	int i=0, a=0, b=0;

	srand(time(NULL));
	printf("\n");
	for	(i=0;i<TEST_TIMES; i++)
	{
		a = rand()%21;
		b = rand()%21;
		printf("TEST-%d, %d + %d = %d\n", i, a, b, getSum(a,b));
	}
	printf("\n");

	return (0);
}
