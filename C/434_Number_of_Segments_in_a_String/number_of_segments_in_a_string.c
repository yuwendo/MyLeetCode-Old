/*
 * Problem Description - 434. Number of Segments in a String
 * 		1.	Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
 *
 * 		2.	Please note that the string does not contain any non-printable characters.
 *
 * 		3.	Example:
 * 				Input: "Hello, my name is John"
 * 				Output: 5
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

int countSegments(char* s) 
{
	int flag=0, i=0, len=strlen(s);
	int counts=0;
	char ch=0;

	if (s==NULL || len==0)
		return (0);

	while (i<len)
	{
		ch = s[i];
		if (ch <32 && ch >=0)
			return (0);
		else if (ch != 32)
			flag=1;
		
		if (flag==1 && (ch==32 || i==(len-1)))
		{
			counts++;
			flag=0;
		}
		i++;
	}   

	return counts;
}


int main(void)
{
	char teststr[]="   ";
	int len=0;


	printf("\nInput  : %s\n", teststr);
	printf("length : %d\n", strlen(teststr));
	printf("Results: %d\n", countSegments(teststr));

	return (0);
}
