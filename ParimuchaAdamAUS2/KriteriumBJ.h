#pragma once
#include "Kriterium.h"
#include "ZoskupenieBJ.h"
template<typename T>
class KriteriumBJ :
    public Kriterium<T,ZoskupenieBJ>
{
    virtual T ohodnot(ZoskupenieBJ o) = 0;
};

