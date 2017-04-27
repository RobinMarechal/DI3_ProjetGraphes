#include "Graphe.h"

#include <iostream>
#include "Cexception.h"
#include "Sommet.h"
#include "helpers.h"
#include "constantes.h"

using namespace std;

CGraphe::CGraphe(unsigned int uiNbSommets)
{
	uiGRAnbSommets = uiNbSommets;
	uiGRAtailleTableau = 0;
    GRAinit();
}

CGraphe::CGraphe(const CGraphe & GRAobjet)
{
	GRArecopierGraphe(GRAobjet);
}

CGraphe::~CGraphe()
{
    GRAdetruire();
}

void CGraphe::GRAinit()
{
	ppSOMGRAsommets = new CSommet*[uiGRAnbSommets + 1];
	puiGRApositionsSommets = (unsigned int *)calloc(uiGRAtailleTableau, sizeof(unsigned int));
	uiGRAposProchaineInsertion = 1;
}

void CGraphe::GRAdetruire()
{
	unsigned int uiBoucle;

	for (uiBoucle = 1; uiBoucle <= uiGRAnbSommets; uiBoucle++)
	{
		CSommet * pSOMsommet = ppSOMGRAsommets[uiBoucle];
		if (pSOMsommet != nullptr)
		{
			delete pSOMsommet;
		}
	}

	delete[] ppSOMGRAsommets;
	free(puiGRApositionsSommets);
	ppSOMGRAsommets = nullptr;
	puiGRApositionsSommets = nullptr;
}

void CGraphe::GRArecopierGraphe(const CGraphe & GRAobjet)
{
	unsigned int uiBoucle;
	uiGRAnbSommets = GRAobjet.uiGRAnbSommets;
	uiGRAtailleTableau = GRAobjet.uiGRAtailleTableau;

	GRAinit();

	uiGRAposProchaineInsertion = GRAobjet.uiGRAposProchaineInsertion;

	if (ppSOMGRAsommets == nullptr || puiGRApositionsSommets == nullptr)
	{
		erreur("Echec d'allocation mémoire dans CGraphe::CGraphe(CGraphe). Le programme s'est arrêté.");
	}

	for (uiBoucle = 0; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		ppSOMGRAsommets[uiBoucle] = new CSommet(*GRAobjet.ppSOMGRAsommets[uiBoucle]);
	}

	// Copie de la 
	if (memcpy_s(puiGRApositionsSommets, sizeof(int) * uiGRAtailleTableau, GRAobjet.puiGRApositionsSommets, sizeof(int) * uiGRAtailleTableau) != 0)
	{
		erreur("Echec de copie de mémoire dans CGraphe::CGraphe(CGraphe). Le programme s'est arrêté.");
	}
}

/*
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
*/

CGraphe & CGraphe::operator=(const CGraphe & GRAobjet)
{
	GRAdetruire();

	GRArecopierGraphe(GRAobjet);

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

		erreur(EXCe.EXCgetMessage(), false);
	}

	return pSOMsommet;
}

// precondition : uiNumero > 0
void CGraphe::GRAajouterSommet(CSommet * pSOMobjet)
{
	unsigned int uiNumero = pSOMobjet->SOMgetNumero();
	if (GRAgetPosSommet(pSOMobjet) != 0)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Impossible d'ajouter le sommet au graphe : il en existe déjà un avec le numéro %d.", uiNumero);
		throw Cexception(EXC_SOMMET_UNIQUE, pcMsg);
	}

	ppSOMGRAsommets[uiGRAposProchaineInsertion] = pSOMobjet;

	// So uiNumero + 1 > taille du tableau de positions, on realloue le tableau puis qu'il contienne uiNumero+1 cases
	if (uiGRAtailleTableau <= uiNumero)
	{
		uiGRAtailleTableau = uiNumero + 1;
		unsigned int * uiTemp = (unsigned int *)calloc(uiGRAtailleTableau, sizeof(unsigned int));

		if (uiTemp == nullptr)
		{
			erreur("Erreur d'allocation mémoire dans CGraphe::GRAajouterSommet(CSommet*). Le programme s'est arrêté.");
		}

		// On copie le tableau de bases dans uiTmp pour garder les valeurs déjà présentes
		memcpy_s(uiTemp, (uiNumero + 1) * sizeof(unsigned int), puiGRApositionsSommets, (uiGRAtailleTableau) * sizeof(unsigned int));

		if (uiTemp == nullptr)
		{
			erreur("Erreur de copie mémoire dans CGraphe::GRAajouterSommet(CSommet*). Le programme s'est arrêté.");
		}

		free(puiGRApositionsSommets);
		puiGRApositionsSommets = uiTemp;
	}
	
	puiGRApositionsSommets[uiNumero] = uiGRAposProchaineInsertion;
	uiGRAposProchaineInsertion++;
}

