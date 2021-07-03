#pragma once
#include "UzemnaJednotka.h"
#include "Obec.h"
#include "Kraj.h"
class Okres :
    public UzemnaJednotka
{
private:

public:
	Okres(std::wstring nazov = L"", int pocetPreProdObyv = 0, int pocetProdObyv = 0, int pocetPoProdObyv = 0, double celkovaVymera = 0, double zastavanaPlocha = 0);


	//void pridajDoNizsich(std::wstring nazov, UzemnaJednotka* uj);
};

