#include "monty.h"

/**
 * pall - Prints all values on the stack, starting from the top
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode in the bytecode file
 * @arg: Unused argument (required for function signature compatibility)
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *current = *stack;

	(void)line_number; /* Avoid unused parameter warning */
	(void)arg;         /* Unused argument */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
