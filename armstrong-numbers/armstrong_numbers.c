#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate)
{
    double total = 0;
    int i = candidate;
    int number_of_digits = 0;
    
    while (i > 0)
    {
        i = i / 10;
        number_of_digits++;
    }

    i = candidate;

    for (double j = 0; j < number_of_digits; j++)
    {
        total += pow((i % 10), number_of_digits);
        i = i / 10;
    }

    if ((int)total == candidate)
        return (true);
    return (false);
}
