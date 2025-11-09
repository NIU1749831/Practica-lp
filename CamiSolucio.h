#include "CamiBase.h"
#include<vector>
using namespace std;

typedef struct {
	Coordinate c;
	string id;
} Node;

class CamiSolucio : public CamiBase
{
public:
	CamiSolucio (){}
	CamiSolucio (vector<Coordinate>cami) : m_cami(cami) {}


	void setTipus(const string& nom) { m_tipus = nom; }
	void setCami(vector<Coordinate>cami) { m_cami = cami; }
	void addCami(const Coordinate& c) { m_cami.insert(m_cami.cbegin(), c); }
	void addRef(const string& r) { m_referencies.push_back(r); }

	string getTipus() const { return m_tipus; }
	vector<string> getRefes() const { return m_referencies; }
	vector<Coordinate> getCamiCoords() override;

	CamiSolucio* clone() override;
private:
	string m_tipus;
	vector<Coordinate> m_cami;
	vector<string> m_referencies;
};