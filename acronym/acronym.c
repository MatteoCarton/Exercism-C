#include "acronym.h"

char *abbreviate(const char *phrase)
{
    if (phrase == NULL || phrase[0] == '\0')
        return (NULL);
    
    char *tla = malloc(sizeof(char) * (strlen(phrase) + 1));
    if (!tla)
        return (NULL);
    int j = 0;
    for (int i = 0; phrase[i] != '\0'; i++)
    {
        if (i == 0 || phrase[i-1] == ' ' || phrase[i-1] == '-' || phrase[i-1] == '_') 
        {
            if (isalpha(phrase[i])) 
                tla[j++] = toupper(phrase[i]);
        }
    }
    tla[j] = '\0';
    return (tla);
}
