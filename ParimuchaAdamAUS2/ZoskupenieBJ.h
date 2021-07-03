#pragma once
#include <string>
class ZoskupenieBJ
{
private:
	std::string typ;
	int pocetOsob;
	int pocetObMiestnosti;
public:
	std::string getTyp() { return typ; };
	int getPocetOsob() { return pocetOsob; };
	int getPocetObMiestnosti() { return pocetObMiestnosti; };
};

