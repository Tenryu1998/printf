#include "main.h"
/**
 * print_percent - prints the charater %.
 * @arg: argument passed
 * Return: 1.
 */
int print_percent(va_list arg __attribute__((unused)))
{
	/** 37 represents the % character in ASCII */
	_putchar(37);
	return (1);
}
