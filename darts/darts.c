#include "darts.h"

int score(coordinate_t landing_position)
{
    float distance = 0;
    float x_squared = landing_position.x * landing_position.x;
    float y_squared = landing_position.y * landing_position.y;

    // distance = √(x² + y²)
    distance = sqrtf(x_squared + y_squared);

    if (distance <= 1)
        return (10);
    if (distance <= 5)
        return (5);
    if (distance <= 10)
        return (1);
    return (0);
}
