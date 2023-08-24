#include "monty.h"

#define BUFFSIZE 1024

/**
 * _getc - get a character from an fd
 * @fd: fiel with chars
 *
 * Return: read character
 */
char _getc(int fd)
{
	char c;
	int r;

	r = read(fd, &c, 1);
	if (r == 0 || r == -1)
		return ('\0');
	return (c);
}

/**
 * allocator - allocates memory according to buffer size for line
 * @stk: list of data
 * @fd: file descriptor
 * @container: current line / string
 * @l_idx: size of curret line
 * @b_idx: num of chars in buff - 1
 *
 * Return: newly allocated memory space
 */
char *allocator(stack_t *stk, int fd, char *container,
		size_t l_idx, size_t b_idx)
{
	char *new = NULL;

	new = malloc((l_idx + b_idx + 2) * sizeof(char));
	if (!new)
	{
		err_writer("Error: malloc failed\n", NULL, NULL, NULL);
		if (container)
			free(container);
		free_stack(stk);
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (container)
	{
		strcpy(new, container);
		free(container);
	}
	new[l_idx] = '\0';
	return (new);
}

/**
 * extract_line - get line from file
 * @stk: list of data
 * @fd: file descriptor
 *
 * Return: line from file
 */
char *extract_line(stack_t *stk, int fd)
{
	char c, buff[BUFFSIZE], *line = NULL;
	size_t b_idx = 0, l_idx = 0;

	while ((c = _getc(fd)))
	{
		buff[b_idx] = c;
		if (b_idx == 1022)
		{
			buff[b_idx + 1] = '\0';
			if (buff[b_idx] == '\n')
			{
				line = allocator(stk, fd, line, l_idx, b_idx);
				strcat(line, buff);
				return (line);
			}
			line = allocator(stk, fd, line, l_idx, b_idx);
			strcat(line, buff);
			l_idx += b_idx + 1;
			b_idx = 0;
		}

		if (buff[b_idx] == '\n')
		{
			buff[b_idx + 1] = '\0';
			line = allocator(stk, fd, line, l_idx, b_idx);
			strcat(line, buff);
			return (line);
		}
		b_idx++;
	}
	return (NULL);
}

