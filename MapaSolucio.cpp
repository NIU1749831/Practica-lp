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

void MapaSolucio::getPdis(vector<PuntDeInteresBase*>& pInteres)
{
	for (auto& a : m_pInteres)
		pInteres.push_back(a);
}

void MapaSolucio::getCamins(vector<CamiBase*>& camins)
{
	CamiSolucio* c = new CamiSolucio;
	c->setCami(c->getCamiCoords());
	camins.push_back(c);
}

void MapaSolucio::parsejaXmlElements(vector<XmlElement>& XmlElements)
{
	bool restaurant = false, botiga = false;
	for (auto& element : XmlElements)
	{
		//punt interes
		if (element.id_element == "node" && !element.fills.empty())
		{
			string nom, lat, lon, timestamp, tipe, opHours;
			bool chair;

			//guarda valores de lat, long i timestamp del pdi
			for (auto& atribut : element.atributs)
			{
				if (atribut.first == "lat") lat = atribut.second;
				else if (atribut.first == "lon") lon = atribut.second;
				else if (atribut.first == "timestamp") timestamp = atribut.second;
			}

			//mirar los hijo
			for (auto& fill : element.fills)
			{
				PAIR_ATTR_VALUE kvVector = Util::kvDeTag(fill.second);

				//guardas el valor de las variables
				if (kvVector.first == "name") nom = kvVector.second;
				else if (kvVector.first == "wheelchair") chair = kvVector.second == "yes" ? true : false;
				else if (kvVector.first == "cuisine" || kvVector.first == "shop")tipe = kvVector.second;
				else if (kvVector.second == "restaurant") restaurant = true;
				else if (kvVector.first == "shop") botiga = true;
				else if (kvVector.first == "opening_hours") opHours = kvVector.second;
			}

			if (nom != "undefinit" && (restaurant || botiga))
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
	}
}

