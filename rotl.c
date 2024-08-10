#include "monty.h"

/**
 * rotate_left - Rotates the stack to the left
 * @stack: Pointer to the stack
 * @line_number: Line number
 */
void rotate_left(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack, *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	aux = (*stack)->next;
	aux->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}
