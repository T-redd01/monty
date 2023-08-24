#include "monty.h"

/**
 * pchar_op - prints first element in ascii
 * @stack: list of data
 * @line_number: current line number
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!(*stack))
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't pchar, stack empty\n", NULL, NULL, NULL);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (num < 0 || num > 127)
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(line_number);
		err_writer(": can't pchar, value out of range\n", NULL, NULL, NULL);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", num);
}

/**
 * pstr_op - print ascii of each node / treat list as string
 * @stack: list of data
 * @line_number: current line number
 */
void pstr_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;
	int num;

	while (tmp)
	{
		num = tmp->n;
		if (num < 0 || num > 127)
			break;

		if (num == 0)
			break;
		printf("%c", num);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl_op - move element 1 to last
 * @stack: list of data
 * @line_number: current line number
 */
void rotl_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack, *tmp2;

	if (!(*stack) || !(tmp->next))
		return;

	while (tmp->next)
		tmp = tmp->next;

	tmp2 = (*stack)->next;
	tmp2->prev = NULL;
	tmp->next = (*stack);
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	*stack = tmp2;
}

/**
 * rotr_op - move last element to 1st
 * @stack: list of data
 * @line_number: current line number
 */
void rotr_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack) || !(tmp->next))
		return;

	while (tmp->next)
		tmp = tmp->next;

	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

