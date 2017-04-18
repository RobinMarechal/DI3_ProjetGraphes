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

CArc::CArc(CArc & ARCobjet)
{
	
}

CArc::~CArc()
{
}

CSommet * CArc::ARCgetSommet() const
{
	return pSOMARCsommet;
}

CListeArcs CArc::ARCgetListeArcs() const
{
	return *pLISARClisteArcs;
}

void CArc::ARCdebug() const
{
}

std::ostream & operator<<(std::ostream & oFlux, CArc & ARCarc)
{
	oFlux << ARCarc.ARCgetSommet()->SOMgetNumero();

	bool bSuccesseur = false;
	if (ARCarc.ARCgetListeArcs().LISgetSommet()->SOMgetListeSuccesseurs().LISpossede(ARCarc.ARCgetSommet()))
	{
		bSuccesseur = true;
	}

	oFlux << ARCarc.ARCgetListeArcs().LISgetSommet()->SOMgetNumero();

	if (bSuccesseur)
	{
		oFlux << "->";
	}
	else
	{
		oFlux << "<-";
	}

	oFlux << ARCarc.ARCgetSommet()->SOMgetNumero();

	return oFlux;
}
