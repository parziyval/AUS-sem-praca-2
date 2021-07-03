#include "Aplikacia.h"

#define MOZNOST_FUNKC_3 1
#define MOZNOST_FUNKC_4 2

#define MOZNOST_KRAJ 1
#define MOZNOST_OKRES 2
#define MOZNOST_OBEC 3 
#define MOZNOST_STAT 4 

#define TRIEDENIE_NAZOV 1
#define TRIEDENIE_POCET_OBYV 2
#define TRIEDENIE_ZASTAVANOST 3

void Aplikacia::spusti()
{
	std::wcout << L"Vitajte v informacnom systeme uzemnych jednotiek Slovenska\n";
	std::wcout << L"Pri vybere [Y/N] zadajte Y alebo y ak chcete dany filter aplikovat alebo iny znak ak nie\n";
	std::wcout << L"Pri vybere typu 'cislo - moznost' zadajte prislusne cislo moznosti\n";
	bool koniec = false;
	std::wstring moznost;

	while (!koniec)
	{
		std::wcout << L"Vyberte co chcete robit\n1 - Filtrovanie uzemnych jednotiek a vypisanie informacii o nich\n2 - Zoradenie uzemnych jednotiek na zaklade filtrov\n";

		std::wcin >> moznost;
		if (stoi(moznost) == MOZNOST_FUNKC_3)
		{
			Funkcionalita3 f3;
			f3.spusti();
			koniec = true;
		}
		else if (stoi(moznost) == MOZNOST_FUNKC_4)
		{
			Funkcionalita4 f4;
			f4.spusti();
			koniec = true;
		}
		else
		{
			std::wcout << L"Zadajte platnu moznost: ";
		}
	}
}
