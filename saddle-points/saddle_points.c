#include "saddle_points.h"

static size_t largest_of_the_line(size_t rows, size_t cols, size_t actual_row, uint8_t matrix[rows][cols])
{
    size_t result = 0;
    for (size_t i = 0; i < cols; i++)
    {
        if (matrix[actual_row][i] > matrix[actual_row][result])
            result = i;
    }
    return result;
}

static size_t minest_of_the_column(size_t rows, size_t cols, size_t actual_col, uint8_t matrix[rows][cols])
{
    size_t result = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (matrix[i][actual_col] < matrix[result][actual_col])
            result = i;
    }
    return result;
}

saddle_points_t *saddle_points(size_t rows, size_t cols, uint8_t matrix[rows][cols])
{
    if (rows == 0 || cols == 0 || matrix == NULL)
    {
        saddle_points_t *result = malloc(sizeof(saddle_points_t));
        if (!result)
            return (NULL);
        result->count = 0;
        return (result);
    }

    size_t count = 0;
    for (size_t y = 0; y < rows; y++)
    {
        for (size_t x = 0; x < cols; x++)
        {
            if (matrix[y][x] >= matrix[y][largest_of_the_line(rows, cols, y, matrix)] && 
                matrix[y][x] <= matrix[minest_of_the_column(rows, cols, x, matrix)][x])
                count++;
        }
    }

    saddle_points_t *result = malloc(sizeof(saddle_points_t) + sizeof(saddle_point_t) * count);
    if (!result)
        return (NULL);
    
    result->count = count;

    size_t i = 0;
    for (size_t y = 0; y < rows; y++)
    {
        for (size_t x = 0; x < cols; x++)
        {
            if (matrix[y][x] >= matrix[y][largest_of_the_line(rows, cols, y, matrix)] && 
                matrix[y][x] <= matrix[minest_of_the_column(rows, cols, x, matrix)][x])
            {
                result->points[i].row = y + 1;
                result->points[i].column = x + 1;
                i++;
            }
        }
    }

    return (result);
}

void free_saddle_points(saddle_points_t *points)
{
    if (points == NULL)
        return ;
    free(points);
}
