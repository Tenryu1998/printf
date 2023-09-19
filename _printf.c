#include "main.h"

/**
 * _printf -  produces output according to a format.
 * @format: The format of the output
 * Return: The number of characters that are printed
 */
int _printf(const char *format, ...)
{
	int printedChars = 0, i = 0, ni = 0, j = 0, specFound = 0;

	va_list args;

	specifierToFunc s2f[5] = {
		{"%c", print_char},
		{"%s", print_string},
		{"%%", print_percent},
		{"%i", print_integer},
		{"%d", print_decimal}
	};

	va_start(args, format);
	if (format == NULL)
                return (-1);


	for (i = 0; format[i] != '\0'; )
	{
		ni = i + 1;
		specFound = 0;
		for (j = 0; j < 5; j++)
		{
			if (s2f[j].specifier[0] == format[i] && s2f[j].specifier[1] == format[ni])
			{
				printedChars += s2f[j].printFunc(args);
				i += 2;
				specFound = 1;
				break;
			}
		}
		if (specFound == 1)
			continue;
		else
		{
			_putchar(format[i]);
			printedChars += 1;
			i++;
		}
	}
	va_end(args);
	return (printedChars);
}
