#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    uint64_t i = 2;
    size_t count = 0;

    while (n > 1)
    {
        if (n % i == 0)
        {
            factors[count] = i;
            count++;
            n /= i;
        }
        else
            i++;
    }

    return (count);
}
