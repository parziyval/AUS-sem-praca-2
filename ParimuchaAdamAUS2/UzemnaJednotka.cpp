#include "UzemnaJednotka.h"

UzemnaJednotka::UzemnaJednotka()
{
	this->nadradenaUJ = nullptr;
	this->nizsieUJ = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>;

	this->pocetPreProdObyv = 0;
	this->pocetProdObyv = 0;
	this->pocetPoProdObyv = 0;
	this->celkovaVymera = 0;
	this->zastavanaPlocha = 0;
}

UzemnaJednotka::~UzemnaJednotka()
{
	delete this->nizsieUJ;
	this->nizsieUJ = nullptr;
}

void UzemnaJednotka::setNadradenaUJ(UzemnaJednotka* uj)
{
	this->nadradenaUJ = uj;
}

void UzemnaJednotka::pridajDoNizsich(std::wstring nazov, UzemnaJednotka* uj)
{
	if (this->nizsieUJ != nullptr) //toto je osetrenie keby niekto nahodou chcel pridavat nizsiu jednotku do obce
	{
		this->nizsieUJ->insert(nazov, uj);
		this->pridajPocty(uj->getPocetPreProdObyv(), uj->getPocetProdObyv(),
			uj->getPocetPoProdObyv(), uj->getCelkovaVymera(), uj->getZastavanaPlocha());
	}

	UzemnaJednotka* aktualnaVyssiaUJ = this->nadradenaUJ;
	while (aktualnaVyssiaUJ != nullptr)
	{
		aktualnaVyssiaUJ->pridajPocty(uj->getPocetPreProdObyv(), uj->getPocetProdObyv(),
			uj->getPocetPoProdObyv(), uj->getCelkovaVymera(), uj->getZastavanaPlocha());
		aktualnaVyssiaUJ = aktualnaVyssiaUJ->getNadradenaUJ();
	}

	//if (this->nadradenaUJ != nullptr)
	//{
	//	nadradenaUJ->pridajPocty(uj->getPocetPreProdObyv(), uj->getPocetProdObyv(),
	//		uj->getPocetPoProdObyv(), uj->getCelkovaVymera(),
	//		uj->getZastavanaPlocha());
	//}
}

void UzemnaJednotka::pridajPocty(int p_pocetPreProdObyv, int p_pocetProdObyv, int p_pocetPoProdObyv, double p_celkovaVymera, double p_zastavanaPlocha)
{
	this->pocetPreProdObyv += p_pocetPreProdObyv;
	this->pocetProdObyv += p_pocetProdObyv;
	this->pocetPoProdObyv += p_pocetPoProdObyv;
	this->celkovaVymera += p_celkovaVymera;
	this->zastavanaPlocha += p_zastavanaPlocha;
}

bool UzemnaJednotka::patriDoVyssej(std::wstring nazovVyssej) 
{
	if (this->nadradenaUJ == nullptr)
	{
		return false;
	}
	else if(this->nadradenaUJ->getNazov() == nazovVyssej)
	{
		return true;
	}
	else
	{
		return this->nadradenaUJ->patriDoVyssej(nazovVyssej);
	}
}

void UzemnaJednotka::vypis()
{
	UzemnaJednotka* aktualnaVyssiaUJ = nadradenaUJ;
	std::wstring nadradeneStr = L"";
	while (aktualnaVyssiaUJ != nullptr)
	{
		nadradeneStr = aktualnaVyssiaUJ->getNazov() + L", " + nadradeneStr;
		aktualnaVyssiaUJ = aktualnaVyssiaUJ->getNadradenaUJ();
	}
	//std::wcout << nadradeneStr << this->nazov << L" " << this->getPocetObyv() << L" " << this->pocetPreProdObyv << L" " << this->pocetProdObyv
	//	<< L" " << this->pocetPoProdObyv << L" " << this->getZastavanost() << L"% " << this->celkovaVymera << L" " << this->zastavanaPlocha;

	std::wcout << nadradeneStr << std::setw(30) << this->nazov << std::setw(10) << this->getPocetObyv() << std::setw(8) << this->pocetPreProdObyv <<
		std::setw(8) << this->pocetProdObyv << std::setw(8) << this->pocetPoProdObyv << std::setw(8) << std::setprecision(2)
		<< this->getZastavanost() << L"% " << std::setw(20) << std::to_wstring(this->celkovaVymera) << std::setw(20) << std::to_wstring(this->zastavanaPlocha);
}
