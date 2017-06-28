/*
 * Problem Description - 204. Count Primes
 * 		Count the number of prime numbers less than a non-negative number, n.
 *
 * Reference - 
 *		1.	https://skyyen999.gitbooks.io/-leetcode-with-javascript/content/questions/204md.html
 *		2.	www.csie.ntnu.edu.tw/~u91029/Prime.html
 *
 * Notification - 
 *		division until j^2 < n, j is the prime number candidates.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int countPrimes(int n) 
{
	int i=0, j=0, count=1;
	int flag=0;

	if (n<3)
		return (0);

	printf("\nPrimes: ");
	for (i=3; i<n; i+=2)
	{
		for (j=3; j*j<=i;j+=2)
		{
			if (i%j == 0)
			{ 
				flag = 1;
				break;
			}
		}
			
		if (flag == 0)
		{
			count++;
			printf("%d, ", i);
		}
		flag = 0;
	}
	printf("\n");
    
	return (count);
}

int main(void)
{
	int num=499979;

	srand(time(NULL));
	num = rand()%100 + 1;

	printf("\nNumber: %d, the number of prime numbers: %d\n", num, countPrimes(num));

	return (0);
}
