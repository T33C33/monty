#include "monty.h"

/**
 * print_stack - prints the stack
 * @stack: pointer to the stack
 * @counter: unused counter
 * Return: void
 */
void print_stack(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *stack;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
