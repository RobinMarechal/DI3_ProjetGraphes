#include "constantes.h"
#include "ArcArrivant.h"

CSommet::CArcArrivant::CArcArrivant(CSommet * pSOMsommetVise) : CArc(pSOMsommetVise)
{
}

CSommet::CArcArrivant::CArcArrivant(CArcArrivant & ARRobjet) : CArc(ARRobjet)
{
}

CSommet::CArcArrivant::CArcArrivant(CArc & ARCobjet) : CArc(ARCobjet)
{
}

CSommet::CArcArrivant::CArcArrivant::~CArcArrivant()
{
}

CSommet::CArcArrivant & CSommet::CArcArrivant::operator=(CArc & ARCobjet)
{
	return *this;
}
