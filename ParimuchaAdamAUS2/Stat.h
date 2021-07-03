#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "sorted_sequence_table.h"
#include "unsorted_sequence_table.h"
#include "UzemnaJednotka.h"
#include "Kraj.h"
#include "Okres.h"
#include "Obec.h"
class Stat :
    public UzemnaJednotka
{
private:
    structures::SortedSequenceTable<std::wstring,UzemnaJednotka*>* kraje;
    structures::SortedSequenceTable<std::wstring,UzemnaJednotka*>* okresy;
    structures::SortedSequenceTable<std::wstring,UzemnaJednotka*>* obce;

    structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* krajeUn;
    structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* okresyUn;
    structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* obceUn;
public:
    Stat(std::wstring nazov);
    ~Stat();

    void pridajKraj(std::wstring nazov, UzemnaJednotka* kraj);
    void pridajOkres(std::wstring nazov, UzemnaJednotka* okres);
    void pridajObec(std::wstring nazov, UzemnaJednotka* obec);

    structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* getTabKrajov() { return this->kraje; };
    structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* getTabOkresov() { return this->okresy; };
    structures::SortedSequenceTable<std::wstring, UzemnaJednotka*>* getTabObci() { return this->obce; };

    structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* getTabKrajovUn() { return this->krajeUn; };
    structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* getTabOkresovUn() { return this->okresyUn; };
    structures::UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* getTabObciUn() { return this->obceUn; };

    void nacitajZoSuboru(std::string nazovSuboruUJ,std::string nazovSuboruObce);
};

