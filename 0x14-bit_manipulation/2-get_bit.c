#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @num: The number to retrieve the bit from
 * @index: The index of the bit to retrieve
 *
 * Return: The value of the bit at the given index, or -1 if an error occurs
 */
int get_bit(unsigned long int num, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return ((num >> index) & 1);
}

