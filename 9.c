#include <stdio.h>

#define square(x) (x) * (x)
#define sum(a, b, c) (a) + (b) + (c)

/**
 * A Pythagorean triplet is a set of three natural numbers,  a < b < c,  for which  ae2 + be2 = ce2
 *
 * For example: 3e2 + 4e2 = 5e2 (9  + 16  = 25)
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */
int main()
{
	int abc_sum = 1000;
	register int a, b, c;

	c = abc_sum;

	while (c-- > 1) { 
		b = c - 1;
		do {
			a = b - 1;
			do {
				if (sum(a, b, c) == abc_sum && square(a) + square(b) == square(c))	{
					printf("%d\n", a * b * c);
					return 0;
				}
			} while (--a > 0);
		} while (--b > 0);
	}
	
	return 1;
}
