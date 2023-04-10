#include "main.h"

/**
 * get_endianness - A function that checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int i = 1;
	char *c = (char *)&i;
	unsigned char *uc = (unsigned char *)c;
	int result;

	if (*uc == 1)
		result = 1;
	else
		result = 0;

	return (result);
}

