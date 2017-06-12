/*
 * Problem Description - 520. Detect Capital 
 * 		Given a word, you need to judge whether the usage of capitals in it is right or not.
 * 		We define the usage of capitals in a word to be right when one of the following cases holds:
 *
 * 		All letters in this word are capitals, like "USA".
 * 		All letters in this word are not capitals, like "leetcode".
 * 		Only the first letter in this word is capital if it has more than one letter, like "Google".
 * 		Otherwise, we define that this word doesn't use capitals in a right way.
 *      Example 1:
 * 			Input: "USA"
 * 		    Output: True
 *
 * 		Example 2:
 *			Input: "FlaG"
 * 		    Output: False
 *
 * 		Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters. 
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // defined after C99 for using bool 
#include <string.h>

bool detectCapitalUse(char* word) 
{
	char ch;
	int i=0, count=0, len=strlen(word);

	if (word == NULL)	
 		return (false);
	
	if (len==1)
		return (true);

	for (i=0; i<len; i++)
	{
		ch = word[i];
		if (ch >= 'A' && ch <= 'Z')
		{
			if (i==0)
				count++;
			else if (count !=0)
				count++;
			else if (count==0)
				return (false); 
		}
	}

	if (count<=1 || count==len)
		return (true);
	else
		return (false);
}

int main(void)
{
	char test[]="awFawrdf";

	printf("\nInput : %s\n", test);
	printf("Output: %s\n", (detectCapitalUse(test)) ? "TRUE" : "FALSE");

	return (0);
}
