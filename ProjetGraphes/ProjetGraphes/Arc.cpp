#include "Sommet.h"
#include "Arc.h"

/*****************************************
Recopie d'un arc.
******************************************
Entr�e : une instance de CArc.
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
Entr�e : un pointeur sur une instance de CSommet.
Entr�e : un pointeur sur une instance de CSommet.
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
Entr�e : une instance de CArc.
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
