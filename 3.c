#include <stdio.h>
#include <limits.h>
#include <math.h>

int is_prime(int num);

/**
 * The prime factors of 13195 are 5,  7,  13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */
int main()
{
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

/**
 * only works if called sequentially for each number in range
 * from zero
 */
int is_prime(int num)
{
	static int primes[INT_MAX] = {'\0'};
	int target = sqrt(num);
	int i = -1;	

	while (primes[++i] != '\0' && primes[i] < target) 
		if (num % primes[i] == 0)
			return 0;
	
	primes[i] = num;
	primes[i + 1] = '\0';

	return 1;
}
