#include "Sommet.h"

void CSommet::SOMinit()
{
	pGRASOMgraphe = nullptr;
	uiSOMnumero = -1;
	pLISSOMpredecesseurs = new CListeArcs();
	pLISSOMsuccesseurs = new CListeArcs();
}

void CSommet::SOMdetruire()
{
	delete pLISSOMsuccesseurs;
	delete pLISSOMpredecesseurs;
}

/*
CSommet::CSommet()
{
	SOMinit();
	pLISSOMpredecesseurs = new CListeArcs();
	pLISSOMsuccesseurs = new CListeArcs();
}
*/

CSommet::CSommet(CGraphe * pGRAgraphe, unsigned int uiNumero)
{
	SOMinit();
	pGRASOMgraphe = pGRAgraphe;
	uiSOMnumero = uiNumero;
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
	return uiSOMnumero == SOMobjet.uiSOMnumero
		&& pLISSOMsuccesseurs == SOMobjet.pLISSOMsuccesseurs
		&& pLISSOMpredecesseurs == SOMobjet.pLISSOMpredecesseurs;
}

bool CSommet::operator!=(CSommet & SOMobjet) const
{
	return !operator==(SOMobjet);
}

unsigned int CSommet::SOMgetNumero() const
{
	return uiSOMnumero;
}

CGraphe * CSommet::SOMgetGraphe() const
{
	return pGRASOMgraphe;
}

CListeArcs * CSommet::SOMgetListeSuccesseurs() const
{
	return pLISSOMsuccesseurs;
}

CListeArcs * CSommet::SOMgetListePredecesseurs() const
{
	return pLISSOMpredecesseurs;
}

void CSommet::SOMajouterSuccesseur(CSommet * pSOMsuccesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMsuccesseur != nullptr && pSOMsuccesseur != this && pSOMsuccesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		// Ajout a la liste des successeurs
		pLISSOMsuccesseurs->LISajouter(pSOMsuccesseur);

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
		pLISSOMsuccesseurs->LISsupprimer(pSOMsuccesseur);

		// Suppression de this de la liste des predecesseurs de pSOMsuccesseur
		pSOMsuccesseur->SOMsupprimerPredecesseur(this);
	}
}

// private

void CSommet::SOMajouterPredecesseur(CSommet * pSOMpredecesseur)
{
	pLISSOMpredecesseurs->LISajouter(pSOMpredecesseur);
}

void CSommet::SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur)
{
	pLISSOMpredecesseurs->LISsupprimer(pSOMpredecesseur);
}

std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet)
{
	oFlux << SOMsommet.SOMgetListeSuccesseurs();
	return oFlux;
}

std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet)
{
	oFlux << *SOMsommet;
	return oFlux;
}
