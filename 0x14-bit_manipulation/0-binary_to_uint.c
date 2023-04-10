#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to the binary string.
 *
 * Return: the converted number, or 0 if b is NULL or contains characters
 * other than 0 or 1.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0' || b[i] == '1')
		{
			num <<= 1;
			num += b[i] - '0';
		}
		else
		{
			return (0);
		}
	}

	return (num);
}

