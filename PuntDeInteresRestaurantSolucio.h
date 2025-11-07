#pragma once
#include <string>
#include "PuntDeInteresBase.h"

/*
Pare:
class PuntDeInteresBase {

	private:
		Coordinate m_coord;
		std::string m_name;

	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, std::string name);

		virtual std::string getName();
		Coordinate getCoord();
		virtual unsigned int getColor();

};*/

class PuntInteresRestaurantSolucio : public PuntDeInteresBase
{
public:
	PuntInteresRestaurantSolucio() {};
	PuntInteresRestaurantSolucio(const Coordinate& coord, const string& name, const string& tipusDeCuina, const bool& FacilitaAccesMR)
		: PuntDeInteresBase(coord, name), tipusDeCuina(tipusDeCuina), FacilitaAccesMR(FacilitaAccesMR){}
	
	PuntInteresRestaurantSolucio(const PuntInteresRestaurantSolucio& other) : PuntDeInteresBase(other),
		tipusDeCuina(other.tipusDeCuina), FacilitaAccesMR(other.FacilitaAccesMR) {}
	~PuntInteresRestaurantSolucio(){}

	unsigned int getColor() override;
	PuntInteresRestaurantSolucio* clone() override;
	
private:
	string tipusDeCuina;
	bool FacilitaAccesMR;
};
