#include "main.h"

/**
 * _strlen - Returns the length of a string.
 *
 * @s: Pointer to the string.
 *
 * Return: The length of the string (excluding the null byte).
 */
int _strlen(char *s)
{
	int length = 0;

	/* Loop through the string until the null terminator is encountered */
	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
