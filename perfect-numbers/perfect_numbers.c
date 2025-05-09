#include "perfect_numbers.h"

kind classify_number(int number)
{
    if (number <= 0)
        return (ERROR);
    int factors = 0;
    for (int i = 1; i < number; i++)
    {
        if ((number % i) == 0)
            factors += i;
    }

    
    if (factors > number)
        return (ABUNDANT_NUMBER);
    if (factors < number)
        return (DEFICIENT_NUMBER);
    else
        return (PERFECT_NUMBER);
}
