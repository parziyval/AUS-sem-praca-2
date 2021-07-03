#pragma once
#include "KriteriumUJ.h"
class KriteriumUJPocetObyv :
    public KriteriumUJ<int>
{
    int ohodnot(UzemnaJednotka& o) { return o.getPocetPreProdObyv() + o.getPocetProdObyv() + o.getPocetPoProdObyv(); };
};

