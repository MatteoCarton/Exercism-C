#include "space_age.h"

float age(planet_t planet, int64_t seconds)
{
    int64_t oneYear = 31557600;

    // Earth-years
    float age = seconds / oneYear;

    switch (planet)
    {
    case MERCURY:
        age = age / 0.2408467;
        break;
    case VENUS:
        age = age / 0.61519726;
        break;
    case EARTH:
        age = age / 1;
        break;
    case MARS:
        age = age / 1.8808158;
        break;
    case JUPITER:
        age = age / 11.862615;
        break;
    case SATURN:
        age = age / 29.447498;
        break;
    case URANUS:
        age = age / 84.016846;
        break;
    case NEPTUNE:
        age = age / 164.79132;
        break;
    default:
        age = -1;
        break;
    }

    return (age);
}
