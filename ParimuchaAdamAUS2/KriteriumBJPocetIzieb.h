#pragma once
#include "KriteriumBJ.h"
#include "ZoskupenieBJ.h"
class KriteriumBJTyp :
    public KriteriumBJ<int>
{
    int ohodnot(ZoskupenieBJ o) { return o.getPocetObMiestnosti(); };
};

