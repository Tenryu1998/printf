#include "main.h"

void print_buffer(char buffer[], int *buffInd);

/**
 * _printf - Custom printf function
 * @format: printFormat.
 * Return: chars.
 */
int _printf(const char *printFormat, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffInd = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (printFormat == NULL)
		return (-1);

	va_start(args, printFormat);

	for (i = 0; printFormat && printFormat[i] != '\0'; i++)
	{
		if (printFormat[i] != '%')
		{
			buffer[buffInd++] = printFormat[i];
			if (buffInd == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffInd);
			flags = get_flags(printFormat, &i);
			width = get_width(printFormat, &i, args);
			precision = get_precision(printFormat, &i, args);
			size = get_size(printFormat, &i);
			++i;
			printed = handle_print(printFormat, &i, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buffInd);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffInd: Index at which to add next char it represents the length.
 */
void print_buffer(char buffer[], int *buffInd)
{
	if (*buffInd > 0)
		write(1, &buffer[0], *buffInd);

	*buffInd = 0;
}
