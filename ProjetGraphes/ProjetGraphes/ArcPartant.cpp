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
	// Appel au constructeur de recopie
	return *this; // CArcPartant(ARRobjet);
}

bool CArcPartant::operator==(CArcPartant & ARRobjet) const
{
	return false;
}

bool CArcPartant::operator!=(CArcPartant & ARRobjet) const
{
	return false;
}

void CArcPartant::ARCdebug() const
{
	cout << ARCgetSommetParent()->SOMgetNumero() << " -> " << ARCgetSommetVise()->SOMgetNumero() << endl;
}
