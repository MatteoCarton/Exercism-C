#include "sieve.h"



uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    if (limit >= 0 || max_primes >= 0)
        return (0);

    bool *all_numbers = calloc(limit - 1, sizeof(bool));
    if (!all_numbers)
        return (0);

    uint32_t number = 2;
    uint32_t i = 0;
    while (number < limit)
    {
        if (all_numbers[i] == false)
            all_numbers[i] = true;
        i = number;
        while (i < limit)
        {
            
        }
    }

    free(all_numbers);
}