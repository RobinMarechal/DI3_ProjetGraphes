#ifndef CARC_ARRIVANT_H
#define CARC_ARRIVANT_H

#include "Sommet.h"
#include "Arc.h"

class CArcArrivant : public CArc
{
public:

	/*****************************************
	Constructeur � deux arguments.
	******************************************
	Entr�e : un pointeur sur une instance du CSommet parent,
	Entr�e : un pointeur sur une instance du CSommet vis�.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la cr�ation d'un arc.
	******************************************/
	CArcArrivant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entr�e : une instance de CArcArrivant.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la recopie de l'arc pass� en param�tre.
	******************************************/
	CArcArrivant(CArcArrivant & ARRobjet);


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : rien.
	******************************************/
	~CArcArrivant();


	/*****************************************
	Surcharge de l'op�rateur =.
	******************************************
	Entr�e : une instance de CArcArrivant.
	N�cessite : rien.
	Sortie : une instance de CArcArrivant.
	Entra�ne : l'affectation de l'arc pass� en param�tre.
	******************************************/
	CArcArrivant & operator=(CArcArrivant & ARRobjet);


	/*****************************************
	Surcharge de l'op�rateur ==.
	******************************************
	Entr�e : une instance de CArcArrivant.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les arcs sont identiques)
				ou (false : les arcs sont diff�rents).
	******************************************/
	bool operator==(CArcArrivant & ARRobjet) const;


	/*****************************************
	Surcharge de l'op�rateur !=.
	******************************************
	Entr�e : une instance de CArcArrivant.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les arcs sont diff�rents)
				ou (false : les arcs sont identiques).
	******************************************/
	bool operator!=(CArcArrivant & ARRobjet) const;
};

#endif // C_LIEN_SOMMET_PREDECESSEUR_H
