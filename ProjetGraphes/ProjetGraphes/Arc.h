#ifndef CARC_H
#define CARC_H

#include "Graphe.h"
#include "ListeArcs.h"
#include "Sommet.h"

class CGraphe;
class CListeArcs;

class CArc
{
	unsigned int uiARCnumero;

	CGraphe * pGRAARCgraphe;	
	CListeArcs * pLISARClisteArcs;
	 
	void ARCinit();
	void ARCdetruire();

public:
	CArc(CGraphe * pGRAgraphe, unsigned int uiNumero);
	~CArc();

	unsigned int ARCgetNumero() const;
	CGraphe * ARCgetGraphe() const;
	CListeArcs * ARCgetListeArcs();
};

#endif