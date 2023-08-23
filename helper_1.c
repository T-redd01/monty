#include "monty.h"

/**
 * err_writer - writes to stderr
 * @arg1: strign one
 * @arg2: string two
 * @arg3: string three
 * @arg4: string four
 */
void err_writer(char *arg1, char *arg2, char *arg3, char *arg4)
{
	if (arg1)
		write(2, arg1, strlen(arg1));

	if (arg2)
		write(2, arg2, strlen(arg2));

	if (arg3)
		write(2, arg3, strlen(arg3));

	if (arg4)
		write(2, arg4, strlen(arg4));
}

/**
 * free_matrix - frees a matrix
 * @matrix: 2d array
 */
void free_matrix(char **matrix)
{
	int i;

	if (!matrix)
		return;

	for (i = 0; matrix[i]; i++)
		free(matrix[i]);
}

