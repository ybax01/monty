#include "monty.h"
#include <string.h>

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
	char *opcode, *arg;

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
		opcode = strtok(line, " \n\t");
		arg = strtok(NULL, " \n\t");

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
