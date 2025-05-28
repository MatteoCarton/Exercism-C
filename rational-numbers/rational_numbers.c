#include "rational_numbers.h"
#include <math.h>

static int16_t gcd(int16_t a, int16_t b)
{
    
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    
    while (b != 0)
    {
        int16_t temp = b;
        b = a % b;
        a = temp;
    }
    return (a);
}

rational_t reduce(rational_t r)
{
    int nbr = gcd(r.numerator, r.denominator);

    r.numerator /= nbr;
    r.denominator /= nbr;

    if (r.denominator < 0)
    {
        r.numerator *= -1;
        r.denominator *= -1;
    }
    return (r);
}

rational_t add(rational_t r1, rational_t r2)
{
    rational_t result;

    result.numerator = (r1.numerator * r2.denominator) + (r1.denominator * r2.numerator);
    result.denominator = r1.denominator * r2.denominator;

    return (reduce(result));
}

rational_t subtract(rational_t r1, rational_t r2)
{
    rational_t result;

    result.numerator = (r1.numerator * r2.denominator) - (r1.denominator * r2.numerator);
    result.denominator = r1.denominator * r2.denominator;

    return (reduce(result));
}

rational_t multiply(rational_t r1, rational_t r2)
{
    rational_t result;

    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;

    return (reduce(result));
}

rational_t divide(rational_t r1, rational_t r2)
{
    rational_t result;

    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r2.numerator * r1.denominator;

    return (reduce(result));
}

rational_t absolute(rational_t r)
{
    if (r.numerator < 0)
        r.numerator = -r.numerator;
    if (r.denominator < 0)
        r.denominator = -r.denominator;
    
    return (reduce(r));
}

rational_t exp_rational(rational_t r, int16_t n)
{
    if (n == 0)
    {
        r.numerator = 1;
        r.denominator = 1;
        return (r);
    }
    if (r.numerator == 0 && r.denominator == 1)
        return (r);
    if (r.numerator == 1 && r.denominator == 1)
        return (r);

    int16_t original_num = r.numerator;
    int16_t original_den = r.denominator;

    if (n < 0)
    {
        int16_t temp = original_num;
        original_num = original_den;
        original_den = temp;
        n = -n;
    }

    r.numerator = original_num;
    r.denominator = original_den;

    for (int i = 1; i < n; i++)
    {
        r.numerator *= original_num;
        r.denominator *= original_den;
    }

    return (reduce(r));
}

float exp_real(uint16_t x, rational_t r)
{
    double base = (double)x;
    
    double power = pow(base, r.numerator);
    
    return pow(power, 1.0 / r.denominator);
}
