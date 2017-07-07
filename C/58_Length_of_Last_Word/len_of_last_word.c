/*
 * Problem Description - 58. Length of Last Word 
 * 		Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
 * 		return the length of last word in the string.
 *
 * 		If the last word does not exist, return 0.
 *
 * 		Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * 		For example,
 * 			Given s = "Hello World",
 * 			return 5. 
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

int lengthOfLastWord(char* s) 
{
	int len=strlen(s);
	int i=0, count=0;
	char tmp;

	if (s==NULL || len==0)
		return (0);

	/* remove blank at tail */
	for (i=len-1; i>=0; i--)
	{
		tmp = s[i];
		if (tmp!=' ')
			break;
	}
	len = i;

	/* count characters until the first blank */
	for (i=len; i>=0; i--)
	{
		tmp = s[i];
		if (tmp==' ')	
			break;
		count++;
	}
	
	return (count);
}

int main(void)
{
	char teststr[]="hello world  ";

	printf("\nTest String: %s\n", teststr);
	printf("Last Length: %d\n", lengthOfLastWord(teststr));


	return (0);
}
