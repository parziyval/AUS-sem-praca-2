#include "Funkcionalita4.h"

#define MOZNOST_KRAJ 1
#define MOZNOST_OKRES 2
#define MOZNOST_OBEC 3 
#define MOZNOST_STAT 4 

#define TRIEDENIE_NAZOV 1
#define TRIEDENIE_POCET_OBYV 2
#define TRIEDENIE_ZASTAVANOST 3

Funkcionalita4::Funkcionalita4()
{
}

Funkcionalita4::~Funkcionalita4()
{
}

structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* Funkcionalita4::vratTabulkuPodlaTypu(Stat& stat)
{
	bool koniec = false;
	wchar_t moznost;
	std::wcout << L"Chcete filtrovat podla typu? (ak nie, bude sa filtrovat pre cely stat) [Y/N]: ";
	std::wcin >> moznost;
	if (moznost == 'Y' || moznost == 'y')
	{
		while (!koniec)
		{
			std::wcout << L"Zadajte cislo prislusneho typu\n1 - Kraj\n2 - Okres\n3 - Obec\n";
			std::wstring moznostTypStr;

			std::wcin >> moznostTypStr;
			switch (stoi(moznostTypStr))
			{
			case MOZNOST_KRAJ:
				return stat.getTabKrajovUn();
				break;
			case MOZNOST_OKRES:
				return stat.getTabOkresovUn();
				break;
			case MOZNOST_OBEC:
				return stat.getTabObciUn();
				break;
			case MOZNOST_STAT:
				return nullptr;
				break;
			default:
				std::wcout << L"Zadajte platnu moznost: ";
				break;
			}
		}
	}
	else
	{
		return nullptr;
	}
}

Filter<std::wstring, UzemnaJednotka, bool>* Funkcionalita4::vratFilterPrislusnost()
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

int Funkcionalita4::zistiAkeTriedenie()
{
	std::wstring moznost;
	bool koniec = false;
	int navratova = 0;
	std::wcout << L"Vyberte si podla coho chcete triedit\n1 - Nazov\n2 - Pocet obyvatelov\n3 - Zastavanost\n";
	while (!koniec)
	{
		std::wcin >> moznost;
		if (stoi(moznost) == TRIEDENIE_NAZOV)
		{
			navratova = TRIEDENIE_NAZOV;
			break;
		}
		else if (stoi(moznost) == TRIEDENIE_POCET_OBYV)
		{
			navratova = TRIEDENIE_POCET_OBYV;
			break;
		}
		else if (stoi(moznost) == TRIEDENIE_ZASTAVANOST)
		{
			navratova = TRIEDENIE_ZASTAVANOST;
			break;
		}
		else
		{
			std::wcout << L"Zadajte platnu moznost: ";
		}
	}
	return navratova;
}

bool Funkcionalita4::zistiCiVzostupne()
{
	wchar_t moznost;
	std::wcout << L"Chcete triedit vzostupne? (Ak zadate inu moznost ako 'Y', bude sa triedit zostupne) [Y/N]: ";
	std::wcin >> moznost;
	std::wcin.ignore();
	return (moznost == 'Y' || moznost == 'y');
}

void Funkcionalita4::vypisTabulku(structures::SequenceTable<std::wstring, UzemnaJednotka*>* tabulka)
{

	for (auto tableItem : *tabulka)
	{
		tableItem->accessData()->vypis();
		std::wcout << std::endl;
	}
}

void Funkcionalita4::vypisTabulkuNazov(structures::SequenceTable<std::wstring, UzemnaJednotka*>* tabulka)
{
	for (auto tableItem : *tabulka)
	{
		std::wcout << tableItem->accessData()->getNazov();
		std::wcout << std::endl;
	}
}

void Funkcionalita4::vypisTabulkuPocetObyv(structures::SequenceTable<std::wstring, UzemnaJednotka*>* tabulka)
{
	for (auto tableItem : *tabulka)
	{
		std::wcout << tableItem->accessData()->getNazov() << L" " << tableItem->accessData()->getPocetObyv();
		std::wcout << std::endl;
	}
}

void Funkcionalita4::vypisTabulkuZastavanost(structures::SequenceTable<std::wstring, UzemnaJednotka*>* tabulka)
{
	for (auto tableItem : *tabulka)
	{
		std::wcout << tableItem->accessData()->getNazov() << L" " << tableItem->accessData()->getZastavanost() << L"%";
		std::wcout << std::endl;
	}
}

