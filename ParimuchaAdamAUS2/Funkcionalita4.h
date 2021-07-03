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
#include "Triedenie.h"


class Funkcionalita4
{
public:
	Funkcionalita4();
	~Funkcionalita4();

	structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* vratTabulkuPodlaTypu(Stat& stat);
	Filter<std::wstring, UzemnaJednotka, bool>* vratFilterPrislusnost();

	int zistiAkeTriedenie();
	bool zistiCiVzostupne();

	void vypisTabulku(structures::SequenceTable< std::wstring, UzemnaJednotka*>* tabulka);
	void vypisTabulkuNazov(structures::SequenceTable< std::wstring, UzemnaJednotka*>* tabulka);
	void vypisTabulkuPocetObyv(structures::SequenceTable< std::wstring, UzemnaJednotka*>* tabulka);
	void vypisTabulkuZastavanost(structures::SequenceTable< std::wstring, UzemnaJednotka*>* tabulka);

	void vypisHlavicku();
	void utriedVsetkoPodlaNazvu(bool& vzostupne, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obceUtriedovana);
	void utriedVsetkoPodlaZastavanosti(bool& vzostupne, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obceUtriedovana);
	void utriedVsetkoPodlaPocetObyv(bool& vzostupne, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obceUtriedovana);
	void spusti();
};

