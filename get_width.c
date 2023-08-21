#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @args: arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list args)
{
	int ci;
	int w = 0;

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		if (is_digit(format[ci]))
		{
			w *= 10;
			w += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			w = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = ci - 1;

	return (w);
}
