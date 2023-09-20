#include "main.h"

/**
 * print_binary - prints an unsigned int as binary
 * @arg: value pased
 * Return: 1.
 */
int print_binary(va_list arg)
{
	int index;
	int max_bits = sizeof(int) * 8;
	char *binary = (char *)malloc(max_bits + 1);
	int c, ci;
	unsigned int num = va_arg(arg, unsigned int);


	if (binary == NULL)
	{
		exit(1);
	}

	index = max_bits - 1;

	while (num > 0)
	{
		binary[index--] = (num % 2) ? '1' : '0';
		num /= 2;
	}

	binary[max_bits] = '\0';
	ci = 0;
	for (ci = 0; ci < max_bits; ci++)
	{
		if (&binary[ci] != NULL)
		{
			_putchar(binary[ci]);
			c++;
		}
	}

	return (c);
}
