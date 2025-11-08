#pragma once
#include"MapaBase.h"
#include"CamiSolucio.h"
#include"DerivadesPuntsInteres.h"


class MapaSolucio : public MapaBase
{
private:
	vector<CamiSolucio*> m_camins;
	vector<PuntDeInteresBase*> m_pInteres;
	vector<PuntDeInteresBase*> m_pHighway;
public:
	MapaSolucio(){};

	void getPdis(vector<PuntDeInteresBase*>&) override;
	void getCamins(vector<CamiBase*>&) override;
	void parsejaXmlElements(vector<XmlElement>& xmlElements) override;
};