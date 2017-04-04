#ifndef CGRAPHE_H
#define CGRAPHE_H

class CGraphe
{
private:

	unsigned int uiGRAnbSommets;
	unsigned int * pSOMGRAsommets;

public:
	CGraphe();
	CGraphe(CGraphe & GRAobjet);
	~CGraphe();

	CGraphe & operator=(CGraphe & GRAobjet);

	unsigned int GRAgetNbSommets() const;

	CSommet & GRAajouterSommet(unsigned int uiNumero);
	CSommet & GRAgetSommet(unsigned int uiNumero) const;
	void GRAsupprimerSommet(CSommet & SOMobjet);
	
	void GRAafficher() const;
};

#endif