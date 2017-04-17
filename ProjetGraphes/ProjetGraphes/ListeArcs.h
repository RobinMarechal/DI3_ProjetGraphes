#ifndef CLISTE_ARCS_H
#define CLISTE_ARCS_H

#include "Arc.h"
#include "Sommet.h"

class CSommet;
class CArc;

class CListeArcs
{
	unsigned int uiLISdim;
	CArc ** ppARCLISliste; // tableau dynamique de pointeurs sur un objet CArc
	CSommet * pSOMLISsommet; // pointeur sur un CSommet

	void LISinit();
	void LISdetruire();

public:
	CListeArcs();
	~CListeArcs();

	void LISajouter(CSommet * pSOMsommet);
	void LISsupprimer(CSommet * pSOMsommet);

	unsigned int LISgetDim() const;
	CSommet * LISgetSommet() const;
	CArc * LISgetArc(unsigned int uiPos) const;

	int LISgetIndice(CSommet * pSOMsommet) const;
	bool LISpossede(CSommet * pSOMsommet) const;
};

std::ostream & operator<<(std::ostream & oFlux, CListeArcs & LISliste);

#endif