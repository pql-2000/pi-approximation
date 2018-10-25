#include <gmpxx.h>
#include <cmath>

#ifndef ABSTRACTPIAPPROXIMATIONSERIES_H
#define ABSTRACTPIAPPROXIMATIONSERIES_H

class AbstractPiApproximationSeries {

public:

    AbstractPiApproximationSeries();
    ~AbstractPiApproximationSeries();

    /*
        Approximate PI with an infinite series, from this->index to this->index + bound

    */
    virtual mpf_class approximate(mpz_class bound) = 0;

    /*
        Reset index and approximation
    */
    void reset_state();

    /*
        this->approximation getter
    */
    virtual mpf_class yield_approximation() = 0;
private:
    mpz_class index;
    mpf_class internal_approximation;

    int starting_index = 0;
    
};


#endif // ABSTRACTPIAPPROXIMATIONSERIES_H