/*
 * Problem Description - 412. Fizz Buzz 
 * 		1.	Write a program that outputs the string representation of numbers from 1 to n.
 * 			But for multiples of three it should output “Fizz” instead of the number and 
 * 			for the multiples of five output “Buzz”. 
 * 			For numbers which are multiples of both three and five output “FizzBuzz”.
 *
 * 		Example:
 * 			n = 15,
 *
 *		Return:
 * 		[
 * 			"1",
 * 	        "2",
 * 	        "Fizz",
 * 	        "4",
 * 	        "Buzz",
 * 	        "Fizz",
 * 	        "7",
 * 	        "8",
 * 	        "Fizz",
 * 	        "Buzz",
 * 	        "11",
 * 	        "Fizz",
 * 	        "13",
 * 	        "14",
 * 	        "FizzBuzz"
 * 	     ]
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** fizzBuzz(int n, int* returnSize) 
{
	char **str;
	int i=0;

	if (n==0)
		return (NULL);

	str=(char **)malloc(n * sizeof(char *));	// row
	for (i=0; i<n; i++)	// size of a row
		str[i] = (char *)malloc(2*sizeof(char *));
	
	for (i=1; i<=n; i++)
	{
		if (i%3==0)
			str[i-1]=((i%5==0) ? "FizzBuzz" : "Fizz");
		else if (i%5==0)
			str[i-1]="Buzz";
		else
			sprintf(str[i-1], "%d", i);
	}

	*returnSize=n;
	return (str);
}

int main(void)
{
	int n=30, returnSize=0, i=0;
	char **str;

	str = fizzBuzz(n, &returnSize);

	printf("\nOutput:\n");
	for (i=0; i<returnSize; i++)
		printf("%s\n", str[i]);
	printf("============================\n");

	for (i=0; i<returnSize; i++)
		free(str[i]);

	printf("Free2\n");
	free(str);

	return (0);
}
