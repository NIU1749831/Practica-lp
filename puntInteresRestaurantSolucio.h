#pragma once

#include <string>
#include "..\VSCE2022 - ALUMNES P1\LP-OSM-DLL-2022\PuntDeInteresBase.h"
#include "../VSCE2022 - ALUMNES P1/LP-OSM-DLL-2022/pch.h"
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
	~PuntInteresRestaurantSolucio(){}

	unsigned int getColor() override;

private:
	string tipusDeCuina;
	bool FacilitaAccesMR;
};
