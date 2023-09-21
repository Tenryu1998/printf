#include "main.h"

/**
 * print_integer - prints arg as an integer
 * @arg: value pased
 * Return: 1.
 */
int print_integer(va_list arg)
{
	int n = va_arg(args, int);
	int num, lastDigit = n % 10, digit, decimalPlaces = 1;
	int  printedChars = 1;

	n = n / 10;
	num = n;

	if (lastDigit < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		lastDigit = -lastDigit;
		printedChars++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			decimalPlaces++;
			num = num / 10;
		}
		num = n;
		while (decimalPlaces > 0)
		{
			digit = num / (10 * decimalPlaces);
			_putchar(digit + '0');
			num = num - (digit * (10 * decimalPlaces);
			decimalPlaces++;
			printedChars++;
		}
	}
	_putchar(lastDigit + '0');

	return (printedChars);
}
