#include "Obec.h"

Obec::Obec(std::wstring nazov, int pocetPreProdObyv, int pocetProdObyv, int pocetPoProdObyv, double celkovaVymera, double zastavanaPlocha)
	:UzemnaJednotka()
{
	this->typ = EnumTypUJ::OBEC;
	this->nazov = nazov;
	//this->nizsieUJ = nullptr; //pridane
}
