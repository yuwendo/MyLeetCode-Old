/*
 * Problem Description - 20. Valid Parentheses
 * 		Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * 		determine if the input string is valid.
 * 		
 * 		The brackets must close in the correct order, 
 * 		"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //C99
#include <string.h>

bool isValid(char* s) 
{   
	int len=strlen(s);
	int i=0, count=0;
	char ch, parentheses[len];

	if (len < 2)
		return (false);

	printf("length:%d\n\n", len);
	for (i=0; i<len; i++)
	{
		ch = s[i];
		//printf("Count:%d, parentheses[count]= %c, ch= %c\n", count, parentheses[count], ch);

		/* compare the right side when get the left side parentheses */
		if (ch==')' && count>0)
		{
			if (parentheses[count-1]=='(')
				parentheses[--count]='\0';
			else
				return (false);
		}
		else if (ch=='}' && count>0)
		{
			if (parentheses[count-1]=='{')
				parentheses[--count]='\0';
			else
				return (false);
		}
		else if (ch==']' && count>0)
		{
			if (parentheses[count-1]=='[')
				parentheses[--count]='\0';
			else
				return (false);
		}
		else  /* store the first parenthese and rest of the left parentheses */
			parentheses[count++]=ch;

		//printf("after, Count:%d, parentheses[count]= %c, ch= %c\n", count, parentheses[count-1], ch);
		if (count > (len/2))
			return (false);
	}
	
	if (count > 0)
		return (false);

	return (true);
}

int main(void)
{
	char teststr[]="[()(])";

	printf("\nTest String: %s\n", teststr);
	printf("Is Valid: %s\n\n", (isValid(teststr) ? "YES" : "NO"));

	return (0);
}
