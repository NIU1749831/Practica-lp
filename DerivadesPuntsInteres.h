#pragma once

#include "PuntDeInteresBase.h"
#include<vector>
#include <string>

class PuntInteresBotigaSolucio : public PuntDeInteresBase
{
public:
	PuntInteresBotigaSolucio() : PuntDeInteresBase(), m_tipusBotiga(""), m_wealChair(false), m_openingHours("") {};
	PuntInteresBotigaSolucio(const string& n, const string& t, const string& o, const Coordinate& c, const bool& w)
		: PuntDeInteresBase(c, n), m_tipusBotiga(t), m_wealChair(w), m_openingHours(o) {
	};
	PuntInteresBotigaSolucio(const PuntInteresBotigaSolucio& other) : PuntDeInteresBase(other),
		m_tipusBotiga(other.m_tipusBotiga), m_wealChair(other.m_wealChair), m_openingHours(other.m_openingHours) {
	}
	//string getName() override;
	unsigned getColor() override;
	PuntInteresBotigaSolucio* clone() override;

private:
	string m_tipusBotiga;
	bool m_wealChair;
	string m_openingHours;
};

class PuntInteresRestaurantSolucio : public PuntDeInteresBase
{
public:
	PuntInteresRestaurantSolucio() {};
	PuntInteresRestaurantSolucio(const Coordinate& coord, const string& name, const string& tipusDeCuina, const bool& FacilitaAccesMR)
		: PuntDeInteresBase(coord, name), tipusDeCuina(tipusDeCuina), FacilitaAccesMR(FacilitaAccesMR) {
	}

	PuntInteresRestaurantSolucio(const PuntInteresRestaurantSolucio& other) : PuntDeInteresBase(other),
		tipusDeCuina(other.tipusDeCuina), FacilitaAccesMR(other.FacilitaAccesMR) {
	}
	~PuntInteresRestaurantSolucio() {}

	unsigned int getColor() override;
	PuntInteresRestaurantSolucio* clone() override;

private:
	string tipusDeCuina;
	bool FacilitaAccesMR;
};
