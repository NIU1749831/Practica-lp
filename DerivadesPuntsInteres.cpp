#include"pch.h"
#include "DerivadesPuntsInteres.h"

//---PuntInteresBotigaSolucio---//

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


//---PuntInteresRestaurantSolucio---//
unsigned int PuntInteresRestaurantSolucio::getColor() {
	if (tipusDeCuina == "pizza" && FacilitaAccesMR)
		return 0x7FFFD4;
	if (tipusDeCuina == "chinese")
		return 0x00FFFF;
	if (FacilitaAccesMR)
		return 0x5D3FD3;
	return PuntDeInteresBase::getColor();
}

PuntInteresRestaurantSolucio* PuntInteresRestaurantSolucio::clone()
{
	return new PuntInteresRestaurantSolucio(*this);
}

//---PuntInteresGenericSolucio---//
PuntInteresGenericSolucio* PuntInteresGenericSolucio::clone()
{
	return new PuntInteresGenericSolucio(*this);
}