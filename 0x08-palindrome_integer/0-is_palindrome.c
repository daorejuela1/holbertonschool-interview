#include "palindrome.h"
/**
 * _get_digits - method to get the quantity of digits in a number
 * @n: number to analyze
 *
 * Return: the number of digits in the number
 */
static unsigned long _get_digits(unsigned long n)
{
	if (n > 99999999999999999)
		return (100000000000000000);/* 18 digits*/
	else if (n > 9999999999999999)
		return (10000000000000000);/* 17 digits*/
	else if (n > 999999999999999)
		return (1000000000000000);/* 16 digits*/
	else if (n > 99999999999999)
		return (100000000000000);/* 15 digits*/
	else if (n > 9999999999999)
		return (10000000000000);/* 14 digits*/
	else if (n > 999999999999)
		return (1000000000000);/* 13 digits*/
	else if (n > 99999999999)
		return (100000000000);/* 12 digits*/
	else if (n > 9999999999)
		return (10000000000);/* 11 digits*/
	else if (n > 999999999)
		return (1000000000);/* 10 digits*/
	else if (n > 99999999)
		return (100000000);/* 9 digits*/
	else if (n > 9999999)
		return (10000000);/* 8 digits*/
	else if (n > 999999)
		return (1000000);/* 7 digits*/
	else if (n > 99999)
		return (100000);/* 6 digits*/
	else if (n > 9999)
		return (10000);/* 5 digitss*/
	else if (n > 999)
		return (1000);/* 4 digits*/
	else if (n > 99)
		return (100);/* 3 digits*/
	else if (n > 9)
		return (10);/* 2 digits*/
	return (1); /* 1 digit*/
}
/**
 * is_palindrome - checks if a number is a palindrome
 * which means that every mirror number is the same
 * @n: number to analyze
 *
 * Return: 1 if is a palindrome 0 otherwise
 *
 */
int is_palindrome(unsigned long n)
{
	unsigned long left = 0, right = 0;

	left = _get_digits(n);
	right = 1;
	while (left > right)
	{
		if (((n / right) % 10) == ((n / left) % 10))
			left = left / 10, right = right * 10;
		else
			return (0);
	}
	return (1);
}
