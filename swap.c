#include "monty.h"

/**
 * swap_elements - swaps the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: no return
 */
void swap_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int stack_length = 0, temp;

	current = *stack;
	while (current)
	{
		current = current->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
