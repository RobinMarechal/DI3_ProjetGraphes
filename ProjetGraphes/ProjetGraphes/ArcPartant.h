#ifndef CARC_PARTANT_H
#define CARC_PARTANT_H

#include "Sommet.h"
#include "Arc.h"


/********************************
Classe repr�sentant un arc
partant d'un sommet
*********************************/
class CArcPartant : public CArc
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
	CArcPartant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entr�e : une instance de CArcPartant.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la recopie de l'arc pass� en param�tre.
	******************************************/
	CArcPartant(CArcPartant & ARRobjet);


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : rien.
	******************************************/
	~CArcPartant();


	/*****************************************
	Surcharge de l'op�rateur =.
	******************************************
	Entr�e : une instance de CArcPartant.
	N�cessite : rien.
	Sortie : une instance de CArcPartant.
	Entra�ne : l'affectation de l'arc pass� en param�tre.
	******************************************/
	CArcPartant & operator=(CArcPartant & ARRobjet);


	/*****************************************
	Surcharge de l'op�rateur ==.
	******************************************
	Entr�e : une instance de CArcPartant.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les arcs sont identiques)
				ou (false : les arcs sont diff�rents).
	******************************************/
	bool operator==(CArcPartant & ARRobjet) const;


	/*****************************************
	Surcharge de l'op�rateur !=.
	******************************************
	Entr�e : une instance de CArcPartant.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les arcs sont diff�rents)
				ou (false : les arcs sont identiques).
	******************************************/
	bool operator!=(CArcPartant & ARRobjet) const;
};

#endif // CARC_PARTANT_H
