#include "main.h"

/**
 * set_bit - Sets a bit at a given index to 1
 * @num: The number to modify
 * @bit_index: The index of the bit to set
 *
 * Return: 1 if it worked, or -1 on error
 */
int set_bit(unsigned long int *num, unsigned int bit_index)
{
	if (bit_index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*num |= (1UL << bit_index);

	return (1);
}

