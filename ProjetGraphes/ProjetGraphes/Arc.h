#ifndef CARC_H
#define CARC_H

#include "Sommet.h"

class CSommet;

/********************************
Classe représentant un arc 
orienté entre deux sommets
*********************************/
class CArc
{
private:

	CSommet * pSOMARCsommetVise; // Sommet visé par l'arc
	CSommet * pSOMARCsommetParent; // Sommet de départ de l'arc

protected:

	/*****************************************
	Recopie d'un arc.
	******************************************
	Entrée : une instance de CArc.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la recopie de l'arc passé en paramètre.
	******************************************/
	void ARCrecopier(CArc & ARCobjet);

public:

	/*****************************************
	Constructeur à deux arguments.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la création d'un arc entre les deux sommets passés en paramètre.
	******************************************/
	CArc(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entrée : une instance de CArc.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la recopie de l'arc passé en paramètre.
	******************************************/
	CArc(CArc & ARCarc);


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : rien.
	******************************************/
	virtual ~CArc();


	/*****************************************
	Lecture du sommet visé.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un pointeur sur le CSommet visé.
	Entraîne : rien.
	******************************************/
	CSommet * ARCgetSommetVise() const { return pSOMARCsommetVise; }


	/*****************************************
	Lecture du sommet parent.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un pointeur sur le CSommet parent.
	Entraîne : rien.
	******************************************/
	CSommet * ARCgetSommetParent() const { return pSOMARCsommetParent; }
};

#endif // CARC_H
