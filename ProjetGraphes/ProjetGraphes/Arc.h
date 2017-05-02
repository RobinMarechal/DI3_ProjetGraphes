#ifndef CARC_H
#define CARC_H

#include "Sommet.h"

class CSommet;

// Relier 2 sommets pour former un arc
class CArc
{
private:

	CSommet * pSOMARCsommetVise; // Sommet visé par l'arc
	CSommet * pSOMARCsommetParent; // Sommet de départ de l'arc

protected:

	/*****************************************
	Recopie d'un arc.
	******************************************
	Entrée : une référence sur une instance de CArc.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la recopie de l'arc passé en paramètre.
	******************************************/
	void ARCrecopier(CArc & ARCobjet);

public:

	/*****************************************
	Constructeur à deux arguments.
	******************************************
	Entrée : un pointeur sur une instance de Csommet parent,
			 un pointeur sur une instance de CSommet visé.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la création d'un arc entre les deux sommets passés en paramètre.
	******************************************/
	CArc(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entrée : une référence sur une instance de CArc.
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
	~CArc();


	/*****************************************
	Lecture du sommet visé.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un pointeur sur le CSommet visé.
	Entraîne : rien.
	******************************************/
	CSommet * ARCgetSommetVise() const;


	/*****************************************
	Lecture du sommet parent.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un pointeur sur le CSommet parent.
	Entraîne : rien.
	******************************************/
	CSommet * ARCgetSommetParent() const;


	/*****************************************
	Affectation du sommet visé.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'affectation du sommet visé.
	******************************************/
	void ARCsetSommetVise(CSommet * pSOMsommetVise);


	/*****************************************
	Affectation du sommet parent.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'affectation du sommet parent.
	******************************************/
	void ARCsetSommetParent(CSommet * pSOMsommetParent);

	// A supprimer ?
	virtual void ARCdebug() const = 0;
};

#endif // CARC_H
