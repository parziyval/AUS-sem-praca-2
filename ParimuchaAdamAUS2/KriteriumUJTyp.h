#pragma once
#include "KriteriumUJ.h"
#include "EnumTypUJ.h"
class KriteriumUJTyp :
    public KriteriumUJ<EnumTypUJ>
{
    EnumTypUJ ohodnot(UzemnaJednotka& o) { return o.getTyp(); };
};

