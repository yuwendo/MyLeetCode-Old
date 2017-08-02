/*
 * Problem Description - 7. Reverse Integer
 * 	Reverse digits of an integer.
 *
 * 	Example1: x = 123, return 321
 * 	Example2: x = -123, return -321
 *
 *	
 *	Have you thought about this?
 *		Here are some good questions to ask before coding. 
 *		Bonus points for you if you have already thought through this!
 *		If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 *		Did you notice that the reversed integer might overflow? 
 *		Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 *		For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *
 * 	Note:
 * 			The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows. 
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GET_NUMBER_SIZE 1000

int reverse(int x) 
{
	int result=0, tmp=0;

	if (x>=(2147483647) || x<(-2147483647)) // check the input is overflow or not.
		return (0);							// 2^32/2 for signed and un-signed integer.

	while (x!=0)
	{
		tmp = x % 10;
		result = result * 10 + tmp;
		x = x / 10;
		//printf("tmp: %d, result:%d, x:%d\n", tmp, result, x);
		if (((result>214748364) || (result<(-214748364))) && (x!=0)) // check next digit cause overflow or not.
			return (0);
	}

	return (result);  
}

int main(void)
{
	int test_num=1000000003;

	srand(time(NULL));
	//test_num = rand()%GET_NUMBER_SIZE;

	printf("\nInput : %d\n", test_num);
	printf("Output: %d\n\n", reverse(test_num));

	return (0);
}
