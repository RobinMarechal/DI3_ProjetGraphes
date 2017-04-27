#include "ArcPartant.h"
#include "Arc.h"
#include "Sommet.h"

#include <iostream>

using namespace std;

CArcPartant::CArcPartant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise) : CArc(pSOMsommetParent, pSOMsommetVise)
{
}

CArcPartant::CArcPartant(CArcPartant & ARRobjet) : CArc(ARRobjet)
{
}

CArcPartant::~CArcPartant()
{
}

CArcPartant & CArcPartant::operator=(CArcPartant & ARRobjet)
{
	ARCrecopier(ARRobjet);

	return *this;
}

bool CArcPartant::operator==(CArcPartant & ARRobjet) const
{
	return (ARCgetSommetVise() == ARRobjet.ARCgetSommetVise()) && (ARCgetSommetParent() == ARRobjet.ARCgetSommetParent());
}

bool CArcPartant::operator!=(CArcPartant & ARRobjet) const
{
	return !(* this == ARRobjet);
}

void CArcPartant::ARCdebug() const
{
	cout << ARCgetSommetParent()->SOMgetNumero() << " -> " << ARCgetSommetVise()->SOMgetNumero() << endl;
}
