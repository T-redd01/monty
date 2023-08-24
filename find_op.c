#include "monty.h"

/**
 * not_found_err - opcode was not found
 * @lnum: current line number
 * @opcode: incorrect opcode
 */
void not_found_err(unsigned int lnum, char **opcode)
{
	err_writer("L", NULL, NULL, NULL);
	write_num(lnum);
	err_writer(": unknown instruction ", opcode[0], "\n", NULL);
	free_matrix(opcode);
	exit(EXIT_FAILURE);
}

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
		free(word);
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
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	num = atoi(val);
	free(val);
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
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
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
			free(mm->args[0]);
			push_op(&(mm->stack), mm->count, mm->args[1]);
			return;
		}
		if (!(strcmp(ops[i].opcode, mm->args[0])))
		{
			free_matrix(mm->args);
			ops[i].f(&(mm->stack), mm->count);
			return;
		}
	}
	not_found_err(mm->count, mm->args);
}

