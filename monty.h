#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structure for stack nodes */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Structure for opcode and its function */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, char *arg);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number, char *arg);
void pall(stack_t **stack, unsigned int line_number, char *arg);
void free_stack(stack_t *stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number, char *arg);
int _is_number(char *str);

#endif /* MONTY_H */
