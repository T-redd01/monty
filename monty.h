#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct cache_s - holds memory for parsing
 * @fd: currently open file descriptor to extract code lines
 * @count: current line number
 * @line: line extracted from fd
 * @args: vector of args extracted from line
 * @stack: stack data structure
 *
 * Description: keeps track of resource needed to free on err
 */
typedef struct cache_s
{
	int fd;
	size_t count;
	char *line;
	char *args[3];
	stack_t *stack;
} cache_t;

extern int format; /* 1 means queue, zero means stack (default) */

/*********************** UTILS ***/
/* helper_1 */
void err_writer(char *arg1, char *arg2, char *arg3, char *arg4);
void free_matrix(char **matrix);
void print_matrix(char **matrix);

/* helper_2 */
void write_num(unsigned int num);
void free_stack(stack_t *top);

/* extract_l */
char *extract_line(int fd);

/* parser */
void parse_line(cache_t *mm);

/* find_op */
void is_dig(char *word, unsigned int ln);
void push_op(stack_t **stack, unsigned int line_number, char *val);
void find_op(cache_t *mm);

/* ops_1 */
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);

/* ops_2 */
void nop_op(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);

/* ops_3 */
void pchar_op(stack_t **stack, unsigned int line_number);
void pstr_op(stack_t **stack, unsigned int line_number);
void rotl_op(stack_t **stack, unsigned int line_number);
void rotr_op(stack_t **stack, unsigned int line_number);

/* op_4 */
void stack_op(stack_t **stack, unsigned int line_number);
void queue_op(stack_t **stack, unsigned int line_number);

#endif
