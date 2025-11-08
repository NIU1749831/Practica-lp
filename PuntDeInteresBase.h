#pragma once
#include "pch.h"

#include <string>
#include "Common.h"

class PuntDeInteresBase
{

	private:
		Coordinate m_coord;
		std::string m_name;

	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, std::string name);

		void setNom(const string& s) {m_name = s;}
		void setLat(const double& l) { m_coord.lat = l; }
		void setLon(const double& l) { m_coord.lon = l; }

		virtual string getName();
		Coordinate getCoord();
		virtual unsigned int getColor();

		virtual PuntDeInteresBase* clone();

};