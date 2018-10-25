#include "PiApproximation.h"

#include "RamanujanApproximationSeries.h"

PiApproximation::PiApproximation(ApproximationType t)
{
    this->type = t;
    

    switch(t)
    {
        case RAMANUJAN:
            this->series = new RamanujanApproximationSeries();
            break;
        case CHUDNOVSKY:
            throw std::invalid_argument("Not yet implemented.");
            break;
    }
}

PiApproximation::~PiApproximation()
{
    delete this->series;
}

mpf_class PiApproximation::approximate(mpz_class bound)
{
    return this->series->approximate(bound);
}