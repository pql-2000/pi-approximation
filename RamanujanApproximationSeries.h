#ifndef RAMANUJANAPPROXIMATIONSERIES_H
#define RAMANUJANAPPROXIMATIONSERIES_H

#include "AbstractPiApproximationSeries.h"

class RamanujanApproximationSeries : public AbstractPiApproximationSeries {
public:
    RamanujanApproximationSeries();
    ~RamanujanApproximationSeries();

    mpf_class approximate(mpz_class bound);
    mpf_class yield_approximation();
private:
    mpz_class index;
    mpf_class internal_approximation = 0;
    int starting_index = 0;

    mpz_class factorial_caches[2] = {1, 1};
    mpz_class exponential_caches[1] = {1};
};

#endif // RAMANUJANAPPROXIMATIONSERIES_H