#include "Sommet.h"
#include "Arc.h"

/*****************************************
Recopie d'un arc.
******************************************
Entrée : une instance de CArc.
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
Entrée : un pointeur sur une instance de CSommet.
Entrée : un pointeur sur une instance de CSommet.
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
Entrée : une instance de CArc.
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
