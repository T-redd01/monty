#include "monty.h"

int main(int ac, char **av) {
	int fd;
	size_t count = 0;
	char *line = NULL;


	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", av[0]);
		return (EXIT_FAILURE);
	}

	while (1)
	{
		count = line_count();
		line = extract_line(fd);
		if (!line)
			break;
		parse_line(line)
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
