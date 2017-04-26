/* 
 * Problem Description - 476 number complement
 * 	Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 * 	Note:
 * 	    The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * 	    You could assume no leading zero bit in the integer’s binary representation.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findComplement(int num) 
{
	int num_comp[32]={0};
	int i=0, count=0, tmp=0;

	printf("\n==================================\n");
	printf("Num:%d\n", num);
	for (i=0; i<32; i++)
	{
		num_comp[i] = ((num % 2)==1) ? 0 : 1;
		num = num / 2;
		if (num == 1)
		{
			num_comp[i+1] = 0;
			count = i + 2;
			break;
		}
	}
	
	for (i=0; i<count; i++)
	{
		tmp = tmp + (num_comp[i] * (int)(pow(2, i)));
		printf("\ni:%d, tmp:%d, com:%d", i, tmp, num_comp[i]);
	}
    return tmp;
}

int main(void)
{
	int input=0, output=0;

	printf("Input the number: ");
	scanf("%d", &input);

	output = findComplement(input);
	printf("\n===========================================\n");
	printf("Input : %d, 0x%x\n", input, input);
	printf("Output: %d, 0x%x\n", output, output);

	return 0;
}

