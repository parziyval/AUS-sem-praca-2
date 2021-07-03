#pragma once
#include "KriteriumUJ.h"
class KriteriumUJNazov :
    public KriteriumUJ<std::wstring>
{
    std::wstring ohodnot(UzemnaJednotka& o) { return o.getNazov(); };
};

