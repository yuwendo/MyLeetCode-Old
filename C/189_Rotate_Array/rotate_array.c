/*
 * Problem Description - 189. Rotate Array
 * 		Rotate an array of n elements to the right by k steps.
 *
 * 		For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * 		Note:
 * 			Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
 *
 * 		Hint:
 * 			Could you do it in-place with O(1) extra space?
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
#define MAX_TEST_NUMS	3


void rotate(int* nums, int numsSize, int k) 
{
	int i=0, j=0, flag=0;
	int num[numsSize];

	if (numsSize <=0 || k<0)
		return;

	while (numsSize < k)
		k = k - numsSize;

	for (i=numsSize-k, j=0; i<numsSize; i++, j++)
		num[j] = nums[i];	
	
	for (i=0;j<numsSize; j++, i++)
		num[j] = nums[i];

	//printf("\nTest: ");
	for (i=0; i<numsSize; i++)
	{
	//	printf("%d, ", num[i]);
		nums[i] = num[i];
	}
	//printf("\n");
}

int main(void)
{
	int nums[MAX_TEST_NUMS]={1, 2, 3}, steps=5, i=0;	

	srand(time(NULL));

	//steps=rand()%5 + 1;
	printf("\n%d elements, %d steps\n", MAX_TEST_NUMS, steps);
	printf("Input  nums: ");
	for (i=0; i<MAX_TEST_NUMS; i++)
	{
	//	nums[i] = rand()%10 + 1;
		printf("%d, ", nums[i]);
	}

	printf("\nOutput nums: ");
	rotate(nums, MAX_TEST_NUMS, steps);
	for (i=0; i<MAX_TEST_NUMS; i++)
		printf("%d, ", nums[i]);
	
	printf("\n\n");
	return (0);
}
