#include "Okres.h"

Okres::Okres(std::wstring nazov, int pocetPreProdObyv, int pocetProdObyv, int pocetPoProdObyv, double celkovaVymera, double zastavanaPlocha)
	:UzemnaJednotka()
{
	this->typ = EnumTypUJ::OKRES;
	this->nazov = nazov;
}


//void Okres::pridajDoNizsich(std::wstring nazov, UzemnaJednotka* uj)
//{
//	this->nizsieUJ->insert(nazov, uj);
//	this->pridajPocty(uj->getPocetPreProdObyv(), uj->getPocetProdObyv(),
//		uj->getPocetPoProdObyv(), uj->getCelkovaVymera(),
//		uj->getZastavanaPlocha());
//	nadradenaUJ->pridajPocty(uj->getPocetPreProdObyv(), uj->getPocetProdObyv(),
//							uj->getPocetPoProdObyv(),uj->getCelkovaVymera(),
//							uj->getZastavanaPlocha());
//}
