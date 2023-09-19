#include "main.h"

/**
 * power - calculates the result of
 * raising an integer base to an integer exponent
 *
 * @base: integer base
 * @exponent: integer exponent
 * Return: 1.
 */
int power(int base, int exponent)
{
	int result = 1, i = 0;

	for ( ; i < exponent; i++)
		result *= base;

	return (result);
}
