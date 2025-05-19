#include "reverse_string.h"

char *reverse(const char *value)
{
    
    int i = 0;
    for (i = 0; value[i] != '\0'; i++);

    char *str_reverse = malloc(i + 1);
    if (!str_reverse)
        return (NULL);
    int j = 0;
    for (i--; i >= 0; i--)
    {
        str_reverse[j] = value[i];
        j++;
    }
    str_reverse[j] = '\0';
    return (str_reverse);
}
