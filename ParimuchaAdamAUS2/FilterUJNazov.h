#pragma once
#include "FilterPodlaHodnoty.h"
#include "UzemnaJednotka.h"
#include "KriteriumUJNazov.h"
class FilterUJNazov :
    public FilterPodlaHodnoty<std::wstring, UzemnaJednotka, std::wstring>
{
    FilterUJNazov(std::wstring hodnota)
        :FilterPodlaHodnoty<std::wstring, UzemnaJednotka, std::wstring>(kriterium, hodnota)
    { 
        this->kriterium = new KriteriumUJNazov();
    };
};

