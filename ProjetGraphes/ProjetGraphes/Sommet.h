#ifndef CSOMMET_H
#define CSOMMET_H

#include "Graphe.h"
#include "ListeArcs.h"

class CSommet
{
	unsigned int uiSOMnumero;

	// Relations
	CGraphe * pGRASOMgraphe;
	CListeArcs * pLISSOMsuccesseurs;
	CListeArcs * pLISSOMpredecesseurs;

	// initialisation & destruction
	void SOMinit();
	void SOMdetruire();

	void SOMajouterPredecesseur(CSommet * pSOMpredecesseur);
	void SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur);

public:
	CSommet(CGraphe * pGRAgraphe, unsigned int uiNumero);
	~CSommet();

	void operator>>(CSommet * SOMsuccesseur);
	bool operator==(CSommet & SOMobjet) const;
	bool operator!=(CSommet & SOMobjet) const;

	unsigned int SOMgetNumero() const;

	void SOMajouterSuccesseur(CSommet *  pSOMsuccesseur);
	void SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur);
};

#endif