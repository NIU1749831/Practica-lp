#include"../VSCE2022 - ALUMNES P1/LP-OSM-DLL-2022/PuntDeInteresBase.h"

class puntInteresBotiga	: public PuntDeInteresBase
{
public:
	puntInteresBotiga() : PuntDeInteresBase(), m_tag("") {};
	//string getName() override;
	unsigned getColor() override;
private:
	string m_tag;
	bool m_wealChair;
	string m_openingHours;
};
