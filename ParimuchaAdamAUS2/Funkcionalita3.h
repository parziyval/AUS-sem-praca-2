#pragma once
#include <iostream>
#include "ZlozenyFilter.h"
#include "Filter.h"
#include "UzemnaJednotka.h"
#include "FilterPodlaHodnoty.h"
#include "FilterPodlaIntervalu.h"
#include "Kriterium.h"
#include "KriteriumUJTyp.h"
#include "KriteriumUJPrislusnost.h"
#include "KriteriumUJNazov.h"
#include "KriteriumUJPocetObyv.h"
#include "KriteriumUJZastavanost.h"
#include "Stat.h"
class Funkcionalita3
{
public:
	Funkcionalita3();
	~Funkcionalita3();

	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* vratTabulkuPodlaTypu(Stat& stat);
	Filter<std::wstring, UzemnaJednotka, bool>* vratFilterPrislusnost();
	Filter<std::wstring, UzemnaJednotka, std::wstring>* vratFilterNazov();
	Filter<std::wstring, UzemnaJednotka, int>* vratFilterPocetObyv();
	Filter<std::wstring, UzemnaJednotka, double>* vratFilterZastavanost();
	bool zistiFilterPodlaNazvu(structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>*& vstupnaTab, UzemnaJednotka*& data, Stat* stat, bool filtrovaniePodlaTypu);

	void vypisTabulku(structures::SequenceTable< std::wstring, UzemnaJednotka*>* tabulka);
	void vypisHlavicku();
	void vyfiltrujAVypisJednotku(UzemnaJednotka* hladana, ZlozenyFilter<UzemnaJednotka>& fZlozeny);
	void spusti();
};

