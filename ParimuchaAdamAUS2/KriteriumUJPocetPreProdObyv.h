#pragma once
#include "KriteriumUJ.h"
class KriteriumUJPocetPreProdObyv :
    public KriteriumUJ<int>
{
    int ohodnot(UzemnaJednotka& o) { return o.getPocetPreProdObyv(); };
};

