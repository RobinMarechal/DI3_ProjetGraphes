#include "Arc.h"



void CArc::ARCinit()
{
}

void CArc::ARCdetruire()
{
}

CArc::CArc(CListeArcs * pLISliste, CSommet * pSOMsommet)
{
	pLISARClisteArcs = pLISliste;
	pSOMARCsommet = pSOMsommet;
}

CArc::~CArc()
{
}

CSommet * CArc::ARCgetSommet() const
{
	return pSOMARCsommet;
}

CListeArcs * CArc::ARCgetListeArcs() const
{
	return pLISARClisteArcs;
}

std::ostream & operator<<(std::ostream & oFlux, CArc & ARCarc)
{
	oFlux << ARCarc.ARCgetSommet()->SOMgetNumero();

	return oFlux;
}
