#include "clock.h"

clock_t clock_create(int hour, int minute)
{
    clock_t clock;
    
    while (minute < 0)
    {
         minute = minute + 60;
         hour = hour - 1;
    }
       

    if (minute >= 60)
    {
        hour = hour + (minute / 60);
        minute = minute % 60;
    }

    while (hour < 0)
        hour = hour + 24;
    if (hour >= 24)
        hour = hour % 24;

    sprintf(clock.text, "%02d:%02d", hour, minute);
    return (clock);
}

clock_t clock_add(clock_t clock, int minute_add)
{
    int actual_hour = 0;
    int actual_minute = 0;

    sscanf(clock.text, "%d:%d", &actual_hour, &actual_minute);

    int total_minute = (actual_hour * 60) + actual_minute + minute_add;
    while (total_minute < 0)
        total_minute = total_minute + (24 * 60);
    actual_hour = total_minute / 60;
    actual_minute = total_minute % 60;
    return (clock_create(actual_hour, actual_minute));
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    return (clock_add(clock, -minute_subtract));
}

bool clock_is_equal(clock_t a, clock_t b)
{
    int hour_a, hour_b;
    int minute_a, minute_b;

    sscanf(a.text, "%d:%d", &hour_a, &minute_a);
    sscanf(b.text, "%d:%d", &hour_b, &minute_b);

    if (hour_a == hour_b && minute_a == minute_b)
        return (true);
    return (false);
}
