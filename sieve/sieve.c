#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    if (limit < 1)
        return (0);

    bool *all_numbers = calloc(limit + 1, sizeof(bool));
    if (!all_numbers)
        return (0);

    uint32_t number = 2;
    uint32_t i = number;
    uint32_t count = 0;
    while (number <= limit)
    {
       if (all_numbers[number] == false && count < max_primes)
        {
            primes[count] = number;
            count++;
            i = number;
            while (i <= limit)
            {
                i = i + number;
                if (i <= limit)
                    all_numbers[i] = true;
            }
        }
        number++;
    }
    free(all_numbers);
    return (count);
}
