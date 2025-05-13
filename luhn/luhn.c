#include "luhn.h"


bool luhn(const char *num)
{
    if (num == NULL)
        return (false);
    size_t length = strlen(num);
    if (length <= 1)
        return (false);
    
    char *num_without_space = malloc(length + 1);
    int j = 0;
    for (int i = 0; i < (int)length; i++)
    {
        if ((num[i] < '0' || num[i] > '9') && num[i] != ' ')
            return (free(num_without_space), false);
        while (i < (int)length && num[i] == ' ')
            i++;
        if (i < (int)length)
        {
            num_without_space[j] = num[i];
            j++;
        }
    }
    num_without_space[j] = '\0';
    
    size_t clean_length = strlen(num_without_space);
    if (clean_length <= 1)
        return (free(num_without_space), false);
    
    int total = 0;
    int digit;
    bool is_second = false;
    
    // Parcourir de droite à gauche
    for (j = clean_length - 1; j >= 0; j--)
    {
        digit = num_without_space[j] - '0';
        
        // Doubler chaque second chiffre
        if (is_second == true)
        {
            digit *= 2;
            // Si > 9, soustraire 9
            if (digit > 9)
                digit -= 9;
        }
        
        total += digit;
        is_second = !is_second;
    }
    
    return (free(num_without_space), (total % 10 == 0));
}
