#pragma once
#include "KriteriumBJ.h"
#include "UzemnaJednotka.h"
#include "ZoskupenieBJ.h"
class KriteriumBJPocet :
    public KriteriumBJ<int>
{
private:
    UzemnaJednotka uj;
public:
    void setUJ(UzemnaJednotka uj);
    int ohodnot(ZoskupenieBJ o);
};

