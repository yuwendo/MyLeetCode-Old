/*
 * Problem Description - 278. First Bad Version
 * 		 You are a product manager and currently leading a team to develop a new product. 
 * 		 Unfortunately, the latest version of your product fails the quality check. 
 * 		 Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 *
 * 		 Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
 * 		 which causes all the following ones to be bad.
 *
 * 		 You are given an API bool isBadVersion(version) which will return whether version is bad. 
 * 		 Implement a function to find the first bad version. You should minimize the number of calls to the API. 
 *
 * Reference - 
 *
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BASE_VERSION_SIZE 100

int api_times=0;
int bad_version=0;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
	api_times++;
	if (version >= bad_version)
		return (true);
	return (false);
}

int firstBadVersion(int n) 
{
    int min=1, max=n;

    while (min < max)
    {
        int mid = min + (max-min)/2;
        if (isBadVersion(mid))
            max = mid;
        else
            min = mid + 1;
        
    }
    return (min);
}

int main(void)
{
	int test_version=0;

	srand(time(NULL));
	bad_version = rand() % BASE_VERSION_SIZE + 1;
	test_version = bad_version + (rand() % bad_version);

	printf("\nHere's the information for the product\n");
	printf("Total versions: %d\n", test_version);
	printf("Default first bad version: %d\n", bad_version);
	printf("Test    first bad version: %d\n", firstBadVersion(test_version));
	printf("api call times: %d\n", api_times);

	return (0);
}
