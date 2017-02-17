#include <stdio.h>
#include "primes.h"

/**
 * By listing the first six prime numbers: 2,  3,  5,  7,  11,  and 13,  we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */
int main()
{
	int is_prime(int num);

	int current = 1;
	int target = 10001;
	int prime_count = 0;

	while (prime_count < target && current++) 
		if (is_prime(current)) {
			prime_count++;
		}
	printf("%d\n", current);
	
	return 0;
}

