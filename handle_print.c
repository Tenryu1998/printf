#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @args: Arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @f: Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 *
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int f, int w, int p, int s)
{
	int i, ulen = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(args, buffer, f, w, p, s));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		ulen += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			ulen += write(1, " ", 1);
		else if (w)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		ulen += write(1, &fmt[*ind], 1);
		return (ulen);
	}
	return (printed_chars);
}
