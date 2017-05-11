#include "ArcArrivant.h"
#include "Sommet.h"

#include <iostream>

using namespace std;

/*****************************************
Constructeur à deux arguments.
******************************************
Entrée : un pointeur sur une instance du CSommet parent,
Entrée : un pointeur sur une instance du CSommet visé.
Nécessite : rien.
Sortie : rien.
Entraîne : la création d'un arc.
******************************************/
CArcArrivant::CArcArrivant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise) : CArc( pSOMsommetParent, pSOMsommetVise)
{
}


/*****************************************
Constructeur de recopie.
******************************************
Entrée : une instance de CArcArrivant.
Nécessite : rien.
Sortie : rien.
Entraîne : la recopie de l'arc passé en paramètre.
******************************************/
CArcArrivant::CArcArrivant(CArcArrivant & ARRobjet) : CArc(ARRobjet)
{
}


/*****************************************
Destructeur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : rien.
******************************************/
CArcArrivant::~CArcArrivant()
{
}


/*****************************************
Surcharge de l'opérateur =.
******************************************
Entrée : une instance de CArcArrivant.
Nécessite : rien.
Sortie : une instance de CArcArrivant.
Entraîne : l'affectation de l'arc passé en paramètre.
******************************************/
CArcArrivant & CArcArrivant::operator=(CArcArrivant & ARRobjet)
{
	ARCrecopier(ARRobjet);

	return *this;
}


/*****************************************
Surcharge de l'opérateur ==.
******************************************
Entrée : une instance de CArcArrivant.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les arcs sont identiques)
			ou (false : les arcs sont différents).
******************************************/
bool CArcArrivant::operator==(CArcArrivant & ARRobjet) const
{
	return (*ARCgetSommetVise() == *ARRobjet.ARCgetSommetVise()) && (*ARCgetSommetParent() == *ARRobjet.ARCgetSommetParent());
}


/*****************************************
Surcharge de l'opérateur !=.
******************************************
Entrée : une instance de CArcArrivant.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les arcs sont différents)
			ou (false : les arcs sont identiques).
******************************************/
bool CArcArrivant::operator!=(CArcArrivant & ARRobjet) const
{
	return !(*this == ARRobjet);
}