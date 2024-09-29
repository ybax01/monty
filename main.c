#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

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

	/* If the opcode is not found */
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * main - Monty bytecode interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of argument strings
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \n\t");
		char *arg = strtok(NULL, " \n\t");

		if (opcode != NULL && opcode[0] != '#')  /* Ignore comments and empty lines */
		{
			execute_opcode(opcode, &stack, line_number, arg);
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);  /* Free the stack */
	return (0);
}
