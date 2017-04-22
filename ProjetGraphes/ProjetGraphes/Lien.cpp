#include "Lien.h"

CLien::CLien(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise)
{
	pSOMLIEsommetParent = pSOMsommetParent;
	pSOMLIEsommetVise = pSOMsommetVise;
}

CLien::CLien(CLien & CLien)
{
}

CLien::~CLien()
{
}

CLien & CLien::operator=(CLien & ARCarc)
{
	// TODO: insérer une instruction return ici
}

bool CLien::operator==(CLien & ARCarc) const
{
	return false;
}

bool CLien::operator!=(CLien & ARCarc) const
{
	return false;
}

void CLien::ARCdebug() const
{
}
