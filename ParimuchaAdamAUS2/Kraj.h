#pragma once
#include "UzemnaJednotka.h"
#include "Okres.h"
#include "Stat.h"

class Kraj :
    public UzemnaJednotka
{
private:
public:
    Kraj(std::wstring nazov = L"", int pocetPreProdObyv = 0, int pocetProdObyv = 0, int pocetPoProdObyv = 0, double celkovaVymera = 0, double zastavanaPlocha = 0);


    //void pridajDoNizsich(std::wstring nazov, UzemnaJednotka* uj);
};

