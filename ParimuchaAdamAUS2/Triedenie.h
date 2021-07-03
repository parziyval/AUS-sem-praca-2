#pragma once
#include "Kriterium.h"
#include "unsorted_sequence_table.h"
#include "sequence_table.h"
template<typename Kluc, typename Jednotka, typename Hodnota>
class Triedenie
{
private:
	Kriterium<Hodnota, Jednotka>* kriterium = nullptr;
	bool vzostupne = true;
public:
	Triedenie() {};
	~Triedenie() {};

	void utried(structures::UnsortedSequenceTable<Kluc, Jednotka*>& tab, Kriterium<Hodnota, Jednotka>& kriterium, bool vzostupne);
	void sort(structures::UnsortedSequenceTable<Kluc, Jednotka*>& table);
	void quick(int min, int max, structures::UnsortedSequenceTable<Kluc, Jednotka*>& table);
};



template<typename Kluc, typename Jednotka, typename Hodnota>
inline void Triedenie<Kluc, Jednotka, Hodnota>::utried(structures::UnsortedSequenceTable<Kluc, Jednotka*>& tab, Kriterium<Hodnota, Jednotka>& kriterium, bool vzostupne)
{
	this->kriterium = &kriterium;
	this->vzostupne = vzostupne;
	sort(tab);
}

template<typename Kluc, typename Jednotka, typename Hodnota>
inline void Triedenie<Kluc, Jednotka, Hodnota>::sort(structures::UnsortedSequenceTable<Kluc, Jednotka*>& table)
{
	quick(0, table.size() - 1, table);
}

template<typename Kluc, typename Jednotka, typename Hodnota>
inline void Triedenie<Kluc, Jednotka, Hodnota>::quick(int min, int max, structures::UnsortedSequenceTable<Kluc, Jednotka*>& table)
{
	Hodnota pivot = this->kriterium->ohodnot(*(table.getItemAtIndex((min + max) / 2).accessData()));
	int lavy = min;
	int pravy = max;

	do
	{
		if (vzostupne)
		{
			while (kriterium->ohodnot(*(table.getItemAtIndex(lavy).accessData())) < pivot)
			{
				lavy++;
			}

			while (kriterium->ohodnot(*(table.getItemAtIndex(pravy).accessData())) > pivot)
			{
				pravy--;
			}
		}
		else
		{
			while (kriterium->ohodnot(*(table.getItemAtIndex(lavy).accessData())) > pivot)
			{
				lavy++;
			}

			while (kriterium->ohodnot(*(table.getItemAtIndex(pravy).accessData())) < pivot)
			{
				pravy--;
			}
		}
		

		if (lavy <= pravy)
		{
			table.swap(lavy, pravy);
			lavy++;
			pravy--;
		}
		
	} while (lavy <= pravy);

	if (min < pravy)
	{
		quick(min, pravy, table);
	}

	if (lavy < max)
	{
		quick(lavy, max, table);
	}
}
