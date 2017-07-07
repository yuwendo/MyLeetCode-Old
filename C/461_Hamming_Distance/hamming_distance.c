/*
 * Problem Description - 461. Hamming Distance
 * 		The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *
 * 		Given two integers x and y, calculate the Hamming distance.
 * 		Note:
 * 			0 ≤ x, y < 231.
 *
 * 		Example:
 * 			Input: x = 1, y = 4
 * 			Output: 2
 *
 * 		Explanation:
 * 			1   (0 0 0 1)
 * 			4   (0 1 0 0)
 * 		    	   ↑   ↑
 *
 * 		The above arrows point to positions where the corresponding bits are different.
 *
 * Reference - 
 *		https://en.wikipedia.org/wiki/Hamming_distance
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hammingDistance(int x, int y) 
{
    int dist = 0;
    unsigned  val = x ^ y;

	/* Count the number of bits set */
	while (val!=0)
	{
		/* A bit is set, so increment the count and clear the bit */
		dist++;
		val&=val-1;
	}

	// Return the number of differing bits
	return dist;    
}

int main(void)
{
	int num1=0, num2=0;

	srand(time(NULL));
	num1 = rand()%10+1;
	num2 = rand()%10+1;

	printf("\nInput num1: %d, num2: %d\n", num1, num2);
	printf("The hamming distance is %d.\n\n", hammingDistance(num1, num2));

	return (0);
}
