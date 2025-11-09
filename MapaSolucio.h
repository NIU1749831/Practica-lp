#pragma once
#include"MapaBase.h"
#include"CamiSolucio.h"
#include"DerivadesPuntsInteres.h"


class MapaSolucio : public MapaBase
{
private:
	vector<PuntDeInteresBase*> m_pInteres;
	vector<CamiSolucio*> m_camins;
	vector<Node> m_nodesVisitats;
public:
	MapaSolucio(){};
	~MapaSolucio();

	void getPdis(vector<PuntDeInteresBase*>&) override;
	void getCamins(vector<CamiBase*>&) override;
	void parsejaXmlElements(vector<XmlElement>& xmlElements) override;
};