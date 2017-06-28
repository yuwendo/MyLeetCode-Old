/*
 * Problem Description - 263. Ugly Number 
 * 		 Write a program to check whether a given number is an ugly number.
 * 		 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * 		 For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 * 		 Note that 1 is typically treated as an ugly number. 
 *
 * Reference - 
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // defined after C99 for using bool
#include <time.h>

int remove_mod_num(int num, int mod_num)
{
	while (num >= mod_num)
	{
		if (num % mod_num == 0 )
			num = num / mod_num;
		else
			return (num);
	}

	return num;	
}

bool isUgly(int num) 
{
	int i=0, flag=0;

    if (num <= 0)
		return (false);
	else if (num<=5)
		return (true);

	num = remove_mod_num(num, 2);
	printf("remove 2: %d\n", num);
	num = remove_mod_num(num, 3);
	printf("remove 3: %d\n", num);
	num = remove_mod_num(num, 5);
	printf("remove 5: %d\n", num);
	
	if (num <= 5)
		return (true);

	return (false);
}

int main(void)
{
	int num = 32;

	srand(time(NULL));
	num = rand() % 100 + 1;
	printf("\nNum: %d, Is urgly number: %s\n", 
				num, (isUgly(num) ? "YES" : "NO"));

	return (0);
}
