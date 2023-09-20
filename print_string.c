#include "main.h"
/**
 * print_string - prints arg in string format.
 * @arg: argument to print.
 * Return: the length of the string.
 */

int print_string(va_list arg)
{
	char *str;
	int i, strlen = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";

	if (str != NULL)
	{
		strlen = _strlen(str);
		for (i = 0; i < strlen; i++)
			_putchar(str[i]);
	}
	return (strlen);
}
