#include "main.h"

/**
 * bfree - it free pointer
 * @ptr: its address
 *
 * Return: 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
