#include "Sommet.h"
#include "constantes.h"
#include "Arc.h"

CArc::CArc(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise)
{
	pSOMARCsommetVise = pSOMsommetVise;
}

CArc::CArc(CArc & ARCobjet)
{
	pSOMARCsommetVise = ARCobjet.pSOMARCsommetVise;
}

CArc::~CArc()
{
	// Rien a désallouer
}

CSommet * CArc::ARCgetSommetVise() const
{
	return pSOMARCsommetVise;
}

CSommet * CArc::ARCgetSommetParent() const
{
	return pSOMARCsommetParent;
}
