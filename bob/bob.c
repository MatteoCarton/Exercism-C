#include "bob.h"

static bool is_a_question(char *greeting)
{
    size_t len = 0;

    while (greeting[len])
        len++;
    
    while (len > 0 && isspace(greeting[len - 1]))
        len--;
    
    if (len > 0 && greeting[len - 1] == '?')
        return true; 
    return false;
}

static bool is_all_in_caps(char *greeting)
{
    bool at_leat_one = false;
    for (size_t i = 0; greeting[i]; i++)
    {
        if (greeting[i] >= 'A' && greeting[i] <= 'Z')
            at_leat_one = true;
        if (greeting[i] >= 'a' && greeting[i] <= 'z')
            return (false);
    }
    if (at_leat_one == false)
        return (false);
    return (true);
}

static bool silence(char *greeting)
{
    if (greeting == NULL)
        return (true);
    
    for (int i = 0; greeting[i]; i++)
    {
        if (!isspace(greeting[i]))
            return (false);
    }
    return (true);
}

char *hey_bob(char *greeting)
{
    if (silence(greeting))
        return ("Fine. Be that way!");
    
    if (is_all_in_caps(greeting) && is_a_question(greeting))
        return ("Calm down, I know what I'm doing!");
    
    if (is_all_in_caps(greeting))
        return ("Whoa, chill out!");
    
    if (is_a_question(greeting))
        return ("Sure.");
    return ("Whatever.");
}
