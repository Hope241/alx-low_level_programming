#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: Character to write
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_binary - Prints the binary representation of a number
 * @n: Number to convert to binary
 *
 * Return: Nothing (void)
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int len = 0;

	while (mask <= n)
	{
		len++;
		mask <<= 1;
	}
	if (len > 0)
		mask >>= 1;
	while (mask > 0)
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');
		mask >>= 1;
	}
}

