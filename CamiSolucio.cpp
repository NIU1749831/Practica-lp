#include"pch.h"
#include "CamiSolucio.h"

CamiSolucio* CamiSolucio::clone()
{
	return new CamiSolucio(*this);
}

vector<Coordinate> CamiSolucio::getCamiCoords()
{
	return m_cami;
}

