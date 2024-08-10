#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the stack head
 * @line_number: Line number
 *
 * Return: No return value
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp, *last;

	temp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	last = temp;
	last->next = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	(*stack) = last;
}
