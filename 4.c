#include <stdio.h>
#include <string.h>

#define MAX_STR 10

int is_palindrome(int num);

/**
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
*/
int main()
{
	int limit = 1000; // max product + 1 
	int a, b;
	int max;

	for (a = limit; a > 1; a--, b = limit)
		while (--b > 1)
			if (is_palindrome(a * b)) {
				max = a * b > max ? a * b : max;
			}

	printf("%d\n", max);
	return 0;
}

int is_palindrome(int num)
{
	char as_str[MAX_STR];
	snprintf(as_str, MAX_STR, "%d", num);
	int end = strlen(as_str) - 1;
	int start;

	for (start = 0; start < end; start++, end--)
		if (as_str[start] != as_str[end])
			return 0;

	return 1;
}
