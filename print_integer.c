#include "main.h"

/**
 * print_integer - prints arg as an integer
 * @arg: value pased
 * Return: 1.
 */
int print_integer(va_list arg)
{
	int Number = va_arg(arg, int);
	int lastDigit = Number % 10;
	int number = Number / 10;
	int digit, i = 1, decimalPlaces = 1;

	if (lastDigit < 0)
	{
		_putchar('-');
		number = number * -1;
		lastDigit = lastDigit * -1;
		i++;
	}
	Number = number;

	if (Number > 0)
	{
		for ( ; (number % 10) != 0; decimalPlaces++)
		{
			number = Number / power(10, decimalPlaces);
		}
		number = Number;
		for ( ; decimalPlaces > 0; decimalPlaces--)
		{
			digit = number / power(10, decimalPlaces);
			_putchar(digit + '0');
			number = number - (digit * power(10, decimalPlaces));
			i++;
		}
	}

	_putchar(lastDigit + '0');
	return (i);
}
