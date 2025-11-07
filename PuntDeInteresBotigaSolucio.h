#include "PuntDeInteresBase.h"


class PuntInteresBotigaSolucio	: public PuntDeInteresBase
{
public:
	PuntInteresBotigaSolucio() : PuntDeInteresBase(), m_tag(""), m_wealChair(false), m_openingHours("") {};
	PuntInteresBotigaSolucio(const string& n, const string& t, const string& o, const Coordinate& c, const bool& w)
		: PuntDeInteresBase(c, n), m_tag(t), m_wealChair(w), m_openingHours(o) {};
	PuntInteresBotigaSolucio(const PuntInteresBotigaSolucio& other)	: PuntDeInteresBase(other),
		m_tag(other.m_tag),	m_wealChair(other.m_wealChair),	m_openingHours(other.m_openingHours) {
	}
	//string getName() override;
	unsigned getColor() override;
	PuntInteresBotigaSolucio* clone() override;
	
private:
	string m_tag;
	bool m_wealChair;
	string m_openingHours;
};
