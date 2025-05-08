#include "raindrops.h"

void convert(char result[], int drops)
{
    char *divBy3 = "Pling";
    char *divBy5 = "Plang";
    char *divBy7 = "Plong";
    int i = 0;
    int j = 0;

    if (drops % 3 == 0)
    {
        while (divBy3[j] != '\0')
        {
            result[i] = divBy3[j];
            i++;
            j++;
        }
        j = 0;
    }
    if (drops % 5 == 0)
    {
        while (divBy5[j] != '\0')
        {
            result[i] = divBy5[j];
            i++;
            j++;
        }
        j = 0;
    }
    if (drops % 7 == 0)
    {
        while (divBy7[j] != '\0')
        {
            result[i] = divBy7[j];
            i++;
            j++;
        }
        j = 0;
    }
    if (drops % 3 != 0 && drops % 5 != 0 && drops % 7 != 0)
        i = i + sprintf(&result[i], "%d", drops);

    result[i] = '\0';
}
