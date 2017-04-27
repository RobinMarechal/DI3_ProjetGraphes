#include "Sommet.h"
#include "constantes.h"
#include "Arc.h"

void CArc::ARCrecopier(CArc & ARCobjet)
{
	pSOMARCsommetVise = ARCobjet.pSOMARCsommetVise;
	pSOMARCsommetParent = ARCobjet.pSOMARCsommetParent;
}

CArc::CArc(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise)
{
	pSOMARCsommetVise = pSOMsommetVise;
	pSOMARCsommetParent = pSOMsommetParent;
}

CArc::CArc(CArc & ARCobjet)
{
	ARCrecopier(ARCobjet);
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

void CArc::ARCsetSommetVise(CSommet * pSOMsommetVise)
{
	pSOMARCsommetVise = pSOMsommetVise;
}

void CArc::ARCsetSommetParent(CSommet * pSOMsommetParent)
{
	pSOMARCsommetParent = pSOMsommetParent;
}
