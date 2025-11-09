#include"pch.h"
#include"MapaSolucio.h"
#include"Util.h"
#include<iostream>

/*
Estructura dato XmlElement:

id_element,vector_atributos<que_att_es(key), valor>, vector_hijos<tipo_hijo(tag,way,...),vector_att_hijo(hash)<que_guarda_att,valor>

En el vector de parejas de los atributos del hijo, la primera pareja equivale al key y la segunda pareja quivale al value (hash)
	- de la primera pareja, k = que tipo de Tag es (highway, ..., la V es que sub tipo dentro de esa y la segunda pareja
	 k = ref, .. (depenent de  la priemra parella), i v = valor d'aquesta k
*/

MapaSolucio::~MapaSolucio()
{
	for (int i = 0; i < m_pInteres.size(); i++)
		delete m_pInteres[i];
	for (int i = 0; i < m_camins.size(); i++)
		delete m_camins[i];
}

void MapaSolucio::getPdis(vector<PuntDeInteresBase*>& pInteres)
{
	for (auto& a : m_pInteres)
		pInteres.push_back(a);
}

void MapaSolucio::getCamins(vector<CamiBase*>& camins)
{
	for (auto& nVisitat : m_nodesVisitats)
	{
		for (auto& cami : m_camins)
		{
			for (auto& ref : cami->getRefes())
			{
				if (nVisitat.id == ref)
				{
					cami->addCami(nVisitat.c);
				}
			}
			
		}
	}
	for (int i=0; i<m_camins.size(); i++)
		camins.push_back(m_camins[i]);
}

void MapaSolucio::parsejaXmlElements(vector<XmlElement>& XmlElements)
{
	bool restaurant = false, botiga = false, esHighway = false;

	for (auto& element : XmlElements)
	{
		string nom, lat, lon, timestamp, tipe, opHours;
		bool chair;

		if (element.id_element == "node")
		{
			Node n;

			for (auto& atribut : element.atributs)
			{
				if (atribut.first == "lat") lat = atribut.second;
				else if (atribut.first == "lon") lon = atribut.second;
				else if (atribut.first == "timestamp") timestamp = atribut.second;
				else if (atribut.first == "id") n.id = atribut.second;
			}

			n.c.lat = stod(lat);
			n.c.lon = stod(lon);

			m_nodesVisitats.push_back(n);			
		}
		//punt interes
		if (element.id_element == "node" && !element.fills.empty())
		{
			//mirar los hijo
			for (auto& fill : element.fills)
			{
				PAIR_ATTR_VALUE kvVector = Util::kvDeTag(fill.second);

				//guardas el valor de las variables
				if (kvVector.first == "name") nom = kvVector.second;
				else if (kvVector.first == "wheelchair") chair = kvVector.second == "yes" ? true : false;
				else if (kvVector.first == "cuisine" || kvVector.first == "shop")tipe = kvVector.second;
				else if (kvVector.first == "opening_hours") opHours = kvVector.second;
				if (kvVector.second == "restaurant") restaurant = true;
				if (kvVector.first == "shop") botiga = true;
				/*if (nom == "Gilgo")
					__debugbreak();*/
			}
			
			if (!nom.empty() && (restaurant || botiga))
			{
				Coordinate c;
				c.lat = stod(lat);
				c.lon = stod(lon);
				if (restaurant)
				{
					PuntInteresRestaurantSolucio restaurant(c, nom, tipe, chair);
					m_pInteres.push_back(restaurant.clone());
				}
				else if (botiga)
				{
					PuntInteresBotigaSolucio botiga(nom, tipe, opHours, c, chair);
					m_pInteres.push_back(botiga.clone());
				}
			}
		}
		else if (element.id_element == "way")
		{
			CamiSolucio c;
			for (int i = (element.fills.size()-2); i > 0; i--)
			{	
				CHILD_NODE fill = element.fills[i];
				PAIR_ATTR_VALUE kvVector = Util::kvDeTag(fill.second);
			
				if (kvVector.first == "highway" && !esHighway)
				{
					esHighway = true;
					c.setTipus(kvVector.second); //guardar tipus
				}
				else if (element.fills[i].first != "tag" && !esHighway) break; //break en cas de començar a mirar refes i no ser hihgway

				//omplir refes en cas de ser una referencia
				if (fill.first == "nd")
				{
					PAIR_ATTR_VALUE atribFill = fill.second[0];
					string refe = atribFill.second;
					c.addRef(refe);
				}
			}
			if (esHighway) m_camins.push_back(c.clone());
		}
		esHighway = false;
		restaurant = false;
		botiga = false;
	}
}

