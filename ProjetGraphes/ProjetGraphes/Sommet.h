#ifndef CSOMMET_H
#define CSOMMET_H

#include "Graphe.h"
#include "ArcPartant.h"
#include "ArcArrivant.h"

class CGraphe;
class CArcPartant;
class CArcArrivant;

class CSommet
{
private:
	unsigned int uiSOMnumero;
	unsigned int uiSOMnbSuccesseurs;
	unsigned int uiSOMnbPredecesseurs;

	// Relations
	CGraphe * pGRASOMgraphe;
	CArcPartant * pPARSOMarcsPartants;
	CArcArrivant * pARRSOMarcsArrivants;

	// initialisation & destruction
	void SOMinit();
	void SOMdetruire();

	void SOMajouterPredecesseur(CSommet * pSOMpredecesseur);
	void SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur);

public:

	CSommet(CGraphe * pGRAgraphe, unsigned int uiNumero);
	CSommet(CSommet & SOMobjet);
	~CSommet();

	void operator>>(CSommet * SOMsuccesseur);
	bool operator==(CSommet & SOMobjet) const;
	bool operator!=(CSommet & SOMobjet) const;

	CGraphe * SOMgetGraphe() const;
	const CSommet const * SOMgetSuccesseur(unsigned int uiPos) const;
	const CSommet const * SOMgetPredecesseur(unsigned int uiPos) const;

	unsigned int SOMgetNumero() const;
	unsigned int SOMgetNbSuccesseurs() const;
	unsigned int SOMgetNbPredecesseurs() const;
	int SOMgetPositionSuccesseur(CSommet * pSOMsucc) const;
	int SOMgetPositionPredecesseur(CSommet * pSOMpred) const;

	void SOMajouterSuccesseur(CSommet *  pSOMsuccesseur);
	void SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur);

	void SOMdebug() const;
};


std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet);
std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet);

#endif