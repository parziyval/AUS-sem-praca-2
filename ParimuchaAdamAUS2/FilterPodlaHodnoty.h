#pragma once
#include "Filter.h"
template<typename Kluc, typename Jednotka, typename Hodnota>
class FilterPodlaHodnoty :
    public Filter<Kluc, Jednotka, Hodnota>
{
protected:
    Hodnota hodnota;
public:
    FilterPodlaHodnoty(Kriterium<Hodnota, Jednotka>* kriterium, Hodnota hodnota) :Filter<Kluc, Jednotka, Hodnota>(kriterium) { this->hodnota = hodnota; };
    bool splnaFilter(Jednotka& objekt) override;
};

template<typename Kluc, typename Jednotka, typename Hodnota>
inline bool FilterPodlaHodnoty<Kluc, Jednotka, Hodnota>::splnaFilter(Jednotka& objekt)
{
    return this->kriterium->ohodnot(objekt) == this->hodnota;
}
