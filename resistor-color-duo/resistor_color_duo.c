#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t color[2])
{
    uint16_t code = 0;

    int i = 0;

    while (i < 2)
    {
        switch (color[i])
        {
        case BLACK:
            code =  (code * 10) + 0;
            break;
        case BROWN:
            code = (code * 10) + 1;
            break;
        case RED:
            code = (code * 10) + 2;
            break;
        case ORANGE:
            code = (code * 10) + 3;
            break;
        case YELLOW:
            code = (code * 10) + 4;
            break;
        case GREEN:
            code = (code * 10) + 5;
            break;
        case BLUE:
            code = (code * 10) + 6;
            break;
        case VIOLET:
            code = (code * 10) + 7;
            break;
        case GREY:
            code = (code * 10) + 8;
            break;
        case WHITE:
            code = (code * 10) + 9;
            break;
        default:
            break;
        }
        i++;
    }

    return (code);
}
