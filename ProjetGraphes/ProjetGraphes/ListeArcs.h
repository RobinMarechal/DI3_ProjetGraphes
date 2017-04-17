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

	void LISajouter(unsigned int uiNumero);
	void LISsupprimer(unsigned int uiNumero);

	unsigned int LISgetDim() const;
	CSommet * LISgetSommet() const;

	bool LISpossede(unsigned int uiNumero) const;
};

#endif