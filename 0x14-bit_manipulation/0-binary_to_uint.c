#include <stddef.h>   /* Added to define NULL */
#include <stdlib.h>   /* Added to define malloc, free, and EXIT_FAILURE */
#include <string.h>   /* Added to define strlen and strcpy */

unsigned int binary_to_uint(const char *b)
{
    unsigned int result;
    char *tmp_b;
    const char *c;

    if (b == NULL)
        return (0);

    result = 0;

    /* Fixed incompatible implicit declaration of malloc by including stdlib.h */
    tmp_b = malloc(strlen(b) + 1);
    if (tmp_b == NULL)
        exit(EXIT_FAILURE);

    /* Fixed incompatible implicit declaration of strcpy by including string.h */
    strcpy(tmp_b, b);

    /* Fixed loop declaration error by compiling with -std=c99 */
    for (c = tmp_b; *c != '\0'; ++c)
    {
        if (*c == '0')
        {
            result <<= 1;
        }
        else if (*c == '1')
        {
            result <<= 1;
            result |= 1;
        }
        else
        {
            free(tmp_b);
            return (0);
        }
    }

    free(tmp_b);
    return (result);
}

