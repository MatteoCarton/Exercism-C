#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    if (arr == NULL || length <= 0)
        return (NULL);
    int minimum = 0;
    int maximum = (int)length;
    int middle = minimum + (maximum - minimum) / 2;

    while (minimum <= maximum)
    {
        if (arr[middle] == value)
            return (&arr[middle]);
        if (arr[middle] < value)
            minimum = middle + 1;
        else
            maximum = middle - 1;
        middle = minimum + (maximum - minimum) / 2;
    }

    return (NULL);
}
