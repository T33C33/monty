#include "monty.h"

/**
 * divide_top_two_elements - Divides the top two elements of the stack.
 * @stack: Pointer to the stack head
 * @line_number: Line number
 * Return: No return
 */
void divide_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int stack_length = 0, result;

	while (current)
	{
		current = current->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't divide, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
