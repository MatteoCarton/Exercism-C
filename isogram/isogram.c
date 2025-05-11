#include "isogram.h"

bool is_isogram(const char phrase[])
{
    if (phrase == NULL)
        return (false);
    size_t length = strlen(phrase);
    bool letters[26] = {false};

    size_t i = 0;
    while (i < length)
    {
        if (phrase[i] >= 'A' && phrase[i] <= 'Z')
        {
            int lower_case = tolower(phrase[i]);
            if (letters[lower_case - 97] == false)
                letters[lower_case - 97] = true;
            else
                return (false);
        }
        if (phrase[i] >= 'a' && phrase[i] <= 'z')
        {
            if (letters[phrase[i] - 97] == false)
                letters[phrase[i] - 97] = true;
            else
                return (false);
        }
        i++;
    }
    return (true);
}