void Funkcionalita4::vypisHlavicku()
{
	std::wcout << std::endl << std::setw(30) << L"Nazov obce|" << std::setw(10) << L"Pocet ob.|" << std::setw(8) << L"Pocet predpr. ob.|" <<
		std::setw(8) << L"Pocet prod. ob.|" << std::setw(8) << L"Pocet poprod. ob.|" << std::setw(8) << std::setprecision(2)
		<< L"Zastavanost|" << std::setw(15) << L"Celk. vymera|" << std::setw(15) << L"Zast. plocha|\n";
}

void Funkcionalita4::utriedVsetkoPodlaNazvu(bool& vzostupne, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obceUtriedovana)
{
	Triedenie<std::wstring, UzemnaJednotka, std::wstring> tNazov;
	KriteriumUJNazov kNazov;
	vzostupne = zistiCiVzostupne();
	if (!krajeUtriedovana->isEmpty())
	{
		tNazov.utried(*krajeUtriedovana, kNazov, vzostupne);
	}

	if (!okresyUtriedovana->isEmpty())
	{
		tNazov.utried(*okresyUtriedovana, kNazov, vzostupne);
	}

	if (!obceUtriedovana->isEmpty())
	{
		tNazov.utried(*obceUtriedovana, kNazov, vzostupne);
	}
}

void Funkcionalita4::utriedVsetkoPodlaZastavanosti(bool& vzostupne, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obceUtriedovana)
{
	Triedenie<std::wstring, UzemnaJednotka, double> tZastavanost;
	KriteriumUJZastavanost kZastavanost;
	vzostupne = zistiCiVzostupne();
	if (!krajeUtriedovana->isEmpty())
	{
		tZastavanost.utried(*krajeUtriedovana, kZastavanost, vzostupne);
	}

	if (!okresyUtriedovana->isEmpty())
	{
		tZastavanost.utried(*okresyUtriedovana, kZastavanost, vzostupne);
	}

	if (!obceUtriedovana->isEmpty())
	{
		tZastavanost.utried(*obceUtriedovana, kZastavanost, vzostupne);
	}
}


void Funkcionalita4::utriedVsetkoPodlaPocetObyv(bool& vzostupne, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyUtriedovana, structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obceUtriedovana)
{
	Triedenie<std::wstring, UzemnaJednotka, int> tPocetObyv;
	KriteriumUJPocetObyv kPocetObyv;
	vzostupne = zistiCiVzostupne();
	if (!krajeUtriedovana->isEmpty())
	{
		tPocetObyv.utried(*krajeUtriedovana, kPocetObyv, vzostupne);
	}

	if (!okresyUtriedovana->isEmpty())
	{
		tPocetObyv.utried(*okresyUtriedovana, kPocetObyv, vzostupne);
	}

	if (!obceUtriedovana->isEmpty())
	{
		tPocetObyv.utried(*obceUtriedovana, kPocetObyv, vzostupne);
	}
}

