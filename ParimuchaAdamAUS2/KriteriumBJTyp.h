#pragma once
#include "KriteriumBJ.h"
#include <string>
#include "ZoskupenieBJ.h"
class KriteriumBJTyp :
    public KriteriumBJ<std::string>
{
    std::string ohodnot(ZoskupenieBJ o) { return o.getTyp(); };
};

