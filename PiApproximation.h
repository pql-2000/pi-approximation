#ifndef APPROXIMATE_H
#define APPROXIMATE_H

#include "AbstractPiApproximationSeries.h"

class PiApproximation {
public:
    enum ApproximationType { RAMANUJAN, CHUDNOVSKY};

    PiApproximation(ApproximationType t);
    ~PiApproximation();

    mpf_class approximate(mpz_class bound = 1000000);

    AbstractPiApproximationSeries *yield_series() { return this->series; }    
private:
    ApproximationType type;
    AbstractPiApproximationSeries *series;

};

#endif // APPROXIMATE_H