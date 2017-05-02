#include "Sommet.h"
#include "constantes.h"
#include "Arc.h"

/*****************************************
Recopie d'un arc.
******************************************
Entrée : une référence sur une instance de CArc.
Nécessite : rien.
Sortie : rien.
Entraîne : la recopie de l'arc passé en paramètre.
******************************************/
void CArc::ARCrecopier(CArc & ARCobjet)
{
	pSOMARCsommetVise = ARCobjet.pSOMARCsommetVise;
	pSOMARCsommetParent = ARCobjet.pSOMARCsommetParent;
}


/*****************************************
Constructeur à deux arguments.
******************************************
Entrée : un pointeur sur une instance de Csommet parent,
		 un pointeur sur une instance de CSommet visé.
Nécessite : rien.
Sortie : rien.
Entraîne : la création d'un arc entre les deux sommets passés en paramètre.
******************************************/
CArc::CArc(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise)
{
	pSOMARCsommetVise = pSOMsommetVise;
	pSOMARCsommetParent = pSOMsommetParent;
}


/*****************************************
Constructeur de recopie.
******************************************
Entrée : une référence sur une instance de CArc.
Nécessite : rien.
Sortie : rien.
Entraîne : la recopie de l'arc passé en paramètre.
******************************************/
CArc::CArc(CArc & ARCobjet)
{
	ARCrecopier(ARCobjet);
}


/*****************************************
Destructeur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : rien.
******************************************/
CArc::~CArc()
{
	// Rien a désallouer
}


/*****************************************
Lecture du sommet visé.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : un pointeur sur le CSommet visé.
Entraîne : rien.
******************************************/
CSommet * CArc::ARCgetSommetVise() const
{
	return pSOMARCsommetVise;
}


/*****************************************
Lecture du sommet parent.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : un pointeur sur le CSommet parent.
Entraîne : rien.
******************************************/
CSommet * CArc::ARCgetSommetParent() const
{
	return pSOMARCsommetParent;
}


/*****************************************
Affectation du sommet visé.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : l'affectation du sommet visé.
******************************************/
void CArc::ARCsetSommetVise(CSommet * pSOMsommetVise)
{
	pSOMARCsommetVise = pSOMsommetVise;
}


/*****************************************
Affectation du sommet parent.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : l'affectation du sommet parent.
******************************************/
void CArc::ARCsetSommetParent(CSommet * pSOMsommetParent)
{
	pSOMARCsommetParent = pSOMsommetParent;
}
