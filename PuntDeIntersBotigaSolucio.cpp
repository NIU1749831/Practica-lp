
#include"PuntDeInteresBotigaSolucio.h"

unsigned int PuntInteresBotigaSolucio::getColor()
{
	if (m_tag == "supermarket")
		return 0xDFFF00;
	if (m_tag == "tobacco")
		return 0xFF7F50;
	if (m_tag == "bakery" && m_wealChair && m_openingHours.find("6:00 - 22 : 00") != -1)
		return 0x4CBB17;
	if (m_tag == "bakery")
		return 0xFA8072;
	return 0xFFEA00;
}		

PuntInteresBotigaSolucio* PuntInteresBotigaSolucio::clone()
{
	return new PuntInteresBotigaSolucio(*this);
}