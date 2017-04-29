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
	unsigned int uiNbSommets;
	unsigned int uiBoucle;
	
	uiNbSommets = GRAgraphe.GRAgetNbSommets();

	CGraphe * GRAresult = new CGraphe(uiNbSommets);


	// ------------ Cr�ation des sommets �quivalents --------------------------------------------------

	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		CSommet * pSOMgrapheSommet = GRAgraphe.GRAgetSommetPosition(uiBoucle);

		// recreation du sommet
		GRAresult->GRAcreerSommet(pSOMgrapheSommet->SOMgetNumero());
	}


	// ------------ Recopie de tous les arcs de chaque sommet ------------------------------------------

	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		unsigned int uiNbSucc, uiBoucleArcs;

		CSommet * pSOMgrapheTmp = GRAgraphe.GRAgetSommetPosition(uiBoucle);
		CSommet * pSOMresultSommet = GRAgraphe.GRAgetSommetPosition(uiBoucle);


		// Nombre de SUCCESSEURS du i-�me sommet du nouveau graphe = nombre de PREDECESSEUR du i-eme sommet de GRAgraphe
		uiNbSucc = pSOMgrapheTmp->SOMgetNbPredecesseurs();

		// On recr�e tous les successeurs
		// Les predecesseurs sont cr��s automatiquement en m�me temps
		for (uiBoucleArcs = 0; uiBoucleArcs < uiNbSucc; uiBoucleArcs++)
		{
			CSommet * pSOMsucc = GRAresult->GRAgetSommetNumero(pSOMgrapheTmp->SOMgetPredecesseur(uiBoucleArcs)->SOMgetNumero());

			pSOMresultSommet->SOMajouterSuccesseur(pSOMsucc);
		}
	}

	return GRAresult;
}
