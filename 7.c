#include <stdio.h>
#include <math.h>
#include <limits.h>

int is_prime(int num);

/**
 * By listing the first six prime numbers: 2,  3,  5,  7,  11,  and 13,  we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */
int main()
{
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

/**
 * only works if called sequentially for each number in range from 2
 */
int is_prime(int num)
{
	if (num < 2)
		return 0;

	static int primes[INT_MAX] = {'\0'};
	int target = sqrt(num);
	int i = -1;     

	while (primes[++i] != '\0' && primes[i] <= target) 
		if (num % primes[i] == 0)
			return 0;
	
	while (primes[i] != '\0') // ff to end
		i++;

	primes[i] = num;
	primes[i + 1] = '\0';

	return 1;
}
