#include "monty.h"

/**
 * subtract_stack_top - Subtracts the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number
 */
void subtract_stack_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int difference;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	difference = temp->next->n - temp->n;
	temp->next->n = difference;
	*stack = temp->next;
	free(temp);
}
