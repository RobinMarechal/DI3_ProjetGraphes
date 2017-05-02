#include "Sommet.h"
#include "constantes.h"
#include "Arc.h"

/*****************************************
Recopie d'un arc.
******************************************
Entr�e : une r�f�rence sur une instance de CArc.
N�cessite : rien.
Sortie : rien.
Entra�ne : la recopie de l'arc pass� en param�tre.
******************************************/
void CArc::ARCrecopier(CArc & ARCobjet)
{
	pSOMARCsommetVise = ARCobjet.pSOMARCsommetVise;
	pSOMARCsommetParent = ARCobjet.pSOMARCsommetParent;
}


/*****************************************
Constructeur � deux arguments.
******************************************
Entr�e : un pointeur sur une instance de Csommet parent,
		 un pointeur sur une instance de CSommet vis�.
N�cessite : rien.
Sortie : rien.
Entra�ne : la cr�ation d'un arc entre les deux sommets pass�s en param�tre.
******************************************/
CArc::CArc(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise)
{
	pSOMARCsommetVise = pSOMsommetVise;
	pSOMARCsommetParent = pSOMsommetParent;
}


/*****************************************
Constructeur de recopie.
******************************************
Entr�e : une r�f�rence sur une instance de CArc.
N�cessite : rien.
Sortie : rien.
Entra�ne : la recopie de l'arc pass� en param�tre.
******************************************/
CArc::CArc(CArc & ARCobjet)
{
	ARCrecopier(ARCobjet);
}


/*****************************************
Destructeur.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : rien.
******************************************/
CArc::~CArc()
{
	// Rien a d�sallouer
}


/*****************************************
Lecture du sommet vis�.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : un pointeur sur le CSommet vis�.
Entra�ne : rien.
******************************************/
CSommet * CArc::ARCgetSommetVise() const
{
	return pSOMARCsommetVise;
}


/*****************************************
Lecture du sommet parent.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : un pointeur sur le CSommet parent.
Entra�ne : rien.
******************************************/
CSommet * CArc::ARCgetSommetParent() const
{
	return pSOMARCsommetParent;
}


/*****************************************
Affectation du sommet vis�.
******************************************
Entr�e : un pointeur sur une instance de CSommet.
N�cessite : rien.
Sortie : rien.
Entra�ne : l'affectation du sommet vis�.
******************************************/
void CArc::ARCsetSommetVise(CSommet * pSOMsommetVise)
{
	pSOMARCsommetVise = pSOMsommetVise;
}


/*****************************************
Affectation du sommet parent.
******************************************
Entr�e : un pointeur sur une instance de CSommet.
N�cessite : rien.
Sortie : rien.
Entra�ne : l'affectation du sommet parent.
******************************************/
void CArc::ARCsetSommetParent(CSommet * pSOMsommetParent)
{
	pSOMARCsommetParent = pSOMsommetParent;
}
