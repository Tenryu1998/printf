#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/** STRUCTS */
typedef struct format
{
	char *specifier;
	int (*printFunc)();
} specifierToFunc;

/** Functions */
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_decimal(va_list arg);
int print_integer(va_list arg);
int print_binary(va_list arg);
int _putchar(char c);
int _strlen(char *s);
int power(int base, int exponent);

#endif
