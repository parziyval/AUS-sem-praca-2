#pragma once
template<typename Hodnota,typename Jednotka>
class Kriterium
{
public:
	virtual ~Kriterium() {};
	virtual Hodnota ohodnot(Jednotka& o) = 0;
};

