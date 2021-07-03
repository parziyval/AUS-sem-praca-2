#pragma once
#include "EnumTypUJ.h"
#include "UzemnaJednotka.h"
#include "Okres.h"
class Obec :
	public UzemnaJednotka
{
private:
public:
	Obec(std::wstring nazov = L"", int pocetPreProdObyv = 0, int pocetProdObyv = 0, int pocetPoProdObyv = 0, double celkovaVymera = 0, double zastavanaPlocha = 0);

};

