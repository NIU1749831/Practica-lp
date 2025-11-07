#pragma once

#include <string>
#include "Common.h"
#include <format>
using namespace std;

class PuntDeInteresBase {

	private:
		Coordinate m_coord;
		string m_name;

	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, string name);
		PuntDeInteresBase(const PuntDeInteresBase& other) 
		{
			m_coord = other.m_coord;
			m_name = other.m_name;
		};

		virtual string getName();
		Coordinate getCoord();
		virtual unsigned int getColor();
		virtual PuntDeInteresBase* clone() ;

};