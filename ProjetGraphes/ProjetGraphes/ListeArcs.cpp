#include "ListeArcs.h"



void CListeArcs::LISinit()
{
	uiLISdim = 0;
	ppARCLISliste = nullptr;
}

void CListeArcs::LISdetruire()
{
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < uiLISdim; uiBoucle++)
	{
		delete ppARCLISliste[uiBoucle];
	}

	free(ppARCLISliste);
}

CListeArcs::CListeArcs(CSommet * pSOMsommet)
{
	LISinit();
	pSOMLISsommet = pSOMsommet;
}

CListeArcs::CListeArcs(CListeArcs & LISobjet)
{
	/*
	unsigned int uiBoucle;
	pSOMLISsommet = LISobjet.pSOMLISsommet;
	uiLISdim = LISobjet.uiLISdim;

	ppARCLISliste = (CArc **)malloc(sizeof(CArc *) * uiLISdim);

	if (ppARCLISliste == nullptr)
	{
		erreur("Malloc a echou� dans CListeArcs::CListeArcs(ClisteArcs&).");
	}

	for (uiBoucle = 0; uiBoucle < uiLISdim; uiBoucle++)
	{
		ppARCLISliste[uiBoucle] = new CArc(*LISobjet.ppARCLISliste[uiBoucle]);
	}
	*/
}


CListeArcs::~CListeArcs()
{
	LISdetruire();
}

void CListeArcs::LISajouter(CSommet * pSOMsommet)
{
	// Si la liste poss�de d�j� ce num�ro, on ne fait rien
	if (LISpossede(pSOMsommet))
		return;

	// Sinon, on cr�� un nouvel objet CArc, et on l'ajoute au tableau
	uiLISdim++;
	ppARCLISliste = (CArc **)realloc(ppARCLISliste, sizeof(CArc *) * uiLISdim);
	
	if (ppARCLISliste == nullptr)
	{
		erreur("Realloc a echou� dans LISajouter().");
	}

	ppARCLISliste[uiLISdim - 1] = new CArc(this, pSOMsommet);
}

void CListeArcs::LISsupprimer(CSommet * pSOMsommet)
{
	unsigned int uiBoucle;
	int iPos = LISgetIndice(pSOMsommet);

	if (iPos == -1)
		return;

	// On supprime a l'indice
	delete ppARCLISliste[iPos];

	// On d�cale tout "vers la gauche" a partir de l'indice supprim�
	for (uiBoucle = 0; uiBoucle < uiLISdim - 1; uiBoucle++)
	{
		ppARCLISliste[uiBoucle] = ppARCLISliste[uiBoucle + 1];
	}

	// puis on r�alloue
	uiLISdim--;
	ppARCLISliste = (CArc **)realloc(ppARCLISliste, sizeof(CArc *) * uiLISdim);
}

unsigned int CListeArcs::LISgetDim() const
{
	return uiLISdim;
}

CSommet * CListeArcs::LISgetSommet() const
{
	return pSOMLISsommet;
}

CArc * CListeArcs::LISgetArc(unsigned int uiPos) const
{
	return ppARCLISliste[uiPos];
}

int CListeArcs::LISgetIndice(CSommet * pSOMsommet) const
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiLISdim; uiBoucle++)
	{
		if (ppARCLISliste[uiBoucle]->ARCgetSommet() == pSOMsommet)
		{
			return uiBoucle;
		}
	}

	return -1;
}

bool CListeArcs::LISpossede(CSommet * pSOMsommet) const
{
	return LISgetIndice(pSOMsommet) != -1;
}

void CListeArcs::LISdebug() const
{
}

std::ostream & operator<<(std::ostream & oFlux, CListeArcs & LISliste)
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < LISliste.LISgetDim(); uiBoucle++)
	{
		oFlux << "\t\t" << *(LISliste.LISgetArc(uiBoucle)) << std::endl;
	}

	return oFlux;
}
