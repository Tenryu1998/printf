#include "main.h"

/**
 * _printf -  produces output according to a format.
 * @format: The format of the output
 * Return: The number of characters that are printed
 */
int _printf(const char *format, ...)
{
	int printedChars = 0, i = 0, j = 0, specFound = 0;
	va_list args;
	specifierToFunc s2f[6] = {
		{"%c", print_char},
		{"%s", print_string},
		{"%%", print_percent},
		{"%i", print_integer},
		{"%d", print_decimal},
		{"%b", print_binary}
	};

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; )
	{
		specFound = 0;
		for (j = 0; j < 6; j++)
		{
			if (s2f[j].spec[0] == format[i])
			{
				if (s2f[j].spec[1] == format[i + 1])
				{
					printedChars += s2f[j].printFunc(args);
					i += 2;
				}
				else
					i++;
				specFound = 1;
				break;
			}
		}
		if (specFound == 1)
			continue;
		_putchar(format[i]);
		printedChars += 1;
		i++;
	}
	va_end(args);
	return (printedChars);
}
