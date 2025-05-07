#include "binary.h"

int convert(const char *input)
{
    size_t length = strlen(input);
    size_t i = 0;

    while (i < length)
    {
        if (input[i] != '1' && input[i] != '0')
            return (INVALID);
        i++;
    }

    int number = 0;
    i = 0;

    while (i < length)
    {
        number = number * 2;
        if (input[i] == '1')
            number++;
        i++;
    }

    return (number);

}
