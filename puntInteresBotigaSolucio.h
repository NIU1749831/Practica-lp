#include "..\VSCE2022 - ALUMNES P1\LP-OSM-DLL-2022\PuntDeInteresBase.h"
#include "..\VSCE2022 - ALUMNES P1\LP-OSM-DLL-2022/pch.h"

class PuntInteresBotigaSolucio	: public PuntDeInteresBase
{
public:
	PuntInteresBotigaSolucio() : PuntDeInteresBase(), m_tag(""), m_wealChair(false), m_openingHours("") {};
	PuntInteresBotigaSolucio(const string& n, const string& t, const string& o, const Coordinate& c, const bool& w)
		: PuntDeInteresBase(c, n), m_tag(t), m_wealChair(w), m_openingHours(o) {};
	//string getName() override;
	unsigned getColor() override;

	
private:
	string m_tag;
	bool m_wealChair;
	string m_openingHours;
};
