#include "Kraj.h"

Kraj::Kraj(std::wstring nazov, int pocetPreProdObyv, int pocetProdObyv, int pocetPoProdObyv, double celkovaVymera, double zastavanaPlocha)
	:UzemnaJednotka()
{
	this->typ = EnumTypUJ::KRAJ;
	this->nazov = nazov;
}

//void Kraj::pridajDoNizsich(std::wstring nazov, UzemnaJednotka* uj)
//{
//	this->nizsieUJ->insert(nazov, uj);
//	this->pridajPocty(uj->getPocetPreProdObyv(), uj->getPocetProdObyv(),
//		uj->getPocetPoProdObyv(), uj->getCelkovaVymera(),
//		uj->getZastavanaPlocha());
//	nadradenaUJ->pridajPocty(uj->getPocetPreProdObyv(), uj->getPocetProdObyv(),
//		uj->getPocetPoProdObyv(), uj->getCelkovaVymera(),
//		uj->getZastavanaPlocha());
//}
