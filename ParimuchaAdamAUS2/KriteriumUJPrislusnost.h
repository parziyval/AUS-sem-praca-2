#pragma once
#include "KriteriumUJ.h"
class KriteriumUJPrislusnost :
    public KriteriumUJ<bool>
{
private:
    //UzemnaJednotka* vyssiaUJ;
    std::wstring nazovVyssejUJ;
public:
    //void setVyssiaUJ(UzemnaJednotka* vyssiaUJ) { this->vyssiaUJ = vyssiaUJ; };
    void setVyssiaUJ(std::wstring nazovVyssejUJ) { this->nazovVyssejUJ = nazovVyssejUJ; };
    bool ohodnot(UzemnaJednotka& o) 
    {
        return o.patriDoVyssej(this->nazovVyssejUJ);
    };
};

