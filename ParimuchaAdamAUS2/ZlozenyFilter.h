#pragma once
#include "array_list.h"
#include "sorted_sequence_table.h"
#include "ZlozenyFilter.h"
#include "UniverzalnyFilter.h"
#include <vector>
template<typename Jednotka>
class ZlozenyFilter : public UniverzalnyFilter<Jednotka>
{
private:
    std::vector<UniverzalnyFilter<Jednotka>*>* filtre;
public: 
    ZlozenyFilter();
    ~ZlozenyFilter();
    bool splnaFilter(Jednotka& prvok);
    void pridaj(UniverzalnyFilter<Jednotka>& filter);
    void vyfiltrujTabulku(structures::SequenceTable<std::wstring, Jednotka*>* tabulka,
        structures::SequenceTable<std::wstring, Jednotka*>* vyfiltrovanaTab); 
};

template<typename Jednotka>
inline ZlozenyFilter<Jednotka>::ZlozenyFilter()
{
    this->filtre = new std::vector<UniverzalnyFilter<Jednotka>*>();
}

template<typename Jednotka>
inline ZlozenyFilter<Jednotka>::~ZlozenyFilter()
{
    for (auto filter : *filtre) {
        delete filter;
    }
    delete this->filtre;
    this->filtre = nullptr;
}

template<typename Jednotka>
inline bool ZlozenyFilter<Jednotka>::splnaFilter(Jednotka& prvok)
{
    for (auto filter : *filtre) {
        if (!filter->splnaFilter(prvok))
        {
            return false;
        }
    }
    return true;    
}

template<typename Jednotka>
inline void ZlozenyFilter<Jednotka>::pridaj(UniverzalnyFilter<Jednotka>& filter)
{
    filtre->push_back(&filter);
}

template<typename Jednotka>
inline void ZlozenyFilter<Jednotka>::vyfiltrujTabulku(structures::SequenceTable<std::wstring, Jednotka*>* tabulka, 
                                                        structures::SequenceTable<std::wstring, Jednotka*>* vyfiltrovanaTab)
{
    for (auto tableItem : *tabulka) {
        if (this->splnaFilter(*(tableItem->accessData())))
        {
            vyfiltrovanaTab->insert(tableItem->getKey(), tableItem->accessData());
        }
    }
}



