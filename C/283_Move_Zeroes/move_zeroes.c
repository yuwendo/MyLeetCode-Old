/*
 * Problem Description - 283. Move Zeroes 
 * 		Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * 	 	For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 *		Note:
 * 	    	You must do this in-place without making a copy of the array.
 * 	        Minimize the total number of operations.
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIZE 5


void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}


void moveZeroes(int* nums, int numsSize) 
{
	int i=0, j=0;

	for (i=0; i<numsSize; i++)
	{
		if (nums[i]==0)				
		{
			for (j=i+1; j<numsSize; j++) // exchange with the first number that is not zero
			{
				if (nums[j] != 0)
				{
					swap(&nums[i], &nums[j]);
					break;
				}
			}
		}
	}
}

int main(void)
{
	int nums[NUM_SIZE]={0, 0, 0, 0, 1};
	int i=0;

	srand(time(NULL));

	printf("\nInput : ");
	for (i=0; i<NUM_SIZE; i++)
	{
		nums[i] = rand()%10;
		printf("%d, ", nums[i]);
	}	
	printf("\n");

	moveZeroes(nums, NUM_SIZE);
	printf("output: ");
	for(i=0;i<NUM_SIZE;i++)
		printf("%d, ", nums[i]);
	printf("\n\n");

	return (0);
}
