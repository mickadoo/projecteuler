/**
 * Starting in the top left corner of a 2×2 grid,  and only being able to move to the right and down,  there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20×20 grid?
*/

#include <stdio.h>

#define GRID_SIZE 2 

void traverse(int x, int y);
int paths = 0;

int main()
{
	traverse(0, 0);
	printf("%d\n", paths);
}

void traverse(int x, int y)
{
	if (x < GRID_SIZE)
		traverse(x+1, y);
	if (y < GRID_SIZE)
		traverse(x, y+1);
	if (x == GRID_SIZE && y == GRID_SIZE)
		paths++;
}
