#pragma once
#include "KriteriumUJ.h"
class KriteriumUJPocetProdObyv:
    public KriteriumUJ<int>
{
    int ohodnot(UzemnaJednotka& o) { return o.getPocetProdObyv(); };
};

