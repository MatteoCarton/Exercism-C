#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
    if (number_of_factors == 0)
        return (0);

    unsigned int result = 0;
    unsigned int i = 0;
    unsigned int j = 0;

    for (i = 1; i < limit; i++)
    {
        for (j = 0; j < number_of_factors; j++)
    {
            if (factors[j] != 0 && i % factors[j] == 0)
        {
                result += i;
                break;
            }
        }
        }

    return result;
    }
