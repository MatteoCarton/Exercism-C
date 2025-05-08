#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int number)
{
    if (number <= 0)
        return (0);

    unsigned int count = 0;

    while (number != 0)
    {
        if ((number % 2 ) == 1)
            count += 1;
        number = number / 2;
    }
    
    return (count);
}
