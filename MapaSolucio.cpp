#include"MapaSolucio.h"
#include "CamiSolucio.h"

void MapaSolucio::getPdis(vector<PuntDeInteresBase*>& pInteres)
{
	Coordinate c;
	c.lat = 41.4918606;
	c.lon = 2.1465411;
	PuntInteresBotigaSolucio  p1("Millor Pastisseria", "bakery", "", c, false);

	c.lat = 41.4902204;
	c.lon = 2.1406477;
	PuntInteresRestaurantSolucio  p2(c, "El Millor Restaurant", "regional", true);

	pInteres.push_back(&p1);
	pInteres.push_back(&p2);

}
void MapaSolucio::getCamins(vector<CamiBase*>&camins)
{
	CamiSolucio c;
	c.setCami(c.getCamiCoords());
	camins.push_back(&c);
}

