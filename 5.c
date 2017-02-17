#include <stdio.h>

/**
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
int main()
{
	int limit = 20;
	int i, x;
	int size = 0;
	int current = 0;
	int to_check[limit];
	to_check[0] = '\0';
	
	// this is a bad way to find highest common factors of limit
	for (i = limit - 1; i > 1; i--) {
	  for (x = 0; to_check[x] != '\0'; x++)		
			if (to_check[x] % i == 0) // higher factor exists
				break;
	  if (to_check[x] == '\0') { // reached end
			printf("adding %d\n", i);
			to_check[x] = i;
			to_check[x+1] = '\0';
			size++;
		}
	}

	while (++current) {
		for (i = 0; i < size; i++)
			if (current % to_check[i] != 0)
				break;
		if (i == size)
			break;
	}

	printf("%d\n", current);
}
