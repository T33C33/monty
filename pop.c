#include "monty.h"

/**
 * pop_stack - removes the top element from the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	free(temp);
}