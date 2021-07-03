#include "Funkcionalita3.h"

#define MOZNOST_KRAJ 1
#define MOZNOST_OKRES 2
#define MOZNOST_OBEC 3 
#define MOZNOST_STAT 4 

Funkcionalita3::Funkcionalita3()
{
}

Funkcionalita3::~Funkcionalita3()
{
}

structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* Funkcionalita3::vratTabulkuPodlaTypu(Stat& stat) 
{
	bool koniec = false;
	wchar_t moznost;
	std::wcout << L"Chcete filtrovat podla typu? (ak nie, bude sa filtrovat pre cely stat) [Y/N]: ";
	std::wcin >> moznost;
	if (moznost == 'Y' || moznost == 'y')
	{
		structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* vratena = nullptr;
		while (!koniec)
		{
			std::wcout << L"Zadajte cislo prislusneho typu\n1 - Kraj\n2 - Okres\n3 - Obec\n";
			std::wstring moznostTypStr;

			std::wcin >> moznostTypStr;
			switch (stoi(moznostTypStr))
			{
			case MOZNOST_KRAJ:
				vratena = stat.getTabKrajov();
				koniec = true;
				break;
			case MOZNOST_OKRES:
				vratena = stat.getTabOkresov();
				koniec = true;
				break;
			case MOZNOST_OBEC:
				vratena = stat.getTabObci();
				koniec = true;
				break;
			case MOZNOST_STAT:
				koniec = true;
				break;
			default:
				std::wcout << L"Zadajte platnu moznost: ";
				break;
			}
		}
		return vratena;
	}
	else
	{
		return nullptr;
	}
}

Filter<std::wstring, UzemnaJednotka, bool>* Funkcionalita3::vratFilterPrislusnost()
{
	wchar_t moznost;

	std::wcout << L"Chcete filtrovat podla prislusnosti? [Y/N]: ";
	std::wcin >> moznost;
	std::wcin.ignore();
	if (moznost == 'Y' || moznost == 'y')
	{
		std::wcout << L"Zadajte prislusnost jednotky\n(pre kraje napr. Banskobystrický, pre okresy napr. Okres Levoča): ";
		std::wstring nazovVyssejUJ;
		std::getline(std::wcin, nazovVyssejUJ);

		KriteriumUJPrislusnost* kPrisl = new KriteriumUJPrislusnost();
		kPrisl->setVyssiaUJ(nazovVyssejUJ);

		return new FilterPodlaHodnoty<std::wstring, UzemnaJednotka, bool>(kPrisl, true);
	}
	else
	{
		return nullptr;
	}
}

Filter<std::wstring, UzemnaJednotka, std::wstring>* Funkcionalita3::vratFilterNazov()
{
	wchar_t moznost;
	std::wcout << L"Chcete filtrovat podla nazvu? [Y/N]: ";
	std::wcin >> moznost;
	std::wcin.ignore();
	if (moznost == 'Y' || moznost == 'y')
	{
		std::wcout << L"Zadajte nazov hladanej jednotky: ";
		std::wstring nazovHladanejUJ;
		std::getline(std::wcin, nazovHladanejUJ);

		KriteriumUJNazov* kNazov = new KriteriumUJNazov();

		return new FilterPodlaHodnoty<std::wstring, UzemnaJednotka, std::wstring>(kNazov, nazovHladanejUJ);
	}
	else
	{
		return nullptr;
	}
}

Filter<std::wstring, UzemnaJednotka, int>* Funkcionalita3::vratFilterPocetObyv()
{
	wchar_t moznost;
	std::wcout << L"Chcete filtrovat podla poctu obyvatelov? [Y/N]: ";
	std::wcin >> moznost;
	std::wcin.ignore();
	if (moznost == 'Y' || moznost == 'y')
	{
		bool koniec = false;
		std::wstring min, max = L"0";
		while (!koniec)
		{
			std::wcout << L"Zadajte minimalny pocet obyvatelov: ";
			std::wcin >> min;
			std::wcout << L"Zadajte maximalny pocet obyvatelov: ";
			std::wcin >> max;
			if (stoi(min) < stoi(max) && stoi(min) >= 0)
			{
				koniec = true;
			}
			else
			{
				std::wcout << L"Zadali ste maximum vacsie ako mininum alebo minimum mensie ako 0! Skuste to znova: ";
			}
		}

		KriteriumUJPocetObyv* kPocetObyv = new KriteriumUJPocetObyv();


		return new FilterPodlaIntervalu<std::wstring, UzemnaJednotka, int>(kPocetObyv, stoi(min), stoi(max));
		 
	}
	else
	{
		return nullptr;
	}
}

