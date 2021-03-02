#include "menger.h"
/**
 * print_data - indicates if data has to be printed or not
 * @x: x position in the grid
 * @y: y position in the grid
 *
 * Return: Returns 1 if data have to printed or 0 otherwise
 */
static int print_data(int x, int y)
{
	while (1)
	{
		if (x == 0 || y == 0)
			return (1);
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x = x / 3;
		y = y / 3;
	}
}

/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: level of the Menger Sponge
 *
 * Return: Nothing
 */
void menger(int level)
{
	int n = 0, row = 0, col = 0;

	n = pow(3, level);
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			if (print_data(row, col))
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
