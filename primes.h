#include <limits.h>
#include <math.h>

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
