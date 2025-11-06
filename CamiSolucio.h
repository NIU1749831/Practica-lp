#include "..\proyecto\VSCE2022 - ALUMNES P1\LP-OSM-DLL-2022\CamiBase.h"

/*
Pare
class CamiBase {
	public:
		virtual std::vector<Coordinate> getCamiCoords() = 0;
};


*/
class CamiSolucio : public CamiBase
{
public:
	CamiSolucio (){}
	CamiSolucio (vector<Coordinate>cami) : m_cami(cami) {}

	void setCami(vector<Coordinate>cami) { m_cami = cami; }

	vector<Coordinate> getCamiCoords() override;
private:
	vector<Coordinate> m_cami;
};