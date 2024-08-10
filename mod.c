#include "monty.h"

/**
 * mod_stack - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number
 * Return: No return value
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int stack_len = 0, remainder;

	current = *stack;
	while (current)
	{
		current = current->next;
		stack_len++;
	}

	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't perform mod, stack too short\n", line_number);
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

	remainder = current->next->n % current->n;
	current->next->n = remainder;
	*stack = current->next;
	free(current);
}
