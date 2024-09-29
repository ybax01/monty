#include "monty.h"

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the top of the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	/* Free each node in the stack */
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
