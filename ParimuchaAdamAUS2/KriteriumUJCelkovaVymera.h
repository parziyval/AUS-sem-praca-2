#pragma once
#include "KriteriumUJ.h"
class KriteriumUJCelkovaVymera :
    public KriteriumUJ<double>
{
    double ohodnot(UzemnaJednotka& o) { return o.getCelkovaVymera(); };
};

