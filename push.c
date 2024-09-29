#include <stdlib.h>
#include <stdio.h>
#include "monty.h"


/**
 * push - push to stack function
 * @stack: double pointer to the stack
 * @line_number: line num in the bytecode file
 * @arg: what to push
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    int value;

    // Check if the argument is NULL or not a valid integer
    if (arg == NULL || !_is_number(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);  // Convert the argument to an integer

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the new node
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    // If the stack is not empty, update the previous top node
    if (*stack != NULL)
        (*stack)->prev = new_node;

    // The new node becomes the top of the stack
    *stack = new_node;
}


/**
 * _is_number - Checks if a string is a valid number
 * @str: The string to check
 *
 * Return: 1 if valid number, 0 otherwise
 */
int _is_number(char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}
