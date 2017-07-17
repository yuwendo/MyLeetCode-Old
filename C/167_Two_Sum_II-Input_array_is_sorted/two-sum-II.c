/*
 * Problem Description - 167. Two Sum II - Input array is sorted
 * 		Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 *
 * 		The function twoSum should return indices of the two numbers such that they add up to the target, 
 * 		where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * 		You may assume that each input would have exactly one solution and you may not use the same element twice.
 *
 * 		Input: numbers={2, 7, 11, 15}, target=9
 * 		Output: index1=1, index2=2 
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS_TEST 4

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
	int i=0, j=0, sum=0;
	static result[2];

	/* initialize */
	*returnSize = 2;
	for(i=0; i<2; i++)
		result[i]=0;

	for (i=0; i<numbersSize;i++)
	{
		//printf("i:%d, num:%d\n", i, numbers[i]);
		for (j=i+1; j<numbersSize; j++)
		{
			sum = numbers[i] + numbers[j];
			//printf("target:%d, sum:%d\n", target, sum);
			if (sum==target)
			{
				result[0]=i+1;
				result[1]=j+1;
				return (&result[0]);
			}
		}
	}

	return (&result[0]);
}

int main(void)
{
	int target=-1, nums[MAX_NUMS_TEST]={-1, 0, 1, 2};
	int i=0;
	int *result, returnSize=0;

	printf("\n\nInput: ");
	for (i=0; i<MAX_NUMS_TEST; i++)
		printf("%d, ", nums[i]);

	printf("\nTarget: %d\n", target);
	printf("==================================\n");

	result = twoSum(&nums[0], MAX_NUMS_TEST, target, &returnSize);
	printf("Output: ");
	for (i=0; i<returnSize; i++)
		printf("%d, ", result[i]);
	printf("\n\n");

	return (0);
}
