#include "monty.h"
#include <string.h>

/**
 * execute_opcode - Executes the corresponding function for the given opcode
 * @opcode: The opcode to execute
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode in the bytecode file
 * @arg: Argument to pass to the function (if any)
 *
 * Return: void
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number, char *arg)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number, arg);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
