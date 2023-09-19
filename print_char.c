#include "main.h"

/**
 * print_char - prints arg in char format.
 * @arg: value pased
 * Return: 1.
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	_putchar(c);
	return (1);
}
