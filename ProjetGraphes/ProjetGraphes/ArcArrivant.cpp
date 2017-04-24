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

CArcArrivant::CArcArrivant::~CArcArrivant()
{
}

CArcArrivant & CArcArrivant::operator=(CArcArrivant & ARRobjet)
{
	// Appel au constructeur de recopie
	return *this; // CArcArrivant(ARRobjet);
}

bool CArcArrivant::operator==(CArcArrivant & ARRobjet) const
{
	return false;
}

bool CArcArrivant::operator!=(CArcArrivant & ARRobjet) const
{
	return false;
}

void CArcArrivant::ARCdebug() const
{
	cout << ARCgetSommetParent()->SOMgetNumero() << " <- " << ARCgetSommetVise()->SOMgetNumero() << endl;
}