Filter<std::wstring, UzemnaJednotka, double>* Funkcionalita3::vratFilterZastavanost()
{
	wchar_t moznost;
	std::wcout << L"Chcete filtrovat podla zastavanosti? [Y/N]: ";
	std::wcin >> moznost;
	std::wcin.ignore();
	if (moznost == 'Y' || moznost == 'y')
	{
		bool koniec = false;
		std::wstring min, max = L"0";
		while (!koniec)
		{
			std::wcout << L"Zadajte minimalnu zastavanost (Cislo z intervalu <0;100>): ";
			std::wcin >> min;
			std::wcout << L"Zadajte maximalny pocet obyvatelov (Cislo z intervalu <0;100>): ";
			std::wcin >> max;
			if (stoi(min) < stoi(max) && stoi(min) >= 0 && stoi(min) <= 100 && stoi(max) >= 0 && stoi(max) <= 100)
			{
				koniec = true;
			}
			else
			{
				std::wcout << L"Zadali ste maximum mensie ako minimum alebo hodnoty neboli z intervalu <0;100>. Skuste to znova:";
			}
		}

		KriteriumUJZastavanost* kZastavanost = new KriteriumUJZastavanost();

		return new FilterPodlaIntervalu<std::wstring, UzemnaJednotka, double>(kZastavanost, stoi(min), stoi(max));
	}
	else
	{
		return nullptr;
	}
}



