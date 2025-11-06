#include "PuntInteresRestaurantSolucio.h"


unsigned int PuntInteresRestaurantSolucio::getColor() {
	if (tipusDeCuina == "pizza" && FacilitaAccesMR)
		return 0x7FFFD4;
	if (tipusDeCuina == "chinese")
		return 0x00FFFF;
	if (FacilitaAccesMR)
		return 0x5D3FD3;
	return PuntDeInteresBase::getColor();
}