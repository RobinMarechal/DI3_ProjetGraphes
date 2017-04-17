#ifndef CGRAPHE_H
#define CGRAPHE_H

#include <iostream>

#include "Sommet.h"
#include "helpers.h"
#include "constantes.h"
#include "Sommet.h"

class CSommet;

class CGraphe
{
private:

	unsigned int uiGRAnbSommets;
	CSommet ** ppSOMGRAsommets;

	void GRAinit();
	void GRAdetruire();
	void GRAreallouerTabSommets();

public:
	CGraphe(unsigned int uiNb);
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

std::ostream & operator<<(std::ostream & oFlux, CGraphe & GRAgraphe);
std::ostream & operator<<(std::ostream & oFlux, CGraphe * GRAgraphe);

#endif