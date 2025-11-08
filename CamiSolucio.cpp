#include"pch.h"
#include "CamiSolucio.h"

vector<Coordinate> CamiSolucio::getCamiCoords()
{
	//hace falta hacer un push de objeto dinamico
	Coordinate c1, c2, c3, c4;
	vector<Coordinate>cordenadas;
	c1.lat = 41.4928803;
	c1.lon = 2.1452381;
	c2.lat = 41.4929072;
	c2.lon = 2.1452474;
	c3.lat = 41.4933070;
	c3.lon = 2.1453852;
	c4.lat = 41.4939882;
	c4.lon = 2.1456419;
	
	cordenadas.push_back(c1);
	cordenadas.push_back(c2);
	cordenadas.push_back(c3);
	cordenadas.push_back(c4);
	return cordenadas;
}