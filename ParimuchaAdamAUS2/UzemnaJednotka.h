#pragma once
#include <iostream>
#include <iomanip>
#include "EnumTypUJ.h"
#include "sorted_sequence_table.h"
class UzemnaJednotka
{
protected:
	EnumTypUJ typ;
	std::wstring nazov;
	int pocetPreProdObyv;
	int pocetProdObyv;
	int pocetPoProdObyv;
	double celkovaVymera;
	double zastavanaPlocha;

	UzemnaJednotka* nadradenaUJ;
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* nizsieUJ;

public:
	UzemnaJednotka();
	virtual ~UzemnaJednotka();

	EnumTypUJ getTyp() { return this->typ; };
	std::wstring getNazov() { return this->nazov; };
	int getPocetObyv() { return this->pocetPreProdObyv + this->pocetProdObyv + this->pocetPoProdObyv; };
	int getPocetPreProdObyv() { return this->pocetPreProdObyv; };
	int getPocetProdObyv() { return this->pocetProdObyv; };
	int getPocetPoProdObyv() { return this->pocetPoProdObyv; };
	double getCelkovaVymera() { return this->celkovaVymera; };
	double getZastavanaPlocha() { return this->zastavanaPlocha; };
	double getZastavanost() { return this->zastavanaPlocha / this->celkovaVymera * 100; };
	UzemnaJednotka* getNadradenaUJ() { return this->nadradenaUJ; };
	
	void setNadradenaUJ(UzemnaJednotka* uj);

	void pridajDoNizsich(std::wstring nazov,UzemnaJednotka* uj);
	void pridajPocty(int pocetPreProdObyv, int pocetProdObyv, int pocetPoProdObyv, double celkovaVymera, double zastavanaPlocha);
	bool patriDoVyssej(std::wstring nazovVyssej);

	void vypis();
};

