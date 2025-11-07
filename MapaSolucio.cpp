
#include"MapaSolucio.h"
#include "CamiSolucio.h"
#include<iostream>


void MapaSolucio::getPdis(vector<PuntDeInteresBase*>& pInteres)
{
	Coordinate c;
	c.lat = 41.4918606;
	c.lon = 2.1465411;
	PuntInteresBotigaSolucio  p1("Millor Pastisseria", "bakery", "7:00", c, false);


	c.lat = 41.4902204;
	c.lon = 2.1406477;
	PuntInteresRestaurantSolucio  p2(c, "El Millor Restaurant", "regional", true);

	pInteres.push_back(p1.clone());
	pInteres.push_back(p2.clone());

}

void MapaSolucio::getCamins(vector<CamiBase*>& camins)
{
	CamiSolucio c;
	c.setCami(c.getCamiCoords());
	camins.push_back(&c);
}

void MapaSolucio::parsejaXmlElements(vector<XmlElement>& xmlElements)
{
	cout << "NIGER" << endl;
}

