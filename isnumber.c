#include <ctype.h>
#include "monty.h"

/**
 * isnumber - checks if a string represents a valid integer
 * @str: the string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int isnumber(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	/* Check for optional sign */
	if (*str == '-' || *str == '+')
		str++;

	/* Ensure the string contains only digits */
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
