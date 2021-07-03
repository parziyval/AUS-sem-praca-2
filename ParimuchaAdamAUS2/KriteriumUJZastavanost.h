#pragma once
#include "KriteriumUJ.h"
class KriteriumUJZastavanost :
    public KriteriumUJ<double>
{
    double ohodnot(UzemnaJednotka& o) { return o.getZastavanaPlocha() / o.getCelkovaVymera() * 100; };

};