CSommet * CGraphe::GRAgetSommet(unsigned int uiNumero) const
{
	CSommet * pSOMsommet = nullptr;

	// Si le numéro appartient bien au tableau des positions
	if (uiNumero > 0 && uiNumero < uiGRAtailleTableau)
	{
		// On la récupère
		unsigned int uiPos = puiGRApositionsSommets[uiNumero];
		// Si pos == 0, alors le sommet n'est pas dans le graphe (les sommets commencent à l'indice 1)
		if (ppSOMGRAsommets[uiPos] != 0)
		{
			pSOMsommet = ppSOMGRAsommets[uiPos];
		}
	}

	return pSOMsommet;
}

unsigned int CGraphe::GRAgetPosSommet(const CSommet * pSOMobjet) const
{
	// On vérifie que le sommet est bien dans ce graphe là
	if (pSOMobjet->SOMgetGraphe() == this)
	{
		unsigned int uiNumero = pSOMobjet->SOMgetNumero();
		if (uiNumero >= uiGRAtailleTableau)
		{
			return 0;
		}

		return puiGRApositionsSommets[uiNumero];
	}

	return 0;
}

void CGraphe::GRAsupprimerSommet(const CSommet * pSOMobjet)
{
	unsigned int uiBoucle, uiNumero, uiPos;

	uiNumero = pSOMobjet->SOMgetNumero();
	uiPos = GRAgetPosSommet(pSOMobjet);

	if (uiPos < 0)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Impossible de supprimer le sommet numéro %d, il n'est pas dans le graphe.", uiNumero);
		throw Cexception(EXC_SOMMET_HORS_GRAPHE, pcMsg);
	}

	// On commence par désallouer le sommet à supprimer et par actualiser le tableau des positions
	delete ppSOMGRAsommets[uiPos];
	puiGRApositionsSommets[uiNumero] = 0;

	// Décaler les sommets d'une case vers la gauche 
	// + décrémenter les valeurs de puiGRApositionsSommets
	// + décrémenter uiGRAposProchaineInsertion

	for (uiBoucle = uiPos; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		unsigned int uiNumeroSommetBoucle;

		// décalage
		ppSOMGRAsommets[uiBoucle] = ppSOMGRAsommets[uiBoucle + 1];

		if (ppSOMGRAsommets[uiBoucle] != nullptr)
		{
			// décrémentation de la position dans le tableau des positions
			uiNumeroSommetBoucle = ppSOMGRAsommets[uiBoucle]->SOMgetNumero();
			puiGRApositionsSommets[uiNumeroSommetBoucle]--;
		}
	}

	// on met la dernière case à NULL
	ppSOMGRAsommets[uiGRAnbSommets] = nullptr;
	uiGRAposProchaineInsertion--;
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
	cout << "Sommets (" << uiGRAposProchaineInsertion - 1 << ") :" << endl;
	
	for (uiBoucle = 1; uiBoucle <= uiGRAnbSommets; uiBoucle++)
	{
		CSommet * pSOMsommet = ppSOMGRAsommets[uiBoucle];

		if (pSOMsommet != nullptr)
		{
			cout << "\t" << uiBoucle - 1 << ".  CSommet {id = " << pSOMsommet->SOMgetNumero() << "}";

			cout << endl;
		}
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
