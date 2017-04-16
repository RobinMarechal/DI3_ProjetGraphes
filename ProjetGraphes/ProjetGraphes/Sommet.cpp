#include "Sommet.h"



void CSommet::SOMinit()
{
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
	
}


CSommet::~CSommet()
{
	SOMdetruire;
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

void CSommet::SOMajouterSuccesseur(CSommet * pSOMsuccesseur)
{
	// Ajout a la liste des successeurs
	pLISSOMsuccesseurs->LISajouter(pSOMsuccesseur->uiSOMnumero);

	// Ajout de this a la liste des predecesseurs de pSOMsuccesseur
	pSOMsuccesseur->SOMajouterPredecesseur(this);
}

void CSommet::SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur)
{
	pLISSOMsuccesseurs->LISsupprimer(pSOMsuccesseur->uiSOMnumero);

	pSOMsuccesseur->SOMsupprimerPredecesseur(this);
}

// private

void CSommet::SOMajouterPredecesseur(CSommet * pSOMpredecesseur)
{
	pLISSOMpredecesseurs->LISajouter(pSOMpredecesseur->uiSOMnumero);
}

void CSommet::SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur)
{
	pLISSOMpredecesseurs->LISsupprimer(pSOMpredecesseur->uiSOMnumero);
}
