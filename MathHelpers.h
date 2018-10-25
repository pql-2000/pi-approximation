#include <gmpxx.h>

namespace MathHelpers 
{
    /*
        Return factorial of n.
    */
    mpz_class fac(mpz_class n);

    /*
        Return n raised to the exponenth power.
    */
    mpz_class exp(mpz_class n, mpz_class exponent);
}