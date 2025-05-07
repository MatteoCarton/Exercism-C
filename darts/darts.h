#ifndef DARTS_H
#define DARTS_H

#include <math.h>

typedef struct coordinate_s {
    float x;
    float y;
}   coordinate_t;

int score(coordinate_t landing_position);

#endif
