#include "clock.h"

clock_t clock_create(int hour, int minute)
{
    clock_t clock;
    // HOURS
    if (hour < 0)
    {
        while (hour < 0)
            hour += 24;
    }
    if (hour > 24)
        hour = hour % 24;
    // MINUTES
    if (minute < 0)
    {
        while (minute < 0)
            minute += 60;
    }
    if (minute > 24)
        minute = minute % 60;
    sprintf(clock.text, "%02d:%02d", hour, minute);
    // %02d signifie :
    // - 0 : remplir avec des zéros
    // - 2 : largeur minimale de 2 caractères
    // - d : nombre décimal
    return (clock);
}

clock_t clock_add(clock_t clock, int minute_add)
{
    
}