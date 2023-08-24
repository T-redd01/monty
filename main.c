#include "monty.h"

char *val;

/**
 * main - Entry point
 * @ac: number of args passed
 * @av: vector of passed args
 *
 * Return: on success EXIT_SUCCESS, on fail EXIT_FAIL
 */
int main(int ac, char **av)
{
	cache_t mm;

	if (ac != 2)
	{
		err_writer("USAGE: monty file\n", NULL, NULL, NULL);
		return (EXIT_FAILURE);
	}

	mm.fd = open(av[1], O_RDONLY);
	if (mm.fd == -1)
	{
		err_writer("Error: Can't open file ", av[1], "\n", NULL);
		return (EXIT_FAILURE);
	}

	mm.args[2] = NULL;
	mm.stack = NULL;
	mm.count = 0;
	while (1)
	{
		mm.count++;
		mm.line = extract_line(mm.fd);
		if (!(mm.line))
			break;
		parse_line(&mm);
		free(mm.line);
		find_op(&mm);
		//free_matrix(mm.args);
	}
	free_stack(mm.stack);
	close(mm.fd);
	return (EXIT_SUCCESS);
}
