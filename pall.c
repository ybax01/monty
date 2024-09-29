#include <stdio.h>
#include "monty.h"

/**
 * pall - Prints all the values on the stack from top to bottom
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode in the bytecode file (unused)
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;  /* Unused parameter */

	/* Traverse the stack and print each value */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