bool Funkcionalita3::zistiFilterPodlaNazvu(structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>*& vstupnaTab, UzemnaJednotka*& data, Stat* stat, bool filtrovaniePodlaTypu)
{
	wchar_t moznost;
	std::wcout << L"Chcete filtrovat podla nazvu? [Y/N]: ";
	std::wcin >> moznost;
	std::wcin.ignore();
	if (moznost == 'Y' || moznost == 'y')
	{
		std::wcout << L"Zadajte nazov hladanej jednotky: ";
		std::wstring nazovHladanejUJ;
		std::getline(std::wcin, nazovHladanejUJ);
		if (filtrovaniePodlaTypu)
		{
			vstupnaTab->tryFind(nazovHladanejUJ, data);
		}
		else
		{
			stat->getTabKrajov()->tryFind(nazovHladanejUJ, data);

			if (data == nullptr)
			{
				stat->getTabOkresov()->tryFind(nazovHladanejUJ, data);
			}

			if (data == nullptr)
			{
				stat->getTabObci()->tryFind(nazovHladanejUJ, data);
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}



void Funkcionalita3::vypisTabulku(structures::SequenceTable<std::wstring, UzemnaJednotka*>* tabulka)
{
	for (auto tableItem : *tabulka)
	{
		tableItem->accessData()->vypis();
		std::wcout << std::endl;
	}
}

void Funkcionalita3::vypisHlavicku()
{
	std::wcout << std::endl << std::setw(30) << L"Nazov obce|" << std::setw(10) << L"Pocet ob.|" << std::setw(8) << L"Pocet predpr. ob.|" <<
		std::setw(8) << L"Pocet prod. ob.|" << std::setw(8) << L"Pocet poprod. ob.|" << std::setw(8) << std::setprecision(2)
		<< L"Zastavanost|" << std::setw(15) << L"Celk. vymera|" << std::setw(15) << L"Zast. plocha|\n";
}

void Funkcionalita3::vyfiltrujAVypisJednotku(UzemnaJednotka* hladana, ZlozenyFilter<UzemnaJednotka>& fZlozeny)
{
	if (hladana != nullptr)
	{
		if (fZlozeny.splnaFilter(*hladana))
		{
			hladana->vypis();
		}
		else
		{
			std::wcout << std::endl;
			std::wcout << L"Ziadna jednotka s danym nazvom nesplna zadane parametre";
		}
	}
	else
	{
		std::wcout << std::endl;
		std::wcout << L"Jednotka s danym nazvom nebola najdena";
	}
}

void Funkcionalita3::spusti()
{
	Stat stat(L"Slovensko");
	stat.nacitajZoSuboru("2 Tzemné ƒlenenie SR.csv", "1 Obce SR.csv");

	ZlozenyFilter<UzemnaJednotka> fZlozeny;

	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* vstupnaTab = nullptr;
	structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* vyfiltrovanaTab = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>;
	
	//filtre typ a prislusnost
	vstupnaTab = vratTabulkuPodlaTypu(stat);
	bool filtrovaniePodlaTypu = (vstupnaTab != nullptr);

	Filter<std::wstring, UzemnaJednotka, bool>* fPrislusnost = vratFilterPrislusnost();

	//filtre nazov, pocet ob a zastavanost
	bool filtrovaniePodlaNazvu = false;
	UzemnaJednotka* hladana = nullptr;
	filtrovaniePodlaNazvu = zistiFilterPodlaNazvu(vstupnaTab, hladana, &stat, filtrovaniePodlaTypu);

	Filter<std::wstring, UzemnaJednotka, int>* fPocetObyv = vratFilterPocetObyv();

	Filter<std::wstring, UzemnaJednotka, double>* fZastavanost = vratFilterZastavanost();

	if (fPrislusnost != nullptr)
	{
		fZlozeny.pridaj(*fPrislusnost);
	}

	if (fPocetObyv != nullptr)
	{
		fZlozeny.pridaj(*fPocetObyv);
	}

	if (fZastavanost != nullptr)
	{
		fZlozeny.pridaj(*fZastavanost);
	}

	if (filtrovaniePodlaTypu) //ak je zapnute filtrovanie podla typu
	{
		if (filtrovaniePodlaNazvu)
		{
			vyfiltrujAVypisJednotku(hladana, fZlozeny);
		}
		else
		{
			fZlozeny.vyfiltrujTabulku(vstupnaTab, vyfiltrovanaTab);
			if (!vyfiltrovanaTab->isEmpty())
			{
				vypisTabulku(vyfiltrovanaTab);
			}
			else
			{
				std::wcout << std::endl;
				std::wcout << L"Zadanym parametrom neodpoveda ziadna jednotka";
			}
		}

	}
	else
	{
		if (filtrovaniePodlaNazvu)
		{
			vyfiltrujAVypisJednotku(hladana, fZlozeny);
		}
		else
		{
			structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* kraje = stat.getTabKrajov();
			structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* okresy = stat.getTabOkresov();
			structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* obce = stat.getTabObci();

			structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeVyfiltrovana = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>;
			structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyVyfiltrovana = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>;
			structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* obceVyfiltrovana = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>;

			fZlozeny.vyfiltrujTabulku(kraje, krajeVyfiltrovana);
			fZlozeny.vyfiltrujTabulku(okresy, okresyVyfiltrovana);
			fZlozeny.vyfiltrujTabulku(obce, obceVyfiltrovana);

			if (!krajeVyfiltrovana->isEmpty() || !okresyVyfiltrovana->isEmpty() || !obceVyfiltrovana->isEmpty())
			{
				vypisTabulku(krajeVyfiltrovana);
				vypisTabulku(okresyVyfiltrovana);
				vypisTabulku(obceVyfiltrovana);
			}
			else
			{
				std::wcout << L"Ziadna jednotka so zadanymi parametrami nebola najdena";
			}

			delete krajeVyfiltrovana;
			delete okresyVyfiltrovana;
			delete obceVyfiltrovana;
		}
	}
	
	delete vyfiltrovanaTab;	
}
