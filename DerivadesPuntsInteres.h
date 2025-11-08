#pragma once

#include "PuntDeInteresBase.h"
#include<vector>
#include <string>

class PuntInteresBotigaSolucio : public PuntDeInteresBase
{
public:
	PuntInteresBotigaSolucio() : PuntDeInteresBase(), m_tag(""), m_wealChair(false), m_openingHours("") {};
	PuntInteresBotigaSolucio(const string& n, const string& t, const string& o, const Coordinate& c, const bool& w)
		: PuntDeInteresBase(c, n), m_tag(t), m_wealChair(w), m_openingHours(o) {
	};
	PuntInteresBotigaSolucio(const PuntInteresBotigaSolucio& other) : PuntDeInteresBase(other),
		m_tag(other.m_tag), m_wealChair(other.m_wealChair), m_openingHours(other.m_openingHours) {
	}
	//string getName() override;
	unsigned getColor() override;
	PuntInteresBotigaSolucio* clone() override;

private:
	string m_tag;
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

class PuntInteresGenericSolucio : public PuntDeInteresBase
{
private:
	vector<pair<string, string>> m_tags;
	bool m_sillaRuedas;
	string m_timestamp;
public:
	void setTimestamp(const string& t) { m_timestamp = t; }
	void setRuedas(const bool& b) { m_sillaRuedas = b; }
	void setTag(const pair<string, string>& p) { m_tags.push_back(p); }
	//possible metodo: encontrar devolver valor a traves de la llave
	PuntInteresGenericSolucio* clone() override;
};
