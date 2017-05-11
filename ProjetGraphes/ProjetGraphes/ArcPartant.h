#ifndef CARC_PARTANT_H
#define CARC_PARTANT_H

#include "Sommet.h"
#include "Arc.h"


/********************************
Classe représentant un arc
partant d'un sommet
*********************************/
class CArcPartant : public CArc
{
public:

	/*****************************************
	Constructeur à deux arguments.
	******************************************
	Entrée : un pointeur sur une instance du CSommet parent,
	Entrée : un pointeur sur une instance du CSommet visé.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la création d'un arc.
	******************************************/
	CArcPartant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entrée : une instance de CArcPartant.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la recopie de l'arc passé en paramètre.
	******************************************/
	CArcPartant(CArcPartant & ARRobjet);


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : rien.
	******************************************/
	~CArcPartant();


	/*****************************************
	Surcharge de l'opérateur =.
	******************************************
	Entrée : une instance de CArcPartant.
	Nécessite : rien.
	Sortie : une instance de CArcPartant.
	Entraîne : l'affectation de l'arc passé en paramètre.
	******************************************/
	CArcPartant & operator=(CArcPartant & ARRobjet);


	/*****************************************
	Surcharge de l'opérateur ==.
	******************************************
	Entrée : une instance de CArcPartant.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : les arcs sont identiques)
				ou (false : les arcs sont différents).
	******************************************/
	bool operator==(CArcPartant & ARRobjet) const;


	/*****************************************
	Surcharge de l'opérateur !=.
	******************************************
	Entrée : une instance de CArcPartant.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : les arcs sont différents)
				ou (false : les arcs sont identiques).
	******************************************/
	bool operator!=(CArcPartant & ARRobjet) const;
};

#endif // CARC_PARTANT_H
