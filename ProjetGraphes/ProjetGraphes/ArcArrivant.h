#ifndef CARC_ARRIVANT_H
#define CARC_ARRIVANT_H

#include "Sommet.h"
#include "Arc.h"

class CArcArrivant : public CArc
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
	CArcArrivant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entrée : une instance de CArcArrivant.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la recopie de l'arc passé en paramètre.
	******************************************/
	CArcArrivant(CArcArrivant & ARRobjet);


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : rien.
	******************************************/
	~CArcArrivant();


	/*****************************************
	Surcharge de l'opérateur =.
	******************************************
	Entrée : une instance de CArcArrivant.
	Nécessite : rien.
	Sortie : une instance de CArcArrivant.
	Entraîne : l'affectation de l'arc passé en paramètre.
	******************************************/
	CArcArrivant & operator=(CArcArrivant & ARRobjet);


	/*****************************************
	Surcharge de l'opérateur ==.
	******************************************
	Entrée : une instance de CArcArrivant.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : les arcs sont identiques)
				ou (false : les arcs sont différents).
	******************************************/
	bool operator==(CArcArrivant & ARRobjet) const;


	/*****************************************
	Surcharge de l'opérateur !=.
	******************************************
	Entrée : une instance de CArcArrivant.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : les arcs sont différents)
				ou (false : les arcs sont identiques).
	******************************************/
	bool operator!=(CArcArrivant & ARRobjet) const;
};

#endif // C_LIEN_SOMMET_PREDECESSEUR_H
