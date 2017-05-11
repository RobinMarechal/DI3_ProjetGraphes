#include "ArcPartant.h"
#include "Arc.h"
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
CArcPartant::CArcPartant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise) : CArc(pSOMsommetParent, pSOMsommetVise)
{
}


/*****************************************
Constructeur de recopie.
******************************************
Entrée : une instance de CArcPartant.
Nécessite : rien.
Sortie : rien.
Entraîne : la recopie de l'arc passé en paramètre.
******************************************/
CArcPartant::CArcPartant(CArcPartant & ARRobjet) : CArc(ARRobjet)
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
CArcPartant::~CArcPartant()
{
}


/*****************************************
Surcharge de l'opérateur =.
******************************************
Entrée : une instance de CArcPartant.
Nécessite : rien.
Sortie : une instance de CArcPartant.
Entraîne : l'affectation de l'arc passé en paramètre.
******************************************/
CArcPartant & CArcPartant::operator=(CArcPartant & ARRobjet)
{
	ARCrecopier(ARRobjet);

	return *this;
}


/*****************************************
Surcharge de l'opérateur ==.
******************************************
Entrée : une instance de CArcPartant.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les arcs sont identiques)
			ou (false : les arcs sont différents).
******************************************/
bool CArcPartant::operator==(CArcPartant & ARRobjet) const
{
	return (*ARCgetSommetVise() == *ARRobjet.ARCgetSommetVise()) && (*ARCgetSommetParent() == *ARRobjet.ARCgetSommetParent());
}


/*****************************************
Surcharge de l'opérateur !=.
******************************************
Entrée : une instance de CArcPartant.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les arcs sont différents)
			ou (false : les arcs sont identiques).
******************************************/
bool CArcPartant::operator!=(CArcPartant & ARRobjet) const
{
	return !(*this == ARRobjet);
}