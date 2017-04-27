#include "constantes.h"
#include "ArcArrivant.h"
#include "Sommet.h"

#include <iostream>

using namespace std;

CArcArrivant::CArcArrivant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise) : CArc( pSOMsommetParent, pSOMsommetVise)
{
}

CArcArrivant::CArcArrivant(CArcArrivant & ARRobjet) : CArc(ARRobjet)
{
}

CArcArrivant::~CArcArrivant()
{
}

CArcArrivant & CArcArrivant::operator=(CArcArrivant & ARRobjet)
{
	// Appel au constructeur de recopie
	ARCsetSommetParent(ARRobjet.ARCgetSommetParent());
	ARCsetSommetVise(ARRobjet.ARCgetSommetVise());

	return *this;
}

bool CArcArrivant::operator==(CArcArrivant & ARRobjet) const
{
	return (ARCgetSommetVise() == ARRobjet.ARCgetSommetVise()) && (ARCgetSommetParent() == ARRobjet.ARCgetSommetParent());
}

bool CArcArrivant::operator!=(CArcArrivant & ARRobjet) const
{
	return !(* this == ARRobjet);
}

void CArcArrivant::ARCdebug() const
{
	cout << ARCgetSommetParent()->SOMgetNumero() << " <- " << ARCgetSommetVise()->SOMgetNumero() << endl;
}