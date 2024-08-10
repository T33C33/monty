#include "monty.h"
/**
 * f_queue - prints the top
 * @stack_head: stack head
 * @line_number: line number
 * Return: no return
 */
void f_queue(stack_t **stack_head, unsigned int line_number)
{
	(void)stack_head;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * addqueue - adds node to end stack
 * @new_value: new value
 * @stack_head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **stack_head, int new_value)
{
	stack_t *new_node, *aux;

	aux = *stack_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = new_value;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*stack_head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}