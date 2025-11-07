#pragma once
#include"MapaBase.h"
#include"PuntDeInteresBotigaSolucio.h"
#include"PuntDeInteresRestaurantSolucio.h"

class MapaSolucio : public MapaBase
{
private:

public:
	MapaSolucio(){};

	void getPdis(vector<PuntDeInteresBase*>&) override;
	void getCamins(vector<CamiBase*>&) override;
	void parsejaXmlElements(vector<XmlElement>& xmlElements) override;
};