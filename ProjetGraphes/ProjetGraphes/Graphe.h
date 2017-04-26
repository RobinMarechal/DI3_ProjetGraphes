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
	unsigned int * puiGRApositionsSommets;
	unsigned int uiGRAtailleTableau;
	unsigned int uiGRAposDerniereInsertion;
	CSommet ** ppSOMGRAsommets;

	void GRAinit();
	void GRAdetruire();
	//void GRAreallouerTabSommets();
	void GRArecopierGraphe(const CGraphe & GRAobjet);

public:
	CGraphe(unsigned int uiNbSommets);
	CGraphe(const CGraphe & GRAobjet);
	~CGraphe();

	CGraphe & operator=(const CGraphe & GRAobjet);
	bool operator==(const CGraphe & GRAobjet) const;
	bool operator!=(const CGraphe & GRAobjet) const;

	unsigned int GRAgetNbSommets() const { return uiGRAnbSommets; } ;

	CSommet * GRAajouterSommet(unsigned int uiNumero);
	void GRAajouterSommet(CSommet * pSOMobjet);
	CSommet * GRAgetSommet(unsigned int uiNumero) const;
	unsigned int GRAgetPosSommet(const CSommet * pSOMobjet) const;
	void GRAsupprimerSommet(const CSommet * pSOMobjet);
	
	void GRAafficher() const;
	void GRAdebug() const;
};

std::ostream & operator<<(std::ostream & oFlux, const CGraphe & GRAgraphe);
std::ostream & operator<<(std::ostream & oFlux, const CGraphe * GRAgraphe);

#endif