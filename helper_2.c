#include "monty.h"

/**
 * _strrev - reverse string
 * @buff: string to reverse
 */
void _strrev(char *buff)
{
	int i, j, len;
	char c;

	len = strlen(buff) / 2;
	for (i = 0, j = (strlen(buff) - 1); i <= len; i++, j--)
	{
		c = buff[i];
		buff[i] = buff[j];
		buff[j] = c;
	}
}

/**
 * write_num - writes num to stderr
 * @num: num to write
 */
void write_num(unsigned int num)
{
	int i = 0;
	char buff[12], c = '0';

	if (num == 0)
	{
		write(2, &c, 1);
		return;
	}

	while (num)
	{
		buff[i++] = (num % 10) + 48;
		num /= 10;
	}
	buff[i] = '\0';

	_strrev(buff);
	write(2, buff, strlen(buff));
}

/**
 * free_stack - free stack mem
 * @top: top of stack
 */
void free_stack(stack_t *top)
{
	stack_t *tmp;

	if (!top)
		return;

	while (top->prev)
		top = top->prev;

	while (top)
	{
		tmp = top->next;
		free(top);
		top = tmp;
	}
}
