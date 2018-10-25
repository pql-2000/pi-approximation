#include "AbstractPiApproximationSeries.h"


void AbstractPiApproximationSeries::reset_state()
{
    this->internal_approximation = 0;
    this->index = this->starting_index;
}

AbstractPiApproximationSeries::AbstractPiApproximationSeries() 
{
    this->index = this->starting_index;
    this->internal_approximation.set_prec(1024*1000);
}
AbstractPiApproximationSeries::~AbstractPiApproximationSeries() {}