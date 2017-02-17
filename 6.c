#include <stdio.h>

#define sqr(x) (x)*(x)

/**
 * The sum of the squares of the first ten natural numbers is, 
 * 1e2 + 2e2 + ... + 10e2 = 385
 *
 * The square of the sum of the first ten natural numbers is, 
 * (1 + 2 + ... + 10)e2 = 55e2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */
int main()
{
	int limit = 100 + 1;
	int square_of_sum = 0;
	int sum_of_squares = 0;

	while (limit-- > 1) {
		square_of_sum += limit;
		sum_of_squares += sqr(limit);
	}
	square_of_sum = sqr(square_of_sum);
	printf("%d\n", square_of_sum - sum_of_squares);

	return 0;
}
