#include "monty.h"

/**
 * extract_word - get word from line
 * @stk: list of data
 * @fd: resource file descriptor
 * @line: line with words
 * @idx: pointer to index in line
 *
 * Return: word from line
 */
char *extract_word(stack_t *stk, int fd, char *line, size_t *idx)
{
	size_t len = 0, p = *idx;
	char *new = NULL;

	while (line[*idx] && line[*idx] != '\n' && line[*idx] != ' ')
	{
		len++;
		*idx += 1;
	}

	new = malloc((len + 1) * sizeof(char));
	if (!new)
	{
		free(line);
		close(fd);
		free_stack(stk);
		err_writer("Error: malloc failed\n", NULL, NULL, NULL);
		exit(EXIT_FAILURE);
	}

	for (len = 0; line[p] && line[p] != '\n' && line[p] != ' '; p++, len++)
		new[len] = line[p];
	new[len] = '\0';
	return (new);
}

/**
 * is_comment - check if line is comemnt
 * @line: line to check
 *
 * Return: 1 is comment, 0 is not comment
 */
int is_comment(char *line)
{
	size_t i;

	for (i = 0; line[i]; i++)
	{
		if (line[i] != ' ')
		{
			if (line[i] == '#')
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

/**
 * parse_line - make 2 words from line
 * @mm: program memory
 */
void parse_line(cache_t *mm)
{
	size_t i;
	int words = 0;
	char *ln = mm->line;

	mm->args[0] = NULL;
	mm->args[1] = NULL;
	if ((is_comment(ln)))
		return;

	for (i = 0; ln[i] && ln[i] != '\n'; i++)
	{
		if (ln[i] != ' ')
			mm->args[words++] = extract_word(mm->stack, mm->fd, ln, &i);

		if (words == 2)
			break;

		if (ln[i] == '\0')
			i--;
	}
}

