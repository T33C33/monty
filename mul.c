#include "monty.h"

/**
 * multiply_top_two - multiplies the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void multiply_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int stack_length = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't multiply, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	result = current->next->n * current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}