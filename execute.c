#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", push_node},
		{"pall", print_stack},
		{"pint", print_top}, {"pop", pop_stack},
		{"swap", swap_elements}, {"add", add_top_two_elements},
		{"nop", my_custom_function}, {"sub", subtract_stack_top},
		{"div", divide_top_two_elements}, {"mul", multiply_top_two},
		{"mod", mod_stack}, {"pchar", pchar_stack},
		{"pstr", print_string}, {"rotl", rotate_left}, {"rotr", rotr},
		{"queue", f_queue}, {"stack", f_stack}, {NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
