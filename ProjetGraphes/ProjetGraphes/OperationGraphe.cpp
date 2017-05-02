#include "OperationGraphe.h"

#include "Graphe.h"
#include "Sommet.h"
#include "ArcArrivant.h"
#include "ArcPartant.h"
#include "constantes.h"
#include "Cexception.h"
#include "helpers.h"

/*****************************************
Constructeur par d�faut.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : rien.
******************************************/
COperationGraphe::COperationGraphe()
{
}


/*****************************************
Destructeur.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : rien.
******************************************/
COperationGraphe::~COperationGraphe()
{
}


/*****************************************
Inversion du graphe.
******************************************
Entr�e : une r�f�rence sur une instance de CGraphe.
N�cessite : rien.
Sortie : un pointeur sur une instance de CGraphe.
Entra�ne : l'inversion du graphe pass� en param�tre.
******************************************/
CGraphe * COperationGraphe::OPGinverserGraphe(const CGraphe & GRAgraphe) const
{
	unsigned int uiBoucle,
				 uiBouclePredecesseurs;

	unsigned int uiNbSommets,
				 uiNbPredecesseurs;

	uiNbSommets = GRAgraphe.GRAgetNbSommets();

	CGraphe * GRAresult = new CGraphe();

	// On cr�e � nouveau le m�me nombre de sommets.

	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		CSommet * SOMsommet = GRAgraphe.GRAgetSommetPosition(uiBoucle);
		CSommet * SOMsommetResult = GRAresult->GRAcreerSommet(SOMsommet->SOMgetNumero());
	}

	// On inverse les arcs.

	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		CSommet * SOMsommet = GRAgraphe.GRAgetSommetPosition(uiBoucle);
		CSommet * SOMsommetResult = GRAresult->GRAgetSommetPosition(uiBoucle);

		uiNbPredecesseurs = SOMsommet->SOMgetNbPredecesseurs();

		// Les pr�decesseurs de l'ancien graphe deviennent les nouveaux successeurs.
		// Les nouveaux pr�decesseurs sont ajout�s automatiquement.

		for (uiBouclePredecesseurs = 0; uiBouclePredecesseurs < uiNbPredecesseurs; uiBouclePredecesseurs++)
		{
			// On r�cup�re le num�ro du pr�decesseur du sommet �tudi� en cours.

			CSommet * SOMtmp = GRAresult->GRAgetSommetNumero(SOMsommet->SOMgetPredecesseur(uiBouclePredecesseurs)->SOMgetNumero());

			SOMsommetResult->SOMajouterSuccesseur(SOMtmp);
		}
	}

	return GRAresult;
}
