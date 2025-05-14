#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
   complex_t result;

   result.real = a.real + b.real;
   result.imag = a.imag + b.imag;

   return (result);
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t result;

   result.real = a.real - b.real;
   result.imag = a.imag - b.imag;

   return (result);
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t result;

   result.real = (a.real * b.real) - (a.imag * b.imag);
   result.imag = (a.imag * b.real) + (a.real * b.imag);

   return (result);
}

complex_t c_div(complex_t a, complex_t b)
{
   complex_t result;

   double denominator = b.real * b.real + b.imag * b.imag;
   result.real = (a.real * b.real + a.imag * b.imag) / denominator;
   result.imag = (a.imag * b.real - a.real * b.imag) / denominator;

   return (result);
}

double c_abs(complex_t x)
{
   double result;
   
   result = sqrt(pow(x.real, 2) + pow(x.imag, 2));

   return (result);
}

complex_t c_conjugate(complex_t x)
{
   complex_t result;

   result.real = x.real;
   result.imag = -(x.imag);

   return (result);
}

double c_real(complex_t x)
{
   return (x.real);
}

double c_imag(complex_t x)
{
   return (x.imag);
}

complex_t c_exp(complex_t x)
{
   complex_t result;

   double e_to_real = exp(x.real);
   result.real = e_to_real * cos(x.imag);
   result.imag = e_to_real * sin(x.imag);

   return (result);
}
