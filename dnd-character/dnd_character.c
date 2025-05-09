#include "dnd_character.h"

int ability(void)
{
    int i = 0;
    int resultat[4];
    int minimum = 7;
    int total = 0;

    while (i < 4)
    {
        resultat[i] = 1 + rand() % 6;
        if (resultat[i] < minimum)
            minimum = resultat[i];
        i++;
    }

    for(int j = 0; j < 4; j++)
        total += resultat[j];
    
    total = total - minimum;

    return (total);
}


int modifier(int score)
{
    int total = floor((score - 10) / 2.0);
    return (total);
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t character;
    srand(time(NULL));

    for(int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            character.strength = ability();
            break;
        case 1:
            character.dexterity = ability();
            break;
        case 2:
            character.constitution = ability();
            break;
        case 3:
            character.intelligence = ability();
            break;
        case 4:
            character.wisdom = ability();
            break;
        case 5:
            character.charisma = ability();
            break;
        default:
            break;
        }
    }
    character.hitpoints = 10 + modifier(character.constitution);

    return (character);
}
