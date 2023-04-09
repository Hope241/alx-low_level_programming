#include "main.h"

/**
 * binary_to_uint - A finction that converts binary number
 * to an unsigned integer
 * @b: A pointer to binary string
 * Return: unsigned integer converted number
 */

unsigned int binary_to_uint(const char *b)
{
unsigned int result;
result = 0;
if (!b)
return (0);
for (; *b; ++b)
{
if (*b == '0' || *b == '1')
{
result <<= 1;
result += *b - '0';
}
else
{
}
return (0);
}
return (result);
}

