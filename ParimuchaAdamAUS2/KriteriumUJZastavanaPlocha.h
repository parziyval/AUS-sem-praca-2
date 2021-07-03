#pragma once
#include "KriteriumUJ.h"
class KriteriumUJZastavanaPlocha :
    public KriteriumUJ<double>
{
    double ohodnot(UzemnaJednotka& o) { return o.getZastavanaPlocha(); };

};

