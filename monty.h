#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
	int flag;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_node(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int counter);
void print_top(stack_t **stack, unsigned int line_number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void pop_stack(stack_t **stack, unsigned int line_number);
void swap_elements(stack_t **stack, unsigned int line_number);
void add_top_two_elements(stack_t **stack, unsigned int line_number);
void my_custom_function(stack_t **stack, unsigned int line_number);
void subtract_stack_top(stack_t **stack, unsigned int line_number);
void divide_top_two_elements(stack_t **stack, unsigned int line_number);
void multiply_top_two(stack_t **stack, unsigned int line_number);
void mod_stack(stack_t **stack, unsigned int line_number);
void pchar_stack(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
#endif