#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @num: A pointer to the number to modify.
 * @idx: The index of the bit to set to 0.
 * Return: 1 on success, -1 on failure.
 */
int clear_bit(unsigned long int *num, unsigned int idx)
{
	unsigned long int mask = 0x01;

	if (idx >= (8 * sizeof(unsigned long int)))
		return (-1);

	mask = ~(mask << idx);
	if (mask == 0x00)
		return (-1);

	*num &= mask;
	return (1);
}

