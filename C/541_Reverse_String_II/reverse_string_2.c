/*
 * Problem Description - 541. Reverse String II 
 * 	Given a string and an integer k, 
 *		you need to reverse the first k characters for every 2k characters counting from the start of the string. 
 *		If there are less than k characters left, reverse all of them. 
 *		If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
 *
 *		Example:
 *			Input: s = "abcdefg", k = 2
 *			Output: "bacdfeg"
 *	
 *		Restrictions:
 *			1. The string consists of lower English letters only.
 *			2. Length of the given string and k will in the range [1, 10000]
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

void swap(char *x, char *y)
{
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int isLowerLetters(char *str)
{
	int i=0, len=strlen(str);
	char tmp;

	for (i=0; i<len; i++)
	{
		tmp = str[i];
		if (tmp<'a' || tmp>'z')
			return (0);
	
	}

	return (1);
}

char* reverseStr(char* s, int k) 
{
	int len=strlen(s);
	int i=0, j=0;
	
	if (k<1 && k>10000)
		return (0);
	else if (s == NULL)
		return ('\0');
	
	if (isLowerLetters(s) == 0)
		return (s);

	if (len <= k)
	{
		for(i=0, j=(len-1); i<j; i++, j--)
			swap(&s[i], &s[j]);
	}
	else if (len > k && len <=(2*k))
	{
		for(i=0, j=(k-1); i<j; i++, j--)
			swap(&s[i], &s[j]);
	}
	else if (len > (2*k))
	{
		for(i=0; i<len; i++)
		{
			if ((i%(2*k))==0)
			{
				int l = (i+k-1);
				if (l >= len)
					l = len - 1;
				for (j=i; j<l && l<len; j++, l-- )
				{
					swap(&s[j], &s[l]);
				}
			}
		}
	
	}

	return (s);
}


int main(void)
{
	int k=2, i=0;
	char teststr[]="uxzpsogzkwgwacxxvvzlhkaahjaqagdfjkmyutvhxclzskvxckjvfgzptlzldjwhrpocfugzqkpaxexezbvggtkoxriysqivupofrcoxbrdgccvphvdtvrjts";
	char expect[]="khlzvvxxcawgwkzgospzxuaahjaqagdfjkmyutvhxclzprhwjdlzltpzgfvjkcxvksocfugzqkpaxexezbvggtkoccgdrbxocrfopuviqsyirxvphvdtvrjts";
	char *result=NULL;
	int len = strlen(teststr);

	printf("\nInput k, len(%d): ", len);
	scanf("%d", &k);

	printf("\n\nOrigin Information: \n");
	printf("K is %d\n", k);
	printf("Test  str: %s\n", teststr);
	printf("ChechStr : ");
	for (i=0; i<strlen(teststr); i++)
	{
		if (i%(2*k) == 0)
		{
			int j=0;
			for (j=0; j<k && (j+i)<strlen(teststr); j++)
				printf("-");

			i = i+j;
		}
		printf(" ");
	}

	result = reverseStr(teststr, k);
	printf("\nResultStr: %s\n", result);
	printf("\nExpectStr: %s\n", expect);

	return (0);
}
