#include "main.h"

/**
 * get_size -Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: size
 */
int get_size(const char *format, int *i)
{
	int ci = *i + 1;
	int size = 0;

	if (format[ci] == 'l')
		size = S_LONG;
	else if (format[ci] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = ci - 1;
	else
		*i = ci;

	return (size);
}
