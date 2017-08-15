/*
 * Problem Description - 88. Merge Sorted Array
 * 		Given two sorted integer arrays nums1 and nums2, 
 * 		merge nums2 into nums1 as one sorted array.
 *
 * 	Note:
 * 		You may assume that nums1 has enough space (size that is greater or equal to m + n) 
 * 		to hold additional elements from nums2. 
 * 		The number of elements initialized in nums1 and nums2 are m and n respectively.
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#define NUM1_SIZE 4
#define NUM2_SIZE 5
#define NUM1_SIZE_TOTAL ((NUM1_SIZE)+(NUM2_SIZE))

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void resort(int *num, int size)
{
	int i=0, tmp=0;

	for (i=0; i<size-1; i++)
	{
		if (num[i] > num[i+1])
			swap(&num[i], &num[i+1]);
	}
}

void merge(int* nums1, int m, int* nums2, int n) 
{
	int i=0, n2=0;
	int cmp=0, tmp=0;

	if (nums1==NULL)
	{
		nums1 = nums2;
		return;
	}
	else if (n==0 || nums2==NULL)
		return;

	cmp = nums2[0];
	for(i=0; i<m; i++)
	{
		tmp = nums1[i];
		if (cmp<tmp)
		{
			swap(&nums1[i], &nums2[0]);
			resort(nums2, n);
			cmp = nums2[0];
		}
	}

	for (i=m; i<m+n; i++)
		nums1[i] = nums2[i-m];
}

int main(void)
{
	int num2[NUM2_SIZE]={7, 11, 22, 33, 44};
	int num1[NUM1_SIZE]={1, 8, 10, 25};
	int i=0;

	printf("\nNum1: ");
	for (i=0;i<NUM1_SIZE; i++)
		printf("%d, ", num1[i]);

	printf("\nNum2: ");
	for (i=0;i<NUM2_SIZE; i++)
		printf("%d, ", num2[i]);

	printf("\n\nResult for merge to num1\n");
	printf("=================================\n");
	merge(num1, NUM1_SIZE, num2, NUM2_SIZE);
	printf("Out : ");
	for (i=0; i<NUM1_SIZE_TOTAL; i++)
		printf("%d, ", num1[i]);

	printf("\n");
	return (0);
}
