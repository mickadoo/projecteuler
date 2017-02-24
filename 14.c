/**
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13,  we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem),  it is thought that all starting numbers finish at 1.
 *
 * Which starting number,  under one million,  produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 * time: basic = 9 seconds~
 * with cache: BOOM 0.036 seconds
*/
#include <stdio.h>

#define MAX_BASE_NUM 1000000

int get_num_steps(long num);
int step_cache[MAX_BASE_NUM * 1000];

int main()
{
	long current = 0;
	long max_num = 0;
	int max_steps = 0;
	int current_steps = 0;

	while (++current < MAX_BASE_NUM) {
		current_steps = get_num_steps(current);
		if (current_steps > max_steps) {
			max_steps = current_steps;
			max_num = current;
		}
		if (step_cache[current] == 0) {
			step_cache[current] = current_steps;
		}
	}

	printf("%ld with %d steps\n", max_num, max_steps);
}

int get_num_steps(long num)
{
	int steps = 0;

	while (++steps) {
		if (num % 2 == 0)
			num = num / 2;	
		else
			num = (3 * num) + 1;
		if (num == 1)
			break;
		if (num < MAX_BASE_NUM && step_cache[num] != 0) {
			return steps + step_cache[num];
		}
	}
	
	return steps;
}
