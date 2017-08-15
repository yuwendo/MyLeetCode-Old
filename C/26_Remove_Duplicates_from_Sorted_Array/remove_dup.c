/*
 * Problem Description - 26. Remove Duplicates from Sorted Array
 * 		 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * 		 Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * 		 For example,
 * 			Given input array nums = [1,1,2],
 * 		 	Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
 * 		 	It doesn't matter what you leave beyond the new length. 
 *
 * Reference - 
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#define NUM_SIZE 3

int removeDuplicates(int* nums, int numsSize) 
{
	int i=0, j=0, now=0, tmp=0;

	if (nums==NULL)
		return (numsSize);

	now=nums[0];
	for (i=1; i<numsSize; i++)
	{
		tmp = nums[i];
		if (tmp == now)	
		{
			for(j=i; j<numsSize-1; j++)
				nums[j] = nums[j+1];
			numsSize--;
			i = i-1;
		}
		else
			now = tmp;
	}

	return (numsSize);    
}

int main(void)
{
	int testnum[NUM_SIZE]={1, 1, 2};
	int i=0, nums=0;

	printf("\nInput : ");
	for (i=0; i<NUM_SIZE; i++)
		printf("%d, ", testnum[i]);

	printf("\nOutput: ");
	nums = removeDuplicates(testnum, NUM_SIZE);
	for (i=0; i<nums; i++)
		printf("%d, ", testnum[i]);

	printf("\n\n");

	return (0);
}
