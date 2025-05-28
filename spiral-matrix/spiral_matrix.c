#include "spiral_matrix.h"

static void	fill(spiral_matrix_t *result)
{
	int			x;
	int			y;
	int			right_nbr;
	int			bottom_nbr;
	int			left_nbr;
	int			top_nbr;
	int			number;

	x = 0;
	y = 0;
	right_nbr = result->size;
	bottom_nbr = result->size - 1;
	left_nbr = result->size - 1;
	top_nbr = result->size - 2;
	number = 1;

	while (number <= result->size * result->size)
	{
		// right
		for (int i = 0; i < right_nbr; i++)
			result->matrix[y][x + i] = number++;
		x += right_nbr - 1;
		right_nbr -= 2;

		// bottom
		for (int i = 0; i < bottom_nbr; i++)
			result->matrix[y + i + 1][x] = number++;
		y += bottom_nbr;
		bottom_nbr -= 2;

		// left
		for (int i = 0; i < left_nbr; i++)
			result->matrix[y][x - i - 1] = number++;
		x -= left_nbr;
		left_nbr -= 2;

		// top
		for (int i = 0; i < top_nbr; i++)
			result->matrix[y - i - 1][x] = number++;
		y -= top_nbr;
		top_nbr -= 2;

        x++;
	}
}

spiral_matrix_t	*spiral_matrix_create(int size)
{
	spiral_matrix_t	*result;

	if (size < 0)
		return (NULL);
	
	result = malloc(sizeof(spiral_matrix_t));
	if (!result)
		return (NULL);
	
	if (size == 0)
	{
		result->size = 0;
		result->matrix = NULL;
		return (result);
	}

	result->matrix = malloc(sizeof(int *) * size);
	if (!result->matrix)
	{
		free(result);
		return (NULL);
	}
	for (int i = 0; i < size; i++)
	{
		result->matrix[i] = malloc(sizeof(int) * size);
		if (!result->matrix[i])
		{
			for (int j = 0; j < i; j++)
				free(result->matrix[j]);
			free(result->matrix);
			free(result);
			return (NULL);
		}
	}
	result->size = size;
	fill(result);
	return (result);
}

void	spiral_matrix_destroy(spiral_matrix_t *matrix)
{
	if (!matrix)
		return ;

	if (matrix->matrix)
	{
		for (int i = 0; i < matrix->size; i++)
			free(matrix->matrix[i]);
		free(matrix->matrix);
	}
	free(matrix);
}
