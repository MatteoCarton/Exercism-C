#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number)
{
    unsigned int i = 0;
    unsigned int result = 0;
    while (i <= number)
    {
        result = result + (i * i);
        i++;
    }

    return (result);
}

unsigned int square_of_sum(unsigned int number)
{
    unsigned int i = 0;
    unsigned int sum = 0;
    unsigned int result = 0;
    while (i <= number)
    {
        sum += i;
        i++;
    }
    result = sum * sum;
    return (result);
}

unsigned int difference_of_squares(unsigned int number)
{
    unsigned int result;

    result = square_of_sum(number) - sum_of_squares(number);

    return (result);
}

/* #include <stdio.h>
int main(void)
{
    printf("%d", difference_of_squares(10));

} */
