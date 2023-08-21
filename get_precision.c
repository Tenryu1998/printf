#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @args: arguments.
 *
 * Return: Precision(p).
 */
int get_precision(const char *format, int *i, va_list args)
{
	int ci = *i + 1;
	int p = -1;

	if (format[ci] != '.')
		return (p);

	p = 0;

	for (ci += 1; format[ci] != '\0'; ci++)
	{
		if (is_digit(format[ci]))
		{
			p *= 10;
			p += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			p = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = ci - 1;

	return (p);
}
