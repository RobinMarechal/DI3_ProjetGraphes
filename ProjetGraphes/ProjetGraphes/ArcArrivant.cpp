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
	if (ARCgetSommetParent() == nullptr || ARCgetSommetVise() == nullptr)
	{
		return true;
	}

	else if (ARCgetSommetParent()->SOMgetNumero() == ARRobjet.ARCgetSommetParent()->SOMgetNumero()
			&& ARCgetSommetVise()->SOMgetNumero() == ARRobjet.ARCgetSommetVise()->SOMgetNumero())
	{
		return (ARCgetSommetParent() == ARRobjet.ARCgetSommetParent()) && (ARCgetSommetVise() == ARRobjet.ARCgetSommetVise());
	}

	else
	{
		return false;
	}
}

bool CArcArrivant::operator!=(CArcArrivant & ARRobjet) const
{
	return false;
}

void CArcArrivant::ARCdebug() const
{
	cout << ARCgetSommetParent()->SOMgetNumero() << " <- " << ARCgetSommetVise()->SOMgetNumero() << endl;
}