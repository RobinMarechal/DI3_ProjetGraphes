#ifndef CARC_H
#define CARC_H

#include "Graphe.h"
#include "ListeArcs.h"
#include "Sommet.h"

class CListeArcs;
class CSommet;

class CArc
{
	CSommet * pSOMARCsommet;
	CListeArcs * pLISARClisteArcs;
	 
	void ARCinit();
	void ARCdetruire();

public:
	CArc(CListeArcs * pLISliste, CSommet * pSOMsommet);
	~CArc();

	CSommet * ARCgetSommet() const;
	CListeArcs * ARCgetListeArcs() const;
};

std::ostream & operator<<(std::ostream & oFlux, CArc & ARCarc);

#endif