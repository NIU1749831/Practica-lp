#include"pch.h"
#include "CamiSolucio.h"

CamiSolucio* CamiSolucio::clone()
{
	return new CamiSolucio(*this);
}

vector<Coordinate> CamiSolucio::getCamiCoords()
{
	vector<Coordinate> c;
	for (auto& a : m_cami)
		c.push_back(a);
	return c;
}

