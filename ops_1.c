#include "monty.h"

/**
 * pall_op - print all elements
 * @stack: list with data
 * @line_number: file line number
 */
void pall_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * pint_op - print first element
 * @stack: list with data
 * @line_number: current line number
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't pint, stack empty\n", NULL, NULL, NULL);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * pop_op -remove first element
 * @stack: list of data
 * @line_number: current line number
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't pop an empty stack\n", NULL, NULL, NULL);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * swap_op - switch top two element
 * @stack: list of data
 * @line_number: current line number
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int num;

	if (!tmp || !(tmp->next))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't swap, stack too short\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	num = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = num;
}

/**
 * add_op - add first element to second and remove
 * @stack: list of data
 * @line_number: current line number
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp || !(tmp->next))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't add, stack too short\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->next->n += tmp->n;
	*stack = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

