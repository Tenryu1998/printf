#include "main.h"

/**
 * print_decimal - prints arg as a signed decimal
 * @arg: value pased
 * Return: 1.
 */
int print_decimal(va_list arg)
{
	char buffer[32];
	int i = 0, len, printedChars = 0;
	int num = va_arg(arg, int);

	if (num == 0)
	{
		_putchar('0');
		printedChars++;
		return (printedChars);
	}

	if (num < 0)
	{
		_putchar('-');
		printedChars++;
		num = -num;
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	for (len = i - 1; len >= 0; len--)
	{
		_putchar(buffer[len]);
		printedChars++;
	}

	return (printedChars);
}
