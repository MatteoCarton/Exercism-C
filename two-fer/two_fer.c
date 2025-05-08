#include "two_fer.h"

void two_fer(char *buffer, const char *name)
{
    char *str1 = "One for ";
    char *str2 = ", one for me.";
    int i = 0;
    int j = 0;

    // msg part 1
    while (str1[i] != '\0')
    {
        buffer[i] = str1[i];
        i++;
    }

    // name or not
    if (name == NULL)
    {
        buffer[i] = 'y';
        buffer[i + 1] = 'o';
        buffer[i + 2] = 'u';
        i = i + 3;
    }
    else
    {
        while (name[j] != '\0')
        {
            buffer[i] = name[j];
            j++;
            i++;
        }
        j = 0;
    }

    // msg part 2
    while (str2[j] != '\0')
    {
        buffer[i] = str2[j];
        j++;
        i++;
    }
    
    buffer[i] = '\0';
}
