#pragma once
#include"../VSCE2022 - ALUMNES P1/LP-OSM-DLL-2022/MapaBase.h"
#include"puntInteresBotigaSolucio.h"
#include"puntInteresRestaurantSolucio.h"

class MapaSolucio : public MapaBase
{
private:

public:
	void getPdis(vector<PuntDeInteresBase*>&) override;
	void getCamins(vector<CamiBase*>&) override;
	void parsejaXmlElements(vector<XmlElement>& xmlElements) override;
};