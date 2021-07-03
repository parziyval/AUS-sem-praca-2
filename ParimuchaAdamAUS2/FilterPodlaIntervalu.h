#pragma once
#include "Filter.h"
template<typename Kluc, typename Jednotka, typename Hodnota>
class FilterPodlaIntervalu :
    public Filter<Kluc, Jednotka, Hodnota>
{
private:
    Hodnota min;
    Hodnota max;
public:
    FilterPodlaIntervalu(Kriterium<Hodnota, Jednotka>* kriterium, Hodnota p_min, Hodnota p_max) 
        : Filter<Kluc, Jednotka, Hodnota>(kriterium) {
        this->min = p_min;
        this->max = p_max;
        };
    bool splnaFilter(Jednotka& objekt) override;
};

template<typename Kluc, typename Jednotka, typename Hodnota>
inline bool FilterPodlaIntervalu<Kluc, Jednotka, Hodnota>::splnaFilter(Jednotka& objekt)
{
    Hodnota hodnota = this->kriterium->ohodnot(objekt);
    return (this->min <= hodnota) && (hodnota <= this->max);
}

