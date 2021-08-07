#include "sort.h"

/**
 * count_sort - sort by current digit
 * @array: array to sort
 * @size: size of array
 * @temp_array: temp array
 * @exp: current digit exponent
 * Return: if array changed
 */
static void count_sort(int *array, size_t size, int *temp_array, long exp)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int) size; i++)
		temp_array[i] = 0;
	for (i = 0; i < (int) size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
		temp_array[--count[(array[i] / exp) % 10]] = array[i];
	for (i = 0; i < (int) size; i++)
		array[i] = temp_array[i];
}

/**
 * radix_sort - sorts by DIGITS
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max = 0;
	long exp;
	int *temp_array = NULL;

	if (!array || size < 2)
		return;
	temp_array = malloc(sizeof(int) * size);
	if (!temp_array)
		return;
	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, temp_array, exp);
		print_array(array, size);
	}
	free(temp_array);
}

