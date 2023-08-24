#include "monty.h"

/**
 * nop_op - does nothing
 * @stack: list of data
 * @line_number: current line number
 */
void nop_op(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	/**
	 * This is a nlank code that does nothing
	 */
}

/**
 * sub_op - add first element to second and remove
 * @stack: list of data
 * @line_number: current line number
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp || !(tmp->next))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't sub, stack too short\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->next->n -= tmp->n;
	*stack = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

/**
 * div_op - add first element to second and remove
 * @stack: list of data
 * @line_number: current line number
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp || !(tmp->next))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't div, stack too short\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": division by zero\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->next->n /= tmp->n;
	*stack = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

/**
 * mul_op - add first element to second and remove
 * @stack: list of data
 * @line_number: current line number
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp || !(tmp->next))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't mul, stack too short\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->next->n *= tmp->n;
	*stack = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

/**
 * mod_op - add first element to second and remove
 * @stack: list of data
 * @line_number: current line number
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp || !(tmp->next))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't mod, stack too short\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": division by zero\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->next->n %= tmp->n;
	*stack = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

