#include "resistor_color.h"

int color_code(resistor_band_t color)
{
    int code = 0;

    switch (color)
    {
    case BLACK:
        code = 0;
        break;
    case BROWN:
        code = 1;
        break;
    case RED:
        code = 2;
        break;
    case ORANGE:
        code = 3;
        break;
    case YELLOW:
        code = 4;
        break;
    case GREEN:
        code = 5;
        break;
    case BLUE:
        code = 6;
        break;
    case VIOLET:
        code = 7;
        break;
    case GREY:
        code = 8;
        break;
    case WHITE:
        code = 9;
        break;
    default:
        break;
    }

    return (code);
}

const resistor_band_t* colors(void)
{
    static const resistor_band_t colors[] = {
        BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
    };
    return colors;
}
