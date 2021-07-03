#pragma once
#include "UzemnaJednotka.h"
#include "Kriterium.h"
template<typename Hodnota>
class KriteriumUJ : 
	public Kriterium<Hodnota, UzemnaJednotka>
{
	//virtual ~KriteriumUJ() {};
	virtual Hodnota ohodnot(UzemnaJednotka& o) = 0;
};

