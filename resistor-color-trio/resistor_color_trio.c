#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t colors[])
{
	resistor_value_t code;
    uint16_t value = 0;

    uint16_t i = 0;
	while (i < 2)
	{
		switch (colors[i])
		{
		case BLACK:
			value = (value * 10) + 0;
			break ;
		case BROWN:
			value = (value * 10) + 1;
			break ;
		case RED:
			value = (value * 10) + 2;
			break ;
		case ORANGE:
			value = (value * 10) + 3;
			break ;
		case YELLOW:
			value = (value * 10) + 4;
			break ;
		case GREEN:
			value = (value * 10) + 5;
			break ;
		case BLUE:
			value = (value * 10) + 6;
			break ;
		case VIOLET:
			value = (value * 10) + 7;
			break ;
		case GREY:
			value = (value * 10) + 8;
			break ;
		case WHITE:
			value = (value * 10) + 9;
			break ;
		default:
			break ;
		}
        i++;
	}

	switch (colors[2])
	{
	case BLACK:
        code.unit = OHMS;
        code.value = value;
		break ;
	case BROWN:
		code.unit = OHMS;
        code.value = (value * pow(10, 1));
		break ;
	case RED:
		code.unit = KILOOHMS;
        code.value = (value * pow(10, -1));
		break ;
	case ORANGE:
		code.unit = KILOOHMS;
        code.value = value;
		break ;
	case YELLOW:
		code.unit = KILOOHMS;
        code.value = (value * pow(10, 1));
		break ;
	case GREEN:
		code.unit = MEGAOHMS;
        code.value = (value * pow(10, -1));
        break ;
	case BLUE:
		code.unit = MEGAOHMS;
        code.value = value;
		break ;
	case VIOLET:
		code.unit = MEGAOHMS;
        code.value = (value * pow(10, 1));
		break ;
	case GREY:
		code.unit = GIGAOHMS;
        code.value = (value * pow(10, -1));
		break ;
	case WHITE:
		code.unit = GIGAOHMS;
        code.value = value;
		break ;
	default:
		break ;
	}

	return (code);
}
