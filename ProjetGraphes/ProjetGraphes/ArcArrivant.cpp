#include "ArcArrivant.h"
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
CArcArrivant::CArcArrivant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise) : CArc( pSOMsommetParent, pSOMsommetVise)
{
}


/*****************************************
Constructeur de recopie.
******************************************
Entr�e : une instance de CArcArrivant.
N�cessite : rien.
Sortie : rien.
Entra�ne : la recopie de l'arc pass� en param�tre.
******************************************/
CArcArrivant::CArcArrivant(CArcArrivant & ARRobjet) : CArc(ARRobjet)
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
CArcArrivant::~CArcArrivant()
{
}


/*****************************************
Surcharge de l'op�rateur =.
******************************************
Entr�e : une instance de CArcArrivant.
N�cessite : rien.
Sortie : une instance de CArcArrivant.
Entra�ne : l'affectation de l'arc pass� en param�tre.
******************************************/
CArcArrivant & CArcArrivant::operator=(CArcArrivant & ARRobjet)
{
	ARCrecopier(ARRobjet);

	return *this;
}


/*****************************************
Surcharge de l'op�rateur ==.
******************************************
Entr�e : une instance de CArcArrivant.
N�cessite : rien.
Sortie : un bool�en.
Entra�ne : (true : les arcs sont identiques)
			ou (false : les arcs sont diff�rents).
******************************************/
bool CArcArrivant::operator==(CArcArrivant & ARRobjet) const
{
	return (*ARCgetSommetVise() == *ARRobjet.ARCgetSommetVise()) && (*ARCgetSommetParent() == *ARRobjet.ARCgetSommetParent());
}


/*****************************************
Surcharge de l'op�rateur !=.
******************************************
Entr�e : une instance de CArcArrivant.
N�cessite : rien.
Sortie : un bool�en.
Entra�ne : (true : les arcs sont diff�rents)
			ou (false : les arcs sont identiques).
******************************************/
bool CArcArrivant::operator!=(CArcArrivant & ARRobjet) const
{
	return !(*this == ARRobjet);
}