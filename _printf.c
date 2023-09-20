#include "main.h"
/**
 * handle_specifier - prints string based on format and specifier
 * @format: string of characters.
 * @s2f: array of specifiers and their functions.
 * @arg: specifier arguments.
 * Return: number of characters printed.
 */

int handle_specifier(const char *format, specifierToFunc s2f[], va_list arg)
{
	int i = 0, j = 0, specFound = 0, p = 0, ni = 0;

	for (i = 0; format[i] != '\0'; )
	{
		ni = i + 1;
		specFound = 0;
		for (j = 0; j < 6; j++)
		{
			if (format[ni] != '\0')
			{	
				if (s2f[j].spec[0] == format[i] && s2f[j].spec[1] == format[ni])
				{
					p += s2f[j].printFunc(arg);
					specFound = 1;
					i += 2;
					break;
				}
			}
		}
		if (specFound == 1)
			continue;
		if (format[i] != '%')
		{
			_putchar(format[i]);
			p += 1;
		}
		i++;
	}
	return (p);
}

/**
 * _printf -  produces output according to a format.
 * @format: The format of the output
 * Return: The number of characters that are printed
 */
int _printf(const char *format, ...)
{
	int printedChars = 0;
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

	printedChars = handle_specifier(format, s2f, args);
	va_end(args);
	return (printedChars);
}
