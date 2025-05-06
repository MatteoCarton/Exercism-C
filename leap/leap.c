#include "leap.h"

bool leap_year(int year)
{
    int divBy4;
    int divBy100;
    int divBy400;

    divBy4 = year % 4;
    divBy100 = year % 100;
    divBy400 = year % 400;

    if (divBy4 == 0)
    {
        if ((divBy100 == 0) && (divBy400 == 0))
            return (true);
        else if ((divBy100 == 0) && (divBy400 != 0))
            return (false);
        else
            return (true);
    }
    else
        return (false);
}

/*
#include <stdio.h>
int main(void)
{
    printf("%d", leap_year(1900));

}
*/
