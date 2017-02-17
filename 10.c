#include <stdio.h>
#include "primes.h"

/**
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */
int main()
{
	int is_prime(int num);

	long limit = 2000000;
	int current = 0;
	long total = 0;

	while (++current < limit)
		if (is_prime(current))
			total += current;

	printf("%ld\n", total);
}
