#include "monty.h"

#define BUFFSIZE 1024

char _getc(int fd)
{
	char c;
	int r;

	r = read(fd, &c, 1);
	if (r == 0 || r == -1)
		return ('\0');
	return (c);
}

char *allocator(int fd, char *container, size_t l_idx,
		char *buff, size_t b_idx)
{
	size_t i;
	char *new = NULL;

	new = malloc((l_idx + b_idx + 2) * sizeof(char));
	if (!new)
	{
		dprintf(2, "Error: malloc failed\n");
		if (container)
			free(container);
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


char *extract_line(int fd)
{
	char c, buff[BUFFSIZE], *line = NULL;
	size_t b_idx = 0, l_idx = 0;

	while (c = _getc(fd))
	{
		buff[b_idx] = c;
		if (b_idx == 1022)
		{
			buff[b_idx + 1] = '\0';
			if (buff[b_idx] == '\n')
			{
				line = allocator(fd, line, l_idx, buff, b_idx);
				strcat(line, buff);
				return (line);
			}
			line = allocator(fd, line, l_idx, buff, b_idx);
			strcat(line, buff);
			l_idx += b_idx + 1;
			b_idx = 0;
		}

		if (buff[b_idx] == '\n')
		{
			buff[b_idx + 1] = '\0';
			line = allocator(fd, line, l_idx, buff, b_idx);
			strcat(line, buff);
			return (line);
		}
		b_idx++;
	}
	return (NULL);
}
