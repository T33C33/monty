#include "monty.h"

/**
 * print_string - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void print_string(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	(void)line_number;

	current_node = *stack;
	while (current_node)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}
