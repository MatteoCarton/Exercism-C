#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key)
{
    if (text == NULL || shift_key < 0)
        return (NULL);
    char *new_str = malloc(strlen(text) + 1);
    if (new_str == NULL)
        return NULL;
    strcpy(new_str, text);
    if (new_str == NULL)
        return NULL;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
            new_str[i] = 'a' + ((text[i] - 'a' + shift_key) % 26);
        else if (text[i] >= 'A' && text[i] <= 'Z')
            new_str[i] = 'A' + ((text[i] - 'A' + shift_key) % 26);
        else
            new_str[i] = text[i];
    }
    return (new_str);
}
