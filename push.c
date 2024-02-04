#include "main.h"

/**
 * push - Pushes int to stack.
 * @stack: Pointer to top of the stack.
 * @line_num: number in the file.
 */
void push(stack_t **stack, unsigned int line_num)
{
	char *value = "5"; 
	stack_t *new_node = malloc(sizeof(stack_t));
	
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!value || !isdigit(value[0]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(value);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
