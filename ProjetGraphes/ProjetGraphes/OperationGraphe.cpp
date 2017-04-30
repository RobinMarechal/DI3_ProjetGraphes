#include "OperationGraphe.h"

#include "Graphe.h"
#include "Sommet.h"
#include "ArcArrivant.h"
#include "ArcPartant.h"
#include "constantes.h"
#include "Cexception.h"
#include "helpers.h"


COperationGraphe::COperationGraphe()
{
}

COperationGraphe::~COperationGraphe()
{
}

CGraphe * COperationGraphe::OPGinverserGraphe(const CGraphe & GRAgraphe) const
{
	unsigned int uiBoucle,
				 uiBouclePredecesseurs;

	unsigned int uiNbSommets,
				 uiNbPredecesseurs;

	uiNbSommets = GRAgraphe.GRAgetNbSommets();

	CGraphe * GRAresult = new CGraphe(uiNbSommets);

	// On crée à nouveau le même nombre de sommets.

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

		// Les prédecesseurs de l'ancien graphe deviennent les nouveaux successeurs.
		// Les nouveaux prédecesseurs sont ajoutés automatiquement.

		for (uiBouclePredecesseurs = 0; uiBouclePredecesseurs < uiNbPredecesseurs; uiBouclePredecesseurs++)
		{
			// On récupère le numéro du prédecesseur du sommet étudié en cours.

			CSommet * SOMtmp = GRAresult->GRAgetSommetNumero(SOMsommet->SOMgetPredecesseur(uiBouclePredecesseurs)->SOMgetNumero());

			SOMsommetResult->SOMajouterSuccesseur(SOMtmp);
		}
	}

	return GRAresult;
}
