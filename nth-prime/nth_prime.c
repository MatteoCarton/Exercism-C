#include "nth_prime.h"

static bool is_prime(uint32_t i)
{
    uint32_t j = 2;
    while (j * j <= i)
    {
        if (i % j == 0)
            return (0) ;
        j++;
    }
    return (1);
}

uint32_t nth(uint32_t n)
{
    if (n == 0)
        return (0);
    uint32_t i = 2;
    uint32_t count = 0;

    while (count < n)
    {
        if (is_prime(i))
        {
            count++;
        }
        i++;
    }

    return (i - 1);
}
