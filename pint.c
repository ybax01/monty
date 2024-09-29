#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: the current line number in the bytecode file
 *
 * Description: Prints the value at the top of the stack. If the stack
 * is empty, it prints an error message and exits with EXIT_FAILURE.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
