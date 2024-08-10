#include "monty.h"

/**
 * add_node - Add a node to the head of the stack
 * @head: Pointer to the head of the stack
 * @value: Value to be stored in the new node
 * Return: void
 */
void add_node(stack_t **head, int value)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = value;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
