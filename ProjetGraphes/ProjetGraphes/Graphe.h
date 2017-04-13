#ifndef CGRAPHE_H
#define CGRAPHE_H

#include <iostream>

#include "Sommet.h"
#include "helpers.h"
#include "constantes.h"

class CGraphe
{
private:

	unsigned int uiGRAnbSommets;
	unsigned int uiGRAtailleTableau;
	CSommet ** pSOMGRAsommets;

	void GRAinit();
	void GRAdetruire();
	void GRAreallouerTabSommets();

public:
	CGraphe();
	CGraphe(CGraphe & GRAobjet);
	~CGraphe();

	CGraphe & operator=(const CGraphe & GRAobjet);
	bool operator==(const CGraphe & GRAobjet) const;
	bool operator!=(const CGraphe & GRAobjet) const;

	unsigned int GRAgetNbSommets() const { return uiGRAnbSommets; } ;

	CSommet * GRAajouterSommet(unsigned int uiNumero);
	void GRAajouterSommet(CSommet * pSOMobjet);
	CSommet * GRAgetSommet(unsigned int uiNumero) const;
	int GRAgetPosSommet(const CSommet * pSOMobjet) const;
	void GRAsupprimerSommet(const CSommet * pSOMobjet);
	
	void GRAafficher() const;
};

#endif