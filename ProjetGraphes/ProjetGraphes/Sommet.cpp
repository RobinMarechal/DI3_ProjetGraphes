#include "Sommet.h"
#include "helpers.h"


void CSommet::SOMinit()
{
	uiSOMnbSuccesseurs = 0;
	uiSOMnbPredecesseurs = 0;

	pGRASOMgraphe = nullptr;
	pARRSOMarcsArrivants = nullptr;
	pPARSOMarcsPartants = nullptr;
}

void CSommet::SOMdetruire()
{
	free(pARRSOMarcsArrivants);
	free(pPARSOMarcsPartants);
}

CSommet::CSommet(CGraphe * pGRAgraphe, unsigned int uiNumero)
{
	SOMinit();
	pGRASOMgraphe = pGRAgraphe;
	uiSOMnumero = uiNumero;
}

CSommet::CSommet(CSommet & SOMobjet)
{
	/*
	pGRASOMgraphe = SOMobjet.SOMgetGraphe();
	pLSPSOMpredecesseurs = new CListeArcs(*SOMobjet.pLSPSOMpredecesseurs);
	pLSSSOMsuccesseurs = new CListeArcs(*SOMobjet.pLSSSOMsuccesseurs);
	*/
}


CSommet::~CSommet()
{
	SOMdetruire();
}

void CSommet::operator >> (CSommet * SOMsuccesseur)
{
	SOMajouterSuccesseur(SOMsuccesseur);
}

bool CSommet::operator==(CSommet & SOMobjet) const
{
	/* SOIT : on compare les pointeurs, soit en parcourt les 2 listes
	return uiSOMnumero == SOMobjet.uiSOMnumero
		&& pARRSOMarcsArrivants == SOMobjet.pARRSOMarcsArrivants
		&& pPARSOMarcsPartants == SOMobjet.pPARSOMarcsPartants;
	*/
	return false;
}

bool CSommet::operator!=(CSommet & SOMobjet) const
{
	return !operator==(SOMobjet);
}

unsigned int CSommet::SOMgetNumero() const
{
	return uiSOMnumero;
}

unsigned int CSommet::SOMgetNbSuccesseurs() const
{
	return uiSOMnbSuccesseurs;
}

unsigned int CSommet::SOMgetNbPredecesseurs() const
{
	return uiSOMnbPredecesseurs;
}

CGraphe * CSommet::SOMgetGraphe() const
{
	return pGRASOMgraphe;
}

CSommet const * CSommet::SOMgetSuccesseur(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbSuccesseurs)
		return nullptr;

	return pPARSOMarcsPartants[uiPos].ARCgetSommetVise();
}

CSommet const * CSommet::SOMgetPredecesseur(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return pARRSOMarcsArrivants[uiPos].ARCgetSommetVise();
}

void CSommet::SOMajouterSuccesseur(CSommet * pSOMsuccesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMsuccesseur != nullptr && pSOMsuccesseur != this && pSOMsuccesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		// Ajout a la liste des successeurs
		uiSOMnbSuccesseurs++;
		pPARSOMarcsPartants = (CArcPartant *)realloc(pPARSOMarcsPartants, sizeof(CArcPartant) * uiSOMnbSuccesseurs);
		
		if (pPARSOMarcsPartants == nullptr)
		{
			erreur("echec de réallocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arrêté.");
		}

		pPARSOMarcsPartants[uiSOMnbSuccesseurs - 1] = CArcPartant(this, pSOMsuccesseur);


		// Ajout de this a la liste des predecesseurs de pSOMsuccesseur
		pSOMsuccesseur->SOMajouterPredecesseur(this);
	}
}

void CSommet::SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMsuccesseur != nullptr && pSOMsuccesseur != this && pSOMsuccesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		// Suppression de la liste des successeurs
		//pLSSSOMsuccesseurs->LISsupprimer(pSOMsuccesseur); // -----> décalage + realloc

		// Suppression de this de la liste des predecesseurs de pSOMsuccesseur
		pSOMsuccesseur->SOMsupprimerPredecesseur(this);
	}
}

void CSommet::SOMdebug() const
{
}

// private

void CSommet::SOMajouterPredecesseur(CSommet * pSOMpredecesseur)
{
	uiSOMnbPredecesseurs++;
	pARRSOMarcsArrivants = (CArcArrivant *)realloc(pARRSOMarcsArrivants, sizeof(CArcPartant) * uiSOMnbPredecesseurs);

	if (pARRSOMarcsArrivants == nullptr)
	{
		erreur("echec de réallocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arrêté.");
	}

	pARRSOMarcsArrivants[uiSOMnbPredecesseurs - 1] = CArcArrivant(this, pSOMpredecesseur);
}

void CSommet::SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur)
{
	//pLSPSOMpredecesseurs->LISsupprimer(pSOMpredecesseur); // -----> décalage + realloc
}

std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet)
{
	return oFlux;
}

std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet)
{
	oFlux << *SOMsommet;
	return oFlux;
}
