#include "Graphe.h"

#include <iostream>
#include "Cexception.h"
#include "Sommet.h"
#include "helpers.h"
#include "constantes.h"

using namespace std;

CGraphe::CGraphe(unsigned int uiNb)
{
	uiGRAnbSommets = uiNb;
    GRAinit();
}

CGraphe::CGraphe(CGraphe & GRAobjet)
{
    unsigned int uiBoucle;

    uiGRAnbSommets = GRAobjet.uiGRAnbSommets;
    GRAinit();
	ppSOMGRAsommets = (CSommet **) malloc(sizeof(CSommet*) * uiGRAnbSommets);
    
    if(ppSOMGRAsommets == NULL)
    {
        cout << "Echec d'allocation mémoire dans CGraphe::CGraphe(CGraphe). Le programme s'est arrêté." << endl;
        exit(EXIT_FAILURE);
    }

    for(uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
    {
		ppSOMGRAsommets[uiBoucle] = new CSommet(*GRAobjet.ppSOMGRAsommets[uiBoucle]);
    }
}

CGraphe::~CGraphe()
{
    GRAdetruire();
}

void CGraphe::GRAinit()
{
	unsigned int uiBoucle;
	ppSOMGRAsommets = (CSommet **)calloc(uiGRAnbSommets, sizeof(CSommet *));

	for (uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		ppSOMGRAsommets[uiBoucle] = nullptr;
	}
}

void CGraphe::GRAdetruire()
{
	unsigned int uiBoucle;

	for(uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		delete ppSOMGRAsommets[uiBoucle];
	}

	free(ppSOMGRAsommets);
}

void CGraphe::GRAreallouerTabSommets()
{
	ppSOMGRAsommets = (CSommet **)realloc(ppSOMGRAsommets, uiGRAnbSommets * sizeof(CSommet *));

	if (ppSOMGRAsommets == NULL)
	{
		free(ppSOMGRAsommets);
		cout << "Une réallocation a echoué, le programme s'est arrêté." << endl;
		exit(EXIT_FAILURE);
	}
}

CGraphe & CGraphe::operator=(const CGraphe & GRAobjet)
{
	unsigned int uiBoucle;

	GRAdetruire();
	GRAinit();

	uiGRAnbSommets = GRAobjet.uiGRAnbSommets;
	ppSOMGRAsommets = (CSommet **)malloc(sizeof(CSommet*) * uiGRAnbSommets);

	if (ppSOMGRAsommets == NULL)
	{
		cout << "Echec d'allocation mémoire dans CGraphe::CGraphe(CGraphe). Le programme s'est arrêté." << endl;
		exit(EXIT_FAILURE);
	}

	for (uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		ppSOMGRAsommets[uiBoucle] = new CSommet(*GRAobjet.ppSOMGRAsommets[uiBoucle]);
	}

	return *this;
}

bool CGraphe::operator==(const CGraphe & GRAobjet) const
{
	return false;
}

bool CGraphe::operator!=(const CGraphe & GRAobjet) const
{
	return false;
}

CSommet * CGraphe::GRAajouterSommet(unsigned int uiNumero)
{
	CSommet * pSOMsommet = nullptr;

	// S'il n'y a pas déjà un sommet avec ce numéro
	if (GRAgetSommet(uiNumero) != nullptr)
	{
		try 
		{
			pSOMsommet = new CSommet(this, uiNumero);
			GRAajouterSommet(pSOMsommet);
		}
		catch (Cexception EXCe)
		{
			cout << EXCe.EXCgetMessage() << endl;
		}
	}

	return nullptr;
}

void CGraphe::GRAajouterSommet(CSommet * pSOMobjet)
{
	unsigned int uiNumero = pSOMobjet->SOMgetNumero();
	if (GRAgetSommet(uiNumero) == NULL)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Impossible de créer le sommet, le graphe possède déjà un sommet avec le numero %d.", uiNumero);
		throw Cexception(EXC_SOMMET_UNIQUE ,pcMsg);
	}

	ppSOMGRAsommets[uiNumero] = pSOMobjet;
}

CSommet * CGraphe::GRAgetSommet(unsigned int uiNumero) const
{
	// A l'indice n se trouve le sommet numéro n + 1
	return ppSOMGRAsommets[uiNumero - 1];
}

int CGraphe::GRAgetPosSommet(const CSommet * pSOMobjet) const
{
	int iNumero = pSOMobjet->SOMgetNumero();
	if (ppSOMGRAsommets[iNumero]->SOMgetGraphe() == this)
	{
		return iNumero - 1;
	}

	return -1;
}

void CGraphe::GRAsupprimerSommet(const CSommet * pSOMobjet)
{
	unsigned int uiNumero = pSOMobjet->SOMgetNumero();
	int iPos = GRAgetPosSommet(pSOMobjet);

	if (iPos < 0)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Impossible de supprimer le sommet numéro %d, il n'est pas dans le graphe.", uiNumero);
		throw Cexception(EXC_SOMMET_HORS_GRAPHE, pcMsg);
	}

	delete ppSOMGRAsommets[iPos];
	ppSOMGRAsommets[iPos] = NULL;
}


void CGraphe::GRAafficher() const
{
	// Euh.......
}

std::ostream & operator<<(std::ostream & oFlux, CGraphe & GRAgraphe)
{
	unsigned int uiBoucle;

	oFlux << "----------------------------------" << std::endl;
	oFlux << "Graphe :" << std::endl;
	oFlux << "Sommets : " << GRAgraphe.GRAgetNbSommets() << std::endl;

	for (uiBoucle = 0; uiBoucle < GRAgraphe.GRAgetNbSommets(); uiBoucle++)
	{
		CSommet * pSOMsommet = GRAgraphe.GRAgetSommet(uiBoucle);
		if (pSOMsommet != nullptr)
		{
			oFlux << *pSOMsommet << std::endl;
		}
	}

	oFlux << "----------------------------------" << std::endl;

	return oFlux;
}

std::ostream & operator<<(std::ostream & oFlux, CGraphe * GRAgraphe)
{
	oFlux << *GRAgraphe;
	return oFlux;
}
