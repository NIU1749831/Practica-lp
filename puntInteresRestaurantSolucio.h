#pragma once

#include <string>
#include "..\proyecto\VSCE2022 - ALUMNES P1\LP-OSM-DLL-2022\PuntDeInteresBase.h"

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

class puntInteresRestaurantSolucio : public PuntDeInteresBase
{
public:
	puntInteresRestaurantSolucio(){}
	puntInteresRestaurantSolucio(Coordinate coord, string name, string tipusDeCuina, bool FacilitaAccesMR)
		: PuntDeInteresBase(coord, name), tipusDeCuina(tipusDeCuina), FacilitaAccesMR(FacilitaAccesMR){}
	~puntInteresRestaurantSolucio(){}

	unsigned int getColor() override;

private:
	string tipusDeCuina;
	bool FacilitaAccesMR;
};
