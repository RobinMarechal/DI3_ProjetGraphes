#include "OperationGraphe.h"

#include "Graphe.h"
#include "Sommet.h"
#include "ArcArrivant.h"
#include "ArcPartant.h"
#include "Cexception.h"
#include "helpers.h"

/*****************************************
Constructeur par défaut.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : rien.
******************************************/
COperationGraphe::COperationGraphe()
{
}


/*****************************************
Destructeur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : rien.
******************************************/
COperationGraphe::~COperationGraphe()
{
}


/*****************************************
Inversion du graphe.
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : un pointeur sur une instance de CGraphe.
Entraîne : l'inversion du graphe passé en paramètre.
******************************************/
CGraphe COperationGraphe::OPGinverserGraphe(const CGraphe & GRAgraphe) const
{
	unsigned int uiBoucle,
				 uiBouclePredecesseurs;

	unsigned int uiNbSommets,
				 uiNbPredecesseurs;

	uiNbSommets = GRAgraphe.GRAgetNbSommets();

	CGraphe GRAresult;

	// On crée à nouveau le même nombre de sommets.

	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		CSommet * pSOMsommet = GRAgraphe.GRAgetSommetPosition(uiBoucle);
		CSommet * pSOMsommetResult = GRAresult.GRAcreerSommet(pSOMsommet->SOMgetNumero());
	}

	// On inverse les arcs.

	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		CSommet * pSOMsommet = GRAgraphe.GRAgetSommetPosition(uiBoucle);
		CSommet * pSOMsommetResult = GRAresult.GRAgetSommetPosition(uiBoucle);

		uiNbPredecesseurs = pSOMsommet->SOMgetNbPredecesseurs();

		// Les prédecesseurs de l'ancien graphe deviennent les nouveaux successeurs.
		// Les nouveaux prédecesseurs sont ajoutés automatiquement.

		for (uiBouclePredecesseurs = 0; uiBouclePredecesseurs < uiNbPredecesseurs; uiBouclePredecesseurs++)
		{
			// On récupère le numéro du prédecesseur du sommet étudié en cours.

			CSommet * pSOMtmp = GRAresult.GRAgetSommetNumero(pSOMsommet->SOMgetPredecesseur(uiBouclePredecesseurs)->SOMgetNumero());

			pSOMsommetResult->SOMajouterSuccesseur(pSOMtmp);
		}
	}

	return GRAresult;
}
