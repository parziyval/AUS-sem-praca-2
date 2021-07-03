#include "Stat.h"

Stat::Stat(std::wstring nazov)
{
	this->typ = EnumTypUJ::STAT;
	this->nazov = nazov;

	this->kraje = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>;
	this->okresy = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>;
	this->obce = new structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>;

	this->krajeUn = new structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>;
	this->okresyUn = new structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>;
	this->obceUn = new structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>;
}

Stat::~Stat()
{
	for (auto obec : *this->obce) {
		delete obec->accessData();
	}

	for (auto okres : *this->okresy) {
		delete okres->accessData();
	}

	for (auto kraj : *this->kraje) {
		delete kraj->accessData();
	}

	delete this->kraje;
	delete this->okresy;
	delete this->obce;
	
	delete this->krajeUn;
	delete this->okresyUn;
	delete this->obceUn;

	this->kraje = nullptr;
	this->okresy = nullptr;
	this->obce = nullptr;

	this->krajeUn = nullptr;
	this->okresyUn = nullptr;
	this->obceUn = nullptr;
}

void Stat::pridajKraj(std::wstring nazov, UzemnaJednotka* kraj)
{
	this->kraje->insert(nazov, kraj);
	this->krajeUn->insert(nazov, kraj);
}

void Stat::pridajOkres(std::wstring nazov, UzemnaJednotka* okres)
{
	this->okresy->insert(nazov, okres);
	this->okresyUn->insert(nazov, okres);
}

void Stat::pridajObec(std::wstring nazov, UzemnaJednotka* obec)
{
	this->obce->insert(nazov, obec);
	this->obceUn->insert(nazov, obec);
}

void Stat::nacitajZoSuboru(std::string nazovSuboruUJ, std::string nazovSuboruObce)
{
	std::wcout << "Nacitavam uzemne jednotky...";
	std::wifstream suborUJ;
	std::wifstream suborObce;

	suborUJ.imbue(std::locale("Slovak"));
	suborObce.imbue(std::locale("Slovak"));
	suborUJ.open(nazovSuboruUJ);
	suborObce.open(nazovSuboruObce);

	std::wstring nazovObec, nazovOkres, nazovKraj = L"";
	std::wstring predProStr, proStr, poProStr, vymeraStr, zastPlochaStr = L"";

	getline(suborUJ, nazovObec); //hlavicka tabulky, zahodi sa
	getline(suborObce, nazovObec); //hlavicka tabulky, zahodi sa
	while (!suborUJ.eof())
	{
		std::getline(suborUJ, nazovObec, L';');
		std::getline(suborUJ, nazovOkres, L';');
		std::getline(suborUJ, nazovKraj, L'\n');
	
		std::getline(suborObce, nazovObec, L';');
		std::getline(suborObce, predProStr, L';');
		std::getline(suborObce, proStr, L';');
		std::getline(suborObce, poProStr, L';');
		std::getline(suborObce, vymeraStr, L';');
		std::getline(suborObce, zastPlochaStr,L'\n');


		//vytvaranie kraja
		UzemnaJednotka* kraj;
		if (!this->kraje->tryFind(nazovKraj,kraj))
		{
			kraj = new Kraj(nazovKraj);
			kraj->setNadradenaUJ(this);
			this->pridajDoNizsich(nazovKraj, kraj);
			this->pridajKraj(nazovKraj, kraj);
		}

		//vytvaranie okresu
		UzemnaJednotka* okres;
		if (!this->okresy->tryFind(nazovOkres, okres)) {
			okres = new Okres(nazovOkres);
			okres->setNadradenaUJ(kraj);
			kraj->pridajDoNizsich(nazovOkres, okres);
			this->pridajOkres(nazovOkres, okres);
		}

		//vytvaranie obce
		UzemnaJednotka* obec = new Obec(nazovObec);
		obec->setNadradenaUJ(okres);
		obec->pridajPocty(stoi(predProStr), stoi(proStr), stoi(poProStr), stoi(vymeraStr), stoi(zastPlochaStr));
		okres->pridajDoNizsich(nazovObec, obec);
		this->pridajObec(nazovObec, obec);
	}
	
	suborUJ.close();
	suborObce.close();
	std::wcout << "Hotovo";
	std::wcout << std::endl;
}
