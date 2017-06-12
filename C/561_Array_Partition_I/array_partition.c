/*
 * Problem Description - 561. Array Partition I 
 * 		1.	Given an array of 2n integers, your task is to group these integers into n pairs of integer, 
 * 			say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 *
 *		2.	Example 1:
 *				Input: [1,4,3,2]
 *				Output: 4
 *				
 *				Explanation: n is 2, and the maximum sum of pairs is 4.
 *		Note:
 *			n is a positive integer, which is in the range of [1, 10000].
 *			All the integers in the array will be in the range of [-10000, 10000].
 *
 * Reference - 
 *		1.	quick sort - https://openhome.cc/Gossip/AlgorithmGossip/QuickSort3.htm 
 *
 * Notification - 
 * 		the example above - sum = min(1, 2) + min(3, 4) = 4
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 4
#define	MAX	10000
#define MIN

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void selection_sort(int *nums, int numsSize)
{
	int i=0, j=0;
	int num1=0, num2=0;
    
	for (i=0; i<numsSize; i++)
	{
		for (j=i+1; j<numsSize; j++)
		{
			num1 = nums[i];
			num2 = nums[j];
			if (num1 > num2)
				swap(&nums[i], &nums[j]);
		}
	}
}

int partition(int *nums, int left, int right)
{
	int i = left - 1;
	int j=0;
	int num1=0, num2=0;

	for (j = left; j<right; j++)
	{
		num1 = nums[right];
		num2 = nums[j];
		if (num2 <= num1)
		{
			i++;
			swap(&nums[i], &nums[j]);
		}
	}

	swap(&nums[i+1], &nums[right]);

	return (i+1);
}

void quick_sort(int *nums, int left, int right)
{
	int mid=0;

	if(left < right)
	{
		mid = partition(nums, left, right);
		quick_sort(nums, left, mid-1);
		quick_sort(nums, mid+1, right);
	} 
}

int arrayPairSum(int* nums, int numsSize) 
{
	int i=0, sum=0;	

	quick_sort(nums, 0, numsSize-1);
	printf("\n\nNumbers: [");
	for (i=0; i<numsSize; i++)
		printf(" %2d,", nums[i]);
	printf("]\n\n");

	for (i=0; i<numsSize; i+=2)
		sum = sum + nums[i];

	return (sum);
}

int main(void)
{
	int i=0;
	int nums[MAX_NUMBERS];

	srand(time(NULL));
	printf("\nInput: [");
	for (i=0; i<MAX_NUMBERS; i++)
	{
		nums[i] = rand()%10 + 1;
		printf(" %2d,", nums[i]);
	}
	printf("]\n");

	printf("output: %d\n", arrayPairSum(nums, MAX_NUMBERS));

	return (0);
}
