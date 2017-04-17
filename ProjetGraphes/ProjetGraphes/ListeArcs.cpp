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

CListeArcs::CListeArcs()
{
	LISinit();
}


CListeArcs::~CListeArcs()
{
	LISdetruire();
}

void CListeArcs::LISajouter(unsigned int uiNumero)
{
	// Si la liste possède déjà ce numéro, on ne fait rien
	if (LISpossede(uiNumero))
		return;

	// Sinon, on créé un nouvel objet CArc, et on l'ajoute au tableau
	uiLISdim++;
	ppARCLISliste = (CArc **)realloc(ppARCLISliste, sizeof(CArc *) * uiLISdim);
	
	if (ppARCLISliste == nullptr)
	{
		erreur("Realloc a echoué dans LISajouter().");
	}
}

void CListeArcs::LISsupprimer(unsigned int uiNumero)
{
}

unsigned int CListeArcs::LISgetDim() const
{
	return uiLISdim;
}

CSommet * CListeArcs::LISgetSommet() const
{
	return pSOMLISsommet;
}

bool CListeArcs::LISpossede(unsigned int uiNumero) const
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiLISdim; uiBoucle++)
	{
		if (ppARCLISliste[uiBoucle]->ARCgetNumero() == uiNumero)
		{
			return true;
		}
	}

	return false;
}
