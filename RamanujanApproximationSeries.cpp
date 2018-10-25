#include "RamanujanApproximationSeries.h"
#include "MathHelpers.h"

#include <iostream>

RamanujanApproximationSeries::RamanujanApproximationSeries() 
    : AbstractPiApproximationSeries() 
{}

RamanujanApproximationSeries::~RamanujanApproximationSeries() {}


mpf_class RamanujanApproximationSeries::yield_approximation()
{
    return 1.0 / (this->internal_approximation * (2 * sqrt(mpf_class(2, 1024*1000))/9801.0));
}

mpf_class RamanujanApproximationSeries::approximate(mpz_class bound)
{
    mpf_class current_approximation = this->internal_approximation;

    for(mpz_class k = this->index; k < this->index + bound; ++k)
    {
        if(k > 0)
        {

            for(int i = 0; i < 4; ++i)
            {
                this->factorial_caches[0] *= (k*4 - i);
            }
            this->exponential_caches[0] *= 24591257856; // 396**4
            this->factorial_caches[1] *= k;

        }
        mpf_class evaluated_at_k(mpf_class(this->factorial_caches[0] * (1103 + 26390 * k), 1024*1000) / 
                                 mpf_class(MathHelpers::exp(this->factorial_caches[0], 4) * this->exponential_caches[0], 1024*1000), 1024*1000);

        current_approximation += evaluated_at_k;
            
        //std::cout << this->exponential_caches[0] << std::endl;
    }
    this->internal_approximation = current_approximation;
    return this->yield_approximation();
}