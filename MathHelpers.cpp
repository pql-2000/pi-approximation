#include <iostream>
#include "MathHelpers.h"

mpz_class MathHelpers::fac(mpz_class n)
{
    if(n == 0) return 1;

    mpz_class result = 1;

    for(mpz_class i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

mpz_class MathHelpers::exp(mpz_class n, mpz_class exponent)
{
    for(; exponent--; n *= n);
    return n;
}