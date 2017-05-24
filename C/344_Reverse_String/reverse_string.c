/* 
 * Problem Description - 344 Reverse String
 * 		Write a function that takes a string as input and returns the string reversed.
 * 		Example:
 * 			Given s = "hello", return "olleh". 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString_2(char* s) 
{
	int len=strlen(s), i=0, j=0;
	char *tmp=NULL;
	
	if (s==NULL)
		return ("\0");

	j=len-1;
	tmp=(char *)malloc(sizeof(s));
	for(i=0; j>=0; i++, j--)
	{
		tmp[i] = s[j];
	}

	return (tmp);
}

char* reverseString_1(char* s)
{
    int len=strlen(s), i=0, j=0;
    char tmp;

    if (s==NULL || len==0)
        return ("\0");

    j=len-1;
    for(i=0; i<j; i++, j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }

    return (s);
}

int main(void)
{
	char teststr[]="hello";
	char *result=reverseString_2(teststr);

	printf("\nTest string: %s\n", teststr);
	printf("Result string: %s\n", reverseString_1(teststr));
	printf("Result string: %s\n", result);

	free(result);
	return (0);
}
