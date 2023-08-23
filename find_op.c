#include "monty.h"

/**
 * is_dig - checks if string contains non numeric char
 * @word: strign to check
 * @ln: line number
 */
void is_dig(char *word, unsigned int ln)
{
	int i = 0, flag = 0;

	if (!word)
		flag = 1;

	if (word[0] == '-')
		i = 1;

	for (; word && word[i]; i++)
	{
		if (word[i] > 57 || word[i] < 48)
		{
			flag = 1;
			break;
		}
	}

	if (flag)
	{
		err_writer("L", NULL, NULL, NULL);
		write_num(ln);
		err_writer(": usage: push integer\n", NULL, NULL, NULL);
		exit(EXIT_FAILURE);
	}
}

/**
 * push_op - push opcode
 * @stack: stack with data
 * @line_number: current line number
 * @val: word with numeric chars
 */
void push_op(stack_t **stack, unsigned int line_number, char *val)
{
	int num;
	stack_t *new = NULL;

	is_dig(val, line_number);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		err_writer("Error: malloc failed\n", NULL, NULL, NULL);
		exit(EXIT_FAILURE);
	}
	num = atoi(val);
	new->n = num;
	new->prev = NULL;
	new->next = NULL;

	if (!(*stack))
	{
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

/**
 * find_op - find opcode to carry out
 * @mm: program memory
 */
void find_op(cache_t *mm)
{
	int i;
	instruction_t ops[] = {
		{"pall", pall_op},
		{"pint", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{"sub", NULL},
		{"div", NULL},
		{"mul", NULL},
		{"mod", NULL},
		{"pchar", NULL},
		{"pstr", NULL},
		{"rotl", NULL},
		{"rotr", NULL},
		{"stack", NULL},
		{"queue", NULL},
		{NULL, NULL}
	};

	if (mm->args[0] == NULL)
		return;

	for (i = 0; ops[i].opcode; i++)
	{
		if (!(strcmp("push", mm->args[0])))
		{
			push_op(&(mm->stack), mm->count, mm->args[1]);
			return;
		}

		if (!(strcmp(ops[i].opcode, mm->args[0])))
		{
			ops[i].f(&(mm->stack), mm->count);
			return;
		}
	}
}

