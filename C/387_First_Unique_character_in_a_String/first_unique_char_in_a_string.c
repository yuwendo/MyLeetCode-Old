/*
 * Problem Description - 387. First Unique Character in a String 
 * 		 1.	Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 *
 * 		 2.	Examples:
 * 		 		s = "leetcode"
 * 		 		return 0.
 *
 * 				s = "loveleetcode",
 * 		 		return 2.
 *
 * 		 Note: You may assume the string contain only lowercase letters. 
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int firstUniqChar(char* s) 
{
	int len=strlen(s);
	int i=0, j=0, flag=0;
	char ch1=0, ch2=0;

	if (s==NULL || len<=0)
		return (-1);
	
	if (len == 1)
   		return (0);
 
	flag=0;
	for (i=0; i<len; i++)
	{
		ch1= s[i];
		flag=0;
		for (j=0; j<len; j++)
		{
			if (j==i)
				j++;

			ch2 = s[j];
			if (ch1 == ch2)
			{
				flag=1;
				break;
			}
		}

		if (flag == 0)
			return (i);
	}

	return (-1);
}

int main(void)
{
	char teststr[]="leetcode";

	printf("\nInput: %s\n", teststr);
	printf("the first non-repeating index is : %d\n", firstUniqChar(teststr));

	return (0);
}
