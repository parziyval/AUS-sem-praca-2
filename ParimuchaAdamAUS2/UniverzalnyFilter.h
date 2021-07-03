#pragma once
template<typename Jednotka>
class UniverzalnyFilter
{
public:
	virtual ~UniverzalnyFilter() {};
	virtual bool splnaFilter(Jednotka& prvok) = 0;
};