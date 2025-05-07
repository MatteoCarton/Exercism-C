#include "hamming.h"

static int ft_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int compute(const char *lhs, const char *rhs)
{
    if (ft_strlen(lhs) != ft_strlen(rhs))
        return (-1);

    int length = ft_strlen(lhs);
    int difference = 0;
    int i = 0;
    while (i < length)
    {
        if (lhs[i] != rhs[i])
            difference++;
        i++;
    }
    return (difference);
}
