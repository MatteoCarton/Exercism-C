#include "square_root.h"

int square_root(int number)
{
    int i = 0;

    while (i <= number)
    {
        if (i * i == number)
            return (number / i);
        i++;
    }
    return (0);
}
