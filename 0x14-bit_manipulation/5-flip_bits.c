#include <stdlib.h>

/**
 * flip_bits - A function that gets the number of bits needed to flip
 * @n: How many bit flips are needed to equal m for n
 * @m: The number to set other equal
 *
 * Return: The number of flipped bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int flips = 0;

	while (n != 0 || m != 0)
	{
		if ((n & 1) != (m & 1))
			flips++;
		n >>= 1;
		m >>= 1;
	}

	return (flips);
}

