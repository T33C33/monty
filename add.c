#include "monty.h"

/**
 * add_top_two_elements - adds the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: no return
 */
void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int stack_length = 0, sum;

	// Calculate the length of the stack
	while (current)
	{
		current = current->next;
		stack_length++;
	}

	// Check if the stack has at least 2 elements
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	// Calculate the sum of the top two elements
	current = *stack;
	sum = current->n + current->next->n;

	// Update the second element with the sum
	current->next->n = sum;

	// Remove the first element from the stack
	*stack = current->next;
	free(current);
}