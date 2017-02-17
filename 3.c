#include <stdio.h>
#include "primes.h"

/**
 * The prime factors of 13195 are 5,  7,  13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */
int main()
{
	int is_prime(int num);

	long int orig = 600851475143;
	long int check_limit = sqrt(orig); // only check up to sqrt of check_limit
	int current = 2; // first prime
	int max = current;
	
	while (++current < check_limit){
		if (is_prime(current) && orig % current == 0) {
			max = current;
			/**
			 * orig = A (current) * B (orig / current)
			 * since A is now lowest prime factor highest prime factor of orig will be highest prime factor of B 
			*/
			orig = orig / current; 
		}
	}
	printf("%d\n", max);

	return 0;
}
