#include "Sommet.h"
#include "constantes.h"
#include "Arc.h"

CSommet::CArc::CArc(CSommet * pSOMsommetVise)
{
	pSOMARCsommetVise = pSOMsommetVise;
}

CSommet::CArc::CArc(CArc & ARCobjet)
{
	pSOMARCsommetVise = ARCobjet.pSOMARCsommetVise;
}

CSommet::CArc::~CArc()
{
}

bool CSommet::CArc::operator==(CArc & ARCobjet) const
{
	return false;
}

bool CSommet::CArc::operator!=(CArc & ARCobjet) const
{
	return false;
}

CSommet * CSommet::CArc::ARCgetSommetVise() const
{
	return nullptr;
}
