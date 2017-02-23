#include <stdio.h>
#include <limits.h>

#define NUM_FACTORS 200 

int get_num_factors(long total);

/**
 * The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * Let us list the factors of the first seven triangle numbers:
 *    1: 1
 *    3: 1,3
 *    6: 1,2,3,6
 *   10: 1,2,5,10
 *   15: 1,3,5,15
 *   21: 1,3,7,21
 *   28: 1,2,4,7,14,28
 * We can see that 28 is the first triangle number to have over five divisors.
 * What is the value of the first triangle number to have over five hundred divisors?
 *
 * Brute force method works. current time 22m39.062 hahahah
*/
int main()
{
	long total = 0;
	long next = 0;
	int num_factors = 0;

	while (++next) {
		total += next;
		num_factors = get_num_factors(total);
		if (num_factors + 1 >= NUM_FACTORS)
			break;
	}

	printf("%ld has %d factors", total, NUM_FACTORS);
	
	return 1;
}

int get_num_factors(long total)
{
	long i;
	int num_factors = 0;
	static long cache[90000000];
	cache[3] = 2;
	
	if (total == 1)
		return 1;
	else if (cache[total] != 0)
		return cache[total];

	i = total / 2 + 1;
	while (--i >= 1)
		if (total % i == 0)
			num_factors++;

	// printf("num factors for %ld is %d\n", total, num_factors);
	cache[total] = num_factors;
	
	return num_factors;
}
