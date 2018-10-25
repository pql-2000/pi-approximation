#include <iostream>
#include "PiApproximation.h"


int main(int argc, char *argv[])
{
    PiApproximation app(PiApproximation::RAMANUJAN);

    mp_exp_t exponent;

    std::string approximation = app.approximate(argc >= 2 ? std::atoi(argv[1]) : 7).get_str(exponent, 10, 1024*1000);

    std::cout << approximation[0] << '.' << &approximation[1] << std::endl;
}