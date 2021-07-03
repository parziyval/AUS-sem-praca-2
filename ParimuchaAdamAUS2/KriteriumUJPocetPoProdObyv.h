#pragma once
#include "KriteriumUJ.h"
class KriteriumUJPocetPoProdObyv :
    public KriteriumUJ<int>
{
    int ohodnot(UzemnaJednotka& o) { return o.getPocetPoProdObyv(); };
};

