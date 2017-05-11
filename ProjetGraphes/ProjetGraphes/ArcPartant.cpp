#include "ArcPartant.h"
#include "Arc.h"
#include "Sommet.h"

#include <iostream>

using namespace std;

/*****************************************
Constructeur � deux arguments.
******************************************
Entr�e : un pointeur sur une instance du CSommet parent,
Entr�e : un pointeur sur une instance du CSommet vis�.
N�cessite : rien.
Sortie : rien.
Entra�ne : la cr�ation d'un arc.
******************************************/
CArcPartant::CArcPartant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise) : CArc(pSOMsommetParent, pSOMsommetVise)
{
}


/*****************************************
Constructeur de recopie.
******************************************
Entr�e : une instance de CArcPartant.
N�cessite : rien.
Sortie : rien.
Entra�ne : la recopie de l'arc pass� en param�tre.
******************************************/
CArcPartant::CArcPartant(CArcPartant & ARRobjet) : CArc(ARRobjet)
{
}


/*****************************************
Destructeur.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : rien.
******************************************/
CArcPartant::~CArcPartant()
{
}


/*****************************************
Surcharge de l'op�rateur =.
******************************************
Entr�e : une instance de CArcPartant.
N�cessite : rien.
Sortie : une instance de CArcPartant.
Entra�ne : l'affectation de l'arc pass� en param�tre.
******************************************/
CArcPartant & CArcPartant::operator=(CArcPartant & ARRobjet)
{
	ARCrecopier(ARRobjet);

	return *this;
}


/*****************************************
Surcharge de l'op�rateur ==.
******************************************
Entr�e : une instance de CArcPartant.
N�cessite : rien.
Sortie : un bool�en.
Entra�ne : (true : les arcs sont identiques)
			ou (false : les arcs sont diff�rents).
******************************************/
bool CArcPartant::operator==(CArcPartant & ARRobjet) const
{
	return (*ARCgetSommetVise() == *ARRobjet.ARCgetSommetVise()) && (*ARCgetSommetParent() == *ARRobjet.ARCgetSommetParent());
}


/*****************************************
Surcharge de l'op�rateur !=.
******************************************
Entr�e : une instance de CArcPartant.
N�cessite : rien.
Sortie : un bool�en.
Entra�ne : (true : les arcs sont diff�rents)
			ou (false : les arcs sont identiques).
******************************************/
bool CArcPartant::operator!=(CArcPartant & ARRobjet) const
{
	return !(*this == ARRobjet);
}