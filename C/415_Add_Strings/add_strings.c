/*
 * Problem Description - 415. Add Strings
 *		Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 *
 *		Note:
 *		    The length of both num1 and num2 is < 5100.
 *		    Both num1 and num2 contains only digits 0-9.
 *		    Both num1 and num2 does not contain any leading zero.
 *		    You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *
 * Reference - 
 *
 *
 * Notification - 
 *		using static must be carefully for initialize
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_LEN 7

int get_nums(char num)
{
	return ((num<48 || num>57) ? (0) : (num-48));
}

char* addStrings(char* num1, char* num2) 
{
	int i=0, j=0, k=0, carry=0, n1, n2;
	int len=0, len1=strlen(num1), len2=strlen(num2);
	static char sum[5100];

	for (i=0; i<5100; i++)
		sum[i]=0;

	carry = 0;
	len = (len1>len2) ? len1 : len2;
	for (i=len1-1, j=len2-1, k=len; i>=0 || j>=0 || k>=0; i--, j--, k--)
	{
		char tmp;
		n1 = (i>=0) ? get_nums(num1[i]) : 0;
		n2 = (j>=0) ? get_nums(num2[j]) : 0;
		sum[k]=((n1+n2+carry)%10+48);
		carry=((n1+n2+carry)/10);
	}

	if (sum[0]=='0')
	{
		for (i=0; i<strlen(sum); i++)
		{
			sum[i] = sum[i+1];
			if (i==strlen(sum)-1)
				sum[i]='\0';
		}
	}

	return (sum);   
}

int main(void)
{
	char num1[NUM_LEN]="408", num2[NUM_LEN]="5";
	int i=0, len1=0, len2=0;

	srand(time(NULL));
	len1 = rand() % NUM_LEN + 1;
	len2 = rand() % NUM_LEN + 1;
	printf("\nLen1: %d, Len2: %d\n", len1, len2);

	memset(&num1, 0, NUM_LEN);
	memset(&num2, 0, NUM_LEN);	
	/* get numbers for num1 */
	for (i=0; i<len1; i++)
	{
		int tmp=0;
		tmp = rand()%10+48;
		if (i==0 && tmp==48)
			i--;
		else
			num1[i] = tmp;
	}	
	num1[i]='\0';
	/* get numbers for num2 */
	for (i=0; i<len2; i++)
	{
		int tmp=0;
		tmp = rand()%10+48;
		if (i==0 && tmp==48)
			i--;
		else
			num2[i] = tmp;
	}
	num2[i]='\0';

	printf("\nInput BIG Numbers: \n");
	printf("num1: %10s\n", num1);
	printf("num2: %10s\n", num2);
	printf("=========================\n");
	printf("Result:  %7s\n\n", addStrings(num1, num2));

	return (0);
}
