#include "Graphe.h"

#include <iostream>
#include "Cexception.h"
#include "Sommet.h";
#include "helpers.h"
#include "constantes.h"

using namespace std;

CGraphe::CGraphe()
{
    GRAinit();
}

CGraphe::CGraphe(CGraphe & GRAobjet)
{
    unsigned int uiBoucle;

    GRAinit();
    uiGRAnbSommets = GRAobjet.uiGRAnbSommets;
    pSOMGRAsommets = (CSommet **) malloc(sizeof(CSommet*) * uiGRAnbSommets);
    
    if(pSOMGRAsommets == NULL)
    {
        cout << "Echec d'allocation mémoire dans CGraphe::CGraphe(CGraphe). Le programme s'est arrêté." << endl;
        exit(EXIT_FAILURE);
    }

    for(uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
    {
        pSOMGRAsommets[uiBoucle] = new CSommet(*GRAobjet.pSOMGRAsommets[uiBoucle]);
    }
}

CGraphe::~CGraphe()
{
    GRAdetruire();
}

void CGraphe::GRAinit()
{
    uiGRAnbSommets = 0;
    pSOMGRAsommets = NULL;
}

void CGraphe::GRAdetruire()
{
	unsigned int uiBoucle;

	for(uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		delete pSOMGRAsommets[uiBoucle];
	}

    free(pSOMGRAsommets);
}

void CGraphe::GRAreallouerTabSommets()
{
	pSOMGRAsommets = (CSommet **)realloc(pSOMGRAsommets, uiGRAnbSommets * sizeof(CSommet *));

	if (pSOMGRAsommets == NULL)
	{
		free(pSOMGRAsommets);
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
	pSOMGRAsommets = (CSommet **)malloc(sizeof(CSommet*) * uiGRAnbSommets);

	if (pSOMGRAsommets == NULL)
	{
		cout << "Echec d'allocation mémoire dans CGraphe::CGraphe(CGraphe). Le programme s'est arrêté." << endl;
		exit(EXIT_FAILURE);
	}

	for (uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		pSOMGRAsommets[uiBoucle] = new CSommet(*GRAobjet.pSOMGRAsommets[uiBoucle]);
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
	CSommet * pSOMsommet = NULL;

	// S'il n'y a pas déjà un sommet avec ce numéro
	if (GRAgetSommet(uiNumero) != NULL)
	{
		try 
		{
			pSOMsommet = new CSommet(uiNumero);
			GRAajouterSommet(pSOMsommet);
		}
		catch (Cexception EXCe)
		{
			cout << EXCe.EXCgetMessage() << endl;
		}
	}

	return NULL;
}

void CGraphe::GRAajouterSommet(CSommet * pSOMobjet)
{
	unsigned int uiNumero = pSOMobjet->getNumero();
	if (GRAgetSommet(uiNumero) == NULL)
	{
		char * pcMsg;
		sprintf_s(pcMsg, 1024, "Impossible de créer le sommet, le graphe possède déjà un sommet avec le numero %d.", uiNumero);
		throw Cexception(EXC_SOMMET_UNIQUE ,pcMsg);
	}

	pSOMGRAsommets[uiNumero] = pSOMobjet;
}

CSommet * CGraphe::GRAgetSommet(unsigned int uiNumero) const
{
	// A l'indice n se trouve le sommet numéro n + 1
	return pSOMGRAsommets[uiNumero - 1];
}

int CGraphe::GRAgetPosSommet(const CSommet * pSOMobjet) const
{
	int iNumero = pSOMobjet->getNumero();
	if (pSOMGRAsommets[iNumero]->getGraphe() == this)
	{
		return iNumero - 1;
	}

	return -1;
}

void CGraphe::GRAsupprimerSommet(const CSommet * pSOMobjet)
{
	unsigned int uiNumero = pSOMobjet->getNumero();
	int iPos = GRAgetPosSommet(pSOMobjet);

	if (iPos < 0)
	{
		char * pcMsg;
		sprintf_s(pcMsg, 1024, "Impossible de supprimer le sommet numéro %d, il n'est pas dans le graphe.", uiNumero);
		throw Cexception(EXC_SOMMET_HORS_GRAPHE, pcMsg);
	}

	delete pSOMGRAsommets[iPos];
	pSOMGRAsommets[iPos] = NULL;
}


void CGraphe::GRAafficher() const
{
	// Euh.......
}
