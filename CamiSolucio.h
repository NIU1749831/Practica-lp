#include "CamiBase.h"
#include<vector>
using namespace std;
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