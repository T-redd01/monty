#include "monty.h"

/**
 * pall_op - print all elements
 * @stack: list with data
 * @line_number: file line number
 */
void pall_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack))
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
