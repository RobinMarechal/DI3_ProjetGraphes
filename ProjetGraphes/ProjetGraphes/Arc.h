#ifndef CARC_H
#define CARC_H

#include "Sommet.h"

class CSommet;

// Relier 2 sommets pour former un arc
class CArc
{
private:

	CSommet * pSOMARCsommetVise; // Sommet vis� par l'arc
	CSommet * pSOMARCsommetParent; // Sommet de d�part de l'arc

protected:

	/*****************************************
	Recopie d'un arc.
	******************************************
	Entr�e : une r�f�rence sur une instance de CArc.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la recopie de l'arc pass� en param�tre.
	******************************************/
	void ARCrecopier(CArc & ARCobjet);

public:

	/*****************************************
	Constructeur � deux arguments.
	******************************************
	Entr�e : un pointeur sur une instance de Csommet parent,
			 un pointeur sur une instance de CSommet vis�.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la cr�ation d'un arc entre les deux sommets pass�s en param�tre.
	******************************************/
	CArc(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entr�e : une r�f�rence sur une instance de CArc.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la recopie de l'arc pass� en param�tre.
	******************************************/
	CArc(CArc & ARCarc);


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : rien.
	******************************************/
	~CArc();


	/*****************************************
	Lecture du sommet vis�.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : un pointeur sur le CSommet vis�.
	Entra�ne : rien.
	******************************************/
	CSommet * ARCgetSommetVise() const;


	/*****************************************
	Lecture du sommet parent.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : un pointeur sur le CSommet parent.
	Entra�ne : rien.
	******************************************/
	CSommet * ARCgetSommetParent() const;


	/*****************************************
	Affectation du sommet vis�.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'affectation du sommet vis�.
	******************************************/
	void ARCsetSommetVise(CSommet * pSOMsommetVise);


	/*****************************************
	Affectation du sommet parent.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'affectation du sommet parent.
	******************************************/
	void ARCsetSommetParent(CSommet * pSOMsommetParent);

	// A supprimer ?
	virtual void ARCdebug() const = 0;
};

#endif // CARC_H
