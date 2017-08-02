/*
 * Problem Description - 1. Two Sum
 * 		Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * 		You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * 		Example:
 * 			Given nums = [2, 7, 11, 15], target = 9,
 *
 * 			Because nums[0] + nums[1] = 2 + 7 = 9,
 * 			return [0, 1].
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

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target) 
{
    int i=0, j=0, sum=0;
    int *result = (int *)malloc(sizeof(int)*2);
    
    for (i=0; i<numsSize; i++)
    {
        for (j=i+1; j<numsSize; j++)
        {
            sum = nums[i] + nums[j];
            if (sum==target)
            {
                result[0]=i;
                result[1]=j;

                return (result);
            }
        }
    }
    return (result);
}

int main(void)
{
	int i=0;
	int *result=NULL;
	int test[4]={0, 4, 3, 0};
	
	printf("\nInputs: ");
	for (i=0;i<4; i++)
		printf("%d, ", test[i]);

	printf("\nOutput: ");
	result = twoSum(test, 4, 0);
	for (i=0; i<2; i++)
		printf("%d, ", result[i]);	
	printf("\n\n");

	free(result);
	return (0);
}
