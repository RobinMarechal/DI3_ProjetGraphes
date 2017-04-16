#ifndef CLISTE_ARCS_H
#define CLISTE_ARCS_H

#include "Arc.h"
#include "Sommet.h"

class CListeArcs
{
	unsigned int uiLISdim;
	CArc ** pARCLISliste;
	CSommet * pSOMLISsommet;

	void LISinit();
	void LISdetruire();

public:
	CListeArcs();
	~CListeArcs();

	void LISajouter(unsigned int uiNumero);
	void LISsupprimer(unsigned int uiNumero);

	unsigned int LISgetDim() const;
	CSommet * LISgetSommet() const;
};

#endif