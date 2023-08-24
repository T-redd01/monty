#include "monty.h"

/**
 * stack_op - change format to stack / default
 * @stack: list of data
 * @line_number: current line number
 */
void stack_op(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	format = 0;
}

/**
 * queue_op - change format to queue
 * @stack: list of data
 * @line_number: current line number
 */
void queue_op(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	format = 1;
}
