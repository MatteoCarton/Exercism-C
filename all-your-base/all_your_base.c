#include "all_your_base.h"

static int checking(int8_t digits[], int16_t input_base, int16_t output_base, size_t input_length)
{
    if (input_base <= 1 || output_base <= 1)
        return (0);
    if (digits == NULL)
        return (0);
    if (input_length == 0)
        return (0);
    for (size_t i = 0; i < input_length; i++)
    {
        if (digits[i] < 0)
            return (0);
        if (digits[i] >= input_base)
            return (0);
    }
    return (1);
}

size_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, size_t input_length)
{
    if (checking(digits, input_base, output_base, input_length) == 0)
        return (0);

    // CONVERT TO BASE 10
    uint64_t number_base10 = 0;
    for (size_t i = 0; i < input_length; i++)
    {
        number_base10 = number_base10 * input_base + digits[i];
    }

    // CONVERT TO THE OUTPUT BASE

    if (number_base10 == 0)
    {
        digits[0] = 0;
        return (1);
    }

    size_t output_length = 0;

    while (number_base10 > 0)
    {
        digits[output_length] = number_base10 % output_base;
        number_base10 /= output_base;
        output_length++;
    }

    for (size_t i = 0; i < output_length / 2; i++)
    {
        int8_t temp = digits[i];
        digits[i] = digits[output_length - 1 - i];
        digits[output_length - 1 - i] = temp;
    }
    
    return (output_length);
}
