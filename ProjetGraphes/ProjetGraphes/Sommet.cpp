#include "Sommet.h"


void CSommet::SOMinit()
{
	pGRASOMgraphe = nullptr;
	pLSPSOMpredecesseurs = nullptr;
	pLSSSOMsuccesseurs = nullptr;
}

void CSommet::SOMdetruire()
{
	delete pLSSSOMsuccesseurs;
	delete pLSPSOMpredecesseurs;
}

/*
CSommet::CSommet()
{
	SOMinit();
	pLSPSOMpredecesseurs = new CListeArcs();
	pLSSSOMsuccesseurs = new CListeArcs();
}
*/

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
	return uiSOMnumero == SOMobjet.uiSOMnumero
		&& pLSSSOMsuccesseurs == SOMobjet.pLSSSOMsuccesseurs
		&& pLSPSOMpredecesseurs == SOMobjet.pLSPSOMpredecesseurs;
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

void CSommet::SOMajouterSuccesseur(CSommet * pSOMsuccesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMsuccesseur != nullptr && pSOMsuccesseur != this && pSOMsuccesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		// Ajout a la liste des successeurs
		//pLSSSOMsuccesseurs->LISajouter(pSOMsuccesseur); // ----> Realloc + insertion

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
	//pLSPSOMpredecesseurs->LISajouter(pSOMpredecesseur); // ----> Ajouter à pLSPSOMpredecesseurs
}

void CSommet::SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur)
{
	//pLSPSOMpredecesseurs->LISsupprimer(pSOMpredecesseur); // ----> Ajouter à pLSSSOMsuccesseur
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
