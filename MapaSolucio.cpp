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
	bool trobat = false;
	for (auto& element : XmlElements)
	{
		

		//punt interes
		if (element.id_element == "node" && !element.fills.empty())
		{
			PuntInteresGenericSolucio p;
			//guarda valores de lat, long i timestamp del pdi
			for (auto& atribut : element.atributs)
			{
				if (atribut.first == "lat")
					p.setLat(stod(atribut.second));
				if (atribut.first == "lon")
					p.setLon(stod(atribut.second));
				if (atribut.first == "timestamp")
					p.setTimestamp(atribut.second);
			} 
			//mirar los hijo
			for (auto& fill : element.fills)
			{
				for(int i=0; i<fill.second.size(); i++)
				{ 
					//guardas el valor del nombre ne m_nom
					if (fill.second[i].second == "name")
						p.setNom(fill.second[i + 1].second);
					else if (fill.second[i].second == "wheelchair") //guardar valor accesibilidad
					{
						p.setRuedas(fill.second[i + 1].second == "yes" ? true : false);
					}
					else if (fill.second[i].first == "k") //guardar el resto de tags
					{
						vector<PAIR_ATTR_VALUE> convertir_kv;
						convertir_kv.push_back(fill.second[i]); //valor de k
						convertir_kv.push_back(fill.second[i+1]); //valor de v

						p.setTag(Util::kvDeTag(convertir_kv));
					}


					
				}
			}
			if (p.getName() == "undefinit")
				m_pHighway.push_back(p.clone());
			else
				m_pInteres.push_back(p.clone());

		}
	}
}

