#include "Graphe.h"

#include <iostream>
#include "Cexception.h"
#include "Sommet.h"
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
    uiGRAnbSommets = GRAobjet.uiGRAnbSommets;
	ppSOMGRAsommets = (CSommet **)malloc(sizeof(CSommet *) * uiGRAnbSommets);
    
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
	ppSOMGRAsommets = nullptr;
	uiGRAnbSommets = 0;
}

void CGraphe::GRAdetruire()
{
	unsigned int uiBoucle;

	for(uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		delete ppSOMGRAsommets[uiBoucle];
	}

	free(ppSOMGRAsommets);
	ppSOMGRAsommets = nullptr;
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

// precondition : uiNumero > 0
CSommet * CGraphe::GRAajouterSommet(unsigned int uiNumero)
{
	CSommet * pSOMsommet = nullptr;

	try 
	{
		pSOMsommet = new CSommet(this, uiNumero);
		GRAajouterSommet(pSOMsommet);
	}
	catch (Cexception EXCe)
	{
		delete pSOMsommet;
		pSOMsommet = nullptr;
	}

	return pSOMsommet;
}

// precondition : uiNumero > 0
void CGraphe::GRAajouterSommet(CSommet * pSOMobjet)
{
	unsigned int uiNumero = pSOMobjet->SOMgetNumero();
	if (GRAgetSommet(uiNumero) != nullptr)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Impossible de créer le sommet, le graphe possède déjà un sommet avec le numero %d.", uiNumero);
		throw Cexception(EXC_SOMMET_UNIQUE ,pcMsg);
	}

	uiGRAnbSommets++;
	GRAreallouerTabSommets();
	ppSOMGRAsommets[uiNumero - 1] = pSOMobjet;
}

CSommet * CGraphe::GRAgetSommet(unsigned int uiNumero) const
{
	// A l'indice n se trouve le sommet numéro n + 1 :
	if (uiGRAnbSommets < uiNumero) // ou > a uiGRAnbSommets
	{
		return nullptr;
	}

	return ppSOMGRAsommets[uiNumero - 1];
}

int CGraphe::GRAgetPosSommet(const CSommet * pSOMobjet) const
{
	// On vérifie que le sommet est bien dans ce graphe là
	if (pSOMobjet->SOMgetGraphe() == this)
	{
		return pSOMobjet->SOMgetNumero() - 1;
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
	ppSOMGRAsommets[iPos] = nullptr;
}


void CGraphe::GRAafficher() const
{
	cout << this << endl;
}

// affiche les informations concernant le graphe permettant le debugage
void CGraphe::GRAdebug() const
{
	unsigned int uiBoucle;
	cout << "Debug graphe :" << endl;
	cout << "Sommets (" << uiGRAnbSommets << ") :" << endl;
	
	for (uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		cout << "\t" << uiBoucle << ".  =>  "; 
		if(ppSOMGRAsommets[uiBoucle] != nullptr)
		{
			cout << "CSommet {id = " << ppSOMGRAsommets[uiBoucle]->SOMgetNumero() << "}";
		}

		cout << endl;
	}
}

std::ostream & operator<<(std::ostream & oFlux, const CGraphe & GRAgraphe)
{
	unsigned int uiBoucle;

	oFlux << "----------------------------------" << std::endl;
	oFlux << "Graphe :" << std::endl;
	oFlux << "Sommets : " << GRAgraphe.GRAgetNbSommets() << std::endl;

	for (uiBoucle = 1; uiBoucle <= GRAgraphe.GRAgetNbSommets(); uiBoucle++)
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

std::ostream & operator<<(std::ostream & oFlux, const CGraphe * GRAgraphe)
{
	oFlux << *GRAgraphe;
	return oFlux;
}
