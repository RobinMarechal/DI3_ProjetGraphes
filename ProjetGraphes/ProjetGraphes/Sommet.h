#ifndef CSOMMET_H
#define CSOMMET_H

#include "Graphe.h"

class CGraphe;

class CSommet
{
	// classes internes
	class CArc;
	class CArcPartant;
	class CArcArrivant;

	unsigned int uiSOMnumero;

	// Relations
	CGraphe * pGRASOMgraphe;
	CArcPartant * pLSSSOMsuccesseurs;
	CArcArrivant * pLSPSOMpredecesseurs;
	

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

	unsigned int SOMgetNumero() const;
	CGraphe * SOMgetGraphe() const;

	void SOMajouterSuccesseur(CSommet *  pSOMsuccesseur);
	void SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur);

	void SOMdebug() const;
};


std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet);
std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet);

#endif