void Funkcionalita4::spusti()
{
	Stat stat(L"Slovensko");
	stat.nacitajZoSuboru("2 Tzemné ƒlenenie SR.csv", "1 Obce SR.csv");

	structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* vstupnaTab = nullptr;
	structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* vyfiltrovanaTab 
		= new structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>;

	//zisti typ uj ktory sa bude prehladavat
	vstupnaTab = vratTabulkuPodlaTypu(stat);
	bool filtrovaniePodlaTypu = (vstupnaTab != nullptr);

	//zisti ci sa bude filtrovat podla prislusnosti
	Filter<std::wstring, UzemnaJednotka, bool>* fPrislusnost = vratFilterPrislusnost();
	
	int moznostTriedenie = zistiAkeTriedenie();
	bool vzostupne;

	if (filtrovaniePodlaTypu)
	{
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* utriedovanaTab;

		if (fPrislusnost != nullptr)
		{
			fPrislusnost->vyfiltrujTabulku(vstupnaTab, vyfiltrovanaTab);
			utriedovanaTab = vyfiltrovanaTab;
		}
		else
		{
			utriedovanaTab = vstupnaTab;
		}

		if (!utriedovanaTab->isEmpty())
		{
			if (moznostTriedenie == TRIEDENIE_NAZOV)
			{
				Triedenie<std::wstring, UzemnaJednotka, std::wstring> tNazov;
				KriteriumUJNazov kNazov;
				vzostupne = zistiCiVzostupne();
				tNazov.utried(*utriedovanaTab, kNazov, vzostupne);
				vypisTabulkuNazov(utriedovanaTab);
			}
			else if (moznostTriedenie == TRIEDENIE_POCET_OBYV)
			{
				Triedenie<std::wstring, UzemnaJednotka, int> tPocetObyv;
				KriteriumUJPocetObyv kPocetObyv;
				vzostupne = zistiCiVzostupne();
				tPocetObyv.utried(*utriedovanaTab, kPocetObyv, vzostupne);
				vypisTabulkuPocetObyv(utriedovanaTab);
			}
			else
			{
				Triedenie<std::wstring, UzemnaJednotka, double> tZastavanost;
				KriteriumUJZastavanost kZastavanost;
				vzostupne = zistiCiVzostupne();
				tZastavanost.utried(*utriedovanaTab, kZastavanost, vzostupne);
				vypisTabulkuZastavanost(utriedovanaTab);
			}

			//vypisTabulku(utriedovanaTab);
		}
		else
		{
			std::wcout << std::endl;
			std::wcout << L"Zadanym parametrom neodpoveda ziadna jednotka";
		}
		

		
	}
	else //nefiltruje sa podla typu
	{
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* kraje = stat.getTabKrajovUn();
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresy = stat.getTabOkresovUn();
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obce = stat.getTabObciUn();
					
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeVyfiltrovana = new structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>;
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyVyfiltrovana = new structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>;
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obceVyfiltrovana = new structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>;

		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeUtriedovana = nullptr;
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>*okresyUtriedovana = nullptr;
		structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>*obceUtriedovana = nullptr;


		if (fPrislusnost != nullptr)
		{
			fPrislusnost->vyfiltrujTabulku(kraje, krajeVyfiltrovana);
			fPrislusnost->vyfiltrujTabulku(okresy, okresyVyfiltrovana);
			fPrislusnost->vyfiltrujTabulku(obce, obceVyfiltrovana);

			krajeUtriedovana = krajeVyfiltrovana;
			okresyUtriedovana = okresyVyfiltrovana;
			obceUtriedovana = obceVyfiltrovana;
		}
		else
		{
			krajeUtriedovana = kraje;
			okresyUtriedovana = okresy;
			obceUtriedovana = obce;
		}


		if (!krajeUtriedovana->isEmpty() || !okresyUtriedovana->isEmpty() || !obceUtriedovana->isEmpty())
		{
			if (moznostTriedenie == TRIEDENIE_NAZOV)
			{
				utriedVsetkoPodlaNazvu(vzostupne, krajeUtriedovana, okresyUtriedovana, obceUtriedovana);
				vypisTabulkuNazov(krajeUtriedovana);
				vypisTabulkuNazov(okresyUtriedovana);
				vypisTabulkuNazov(obceUtriedovana);
			}
			else if (moznostTriedenie == TRIEDENIE_POCET_OBYV)
			{
				utriedVsetkoPodlaPocetObyv(vzostupne, krajeUtriedovana, okresyUtriedovana, obceUtriedovana);
				vypisTabulkuPocetObyv(krajeUtriedovana);
				vypisTabulkuPocetObyv(okresyUtriedovana);
				vypisTabulkuPocetObyv(obceUtriedovana);
			}
			else
			{
				utriedVsetkoPodlaZastavanosti(vzostupne, krajeUtriedovana, okresyUtriedovana, obceUtriedovana);
				vypisTabulkuZastavanost(krajeUtriedovana);
				vypisTabulkuZastavanost(okresyUtriedovana);
				vypisTabulkuZastavanost(obceUtriedovana);
			}

			/*vypisTabulku(krajeUtriedovana);
			vypisTabulku(okresyUtriedovana);
			vypisTabulku(obceUtriedovana);*/
		}
		else
		{
			std::wcout << std::endl;
			std::wcout << L"Zadanym parametrom neodpoveda ziadna jednotka";
		}

		delete krajeVyfiltrovana;
		delete okresyVyfiltrovana;
		delete obceVyfiltrovana;
	}

	delete vyfiltrovanaTab;
	delete fPrislusnost;
}



