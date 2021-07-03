#pragma once
#include "Kriterium.h"
#include "UniverzalnyFilter.h"
#include "unsorted_sequence_table.h"
#include "sorted_sequence_table.h"
template<typename Kluc, typename Jednotka, typename Hodnota>
class Filter
	:public UniverzalnyFilter<Jednotka>
{
protected:
	Kriterium<Hodnota, Jednotka>* kriterium;
public:
	Filter(Kriterium<Hodnota, Jednotka>* kriterium);
	virtual ~Filter();
	virtual bool splnaFilter(Jednotka& objekt) = 0;
	void vyfiltrujTabulku(structures::SequenceTable<Kluc, Jednotka*>* tabulka,
		structures::SequenceTable<Kluc, Jednotka*>* vyfiltrovanaTab);
};

template<typename Kluc, typename Jednotka, typename Hodnota>
inline Filter<Kluc, Jednotka, Hodnota>::Filter(Kriterium<Hodnota, Jednotka>* kriterium)
{
	this->kriterium = kriterium;
}

template<typename Kluc, typename Jednotka, typename Hodnota>
inline Filter<Kluc, Jednotka, Hodnota>::~Filter()
{
	delete this->kriterium;
}

template<typename Kluc, typename Jednotka, typename Hodnota>
inline void Filter<Kluc, Jednotka, Hodnota>::vyfiltrujTabulku(structures::SequenceTable<Kluc, Jednotka*>* tabulka, 
																structures::SequenceTable<Kluc, Jednotka*>* vyfiltrovanaTab)
{
	for(auto tableItem:*tabulka) {
		if (this->splnaFilter(*(tableItem->accessData())))
		{
			vyfiltrovanaTab->insert(tableItem->getKey(), tableItem->accessData());
		}
	}
}
