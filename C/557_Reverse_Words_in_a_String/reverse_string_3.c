/*
 * Problem Description - 557. Reverse Words in a String III
 * 		Given a string, you need to reverse the order of characters in each word within a sentence 
 * 		while still preserving whitespace and initial word order.
 *
 * 		Example 1:
 * 			Input: "Let's take LeetCode contest"
 * 			Output: "s'teL ekat edoCteeL tsetnoc"
 *
 * 		Note: In the string, each word is separated by single space and there will not be any extra space in the string. 
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

void string_swap(char *s, int start, int end)
{
	int i=0, j=0;
	char tmp;

	//printf("%s, s:%s\n", __func__, s);
	for(i=start, j=end-1; i<j; i++, j--)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	//printf("%s, s:%s\n", __func__, s);
}

char* reverseWords(char* s) 
{
	int i=0, space=0, len=strlen(s);
	int start=0, end=0;
	char ch;

	if (s==NULL || len==0)
		return ("");

	space=1;
	i=0;
	while (i<=len)
	{
		ch = s[i];
		//printf("%d - ch:%c, %d\n", i, ch, ch);
		if (space==1 && (ch!=32 || ch!='\0'))
		{
			space=0;
			start = i;
		}	
		else if (ch==32 || i==len)
		{
			if (space==0)
			{
				end = i;
				string_swap(s, start, end);
			}
			space=1;
		}
		i++;
	}

	return (s);
}

int main(void)
{
	char input[]="Let's take LeetCode contest";

	printf("\n");
	printf("Input : %s\n", input);
	printf("Output: %s\n\n", reverseWords(input));

	return (0);
}
