#include "Graphe.h"

#include <iostream>
#include "Cexception.h"
#include "Sommet.h"
#include "helpers.h"
#include "constantes.h"

using namespace std;

/*****************************************
Constructeur à un argument.
******************************************
Entrée : le nombre de sommets du graphe à construire (unsigned int).
Nécessite : rien.
Sortie : une instance de CGraphe.
Entraîne : la création d'un graphe contenant le nombre de sommets indiqués.
******************************************/
CGraphe::CGraphe(unsigned int uiNbSommets)
{
	uiGRAnbSommets = uiNbSommets;
	uiGRAtailleTableau = 0;
    GRAinit();
}


/*****************************************
Constructeur de recopie.
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : une instance de CGraphe.
Entraîne : la création d'une copie du graphe passé en paramètre.
******************************************/
CGraphe::CGraphe(const CGraphe & GRAobjet)
{
	GRArecopierGraphe(GRAobjet);
}


/*****************************************
Destructeur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : la désallocation des pointeurs.
******************************************/
CGraphe::~CGraphe()
{
    GRAdetruire();
}


/*****************************************
Initialisation d'un graphe.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'initialisation du graphe.
******************************************/
void CGraphe::GRAinit()
{
	ppSOMGRAsommets = new CSommet*[uiGRAnbSommets + 1];
	puiGRApositionsSommets = new unsigned int[uiGRAtailleTableau]();
	uiGRAposProchaineInsertion = 1;
}


/*****************************************
Destruction d'un graphe.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : la destruction du graphe.
******************************************/
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
	delete[] puiGRApositionsSommets;
	ppSOMGRAsommets = nullptr;
	puiGRApositionsSommets = nullptr;
}


/*****************************************
Recopie d'un graphe.
******************************************
Entrée : une référence sur une instance de CGraphe
Nécessite : rien.
Sortie : rien.
Entraîne : la recopie du graphe passé en paramètre.
******************************************/
void CGraphe::GRArecopierGraphe(const CGraphe & GRAobjet)
{
	unsigned int uiBoucle;
	uiGRAnbSommets = GRAobjet.uiGRAnbSommets;
	uiGRAtailleTableau = GRAobjet.uiGRAtailleTableau;

	GRAinit();

	uiGRAposProchaineInsertion = GRAobjet.uiGRAposProchaineInsertion;

	for (uiBoucle = 1; uiBoucle <= uiGRAnbSommets; uiBoucle++)
	{
		ppSOMGRAsommets[uiBoucle] = new CSommet(*GRAobjet.ppSOMGRAsommets[uiBoucle]);
	}

	// Copie du tableau des positions
	if (memcpy_s(puiGRApositionsSommets, sizeof(int) * uiGRAtailleTableau, GRAobjet.puiGRApositionsSommets, sizeof(int) * uiGRAtailleTableau) != 0)
	{
		erreur("Echec de copie de mémoire dans CGraphe::CGraphe(CGraphe). Le programme s'est arrêté.");
	}
}


/*****************************************
Surcharge de l'opérateur =.
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : une instance de CGraphe.
Entraîne : la recopie du graphe passé en paramètre.
******************************************/
CGraphe & CGraphe::operator=(const CGraphe & GRAobjet)
{
	GRAdetruire();

	GRArecopierGraphe(GRAobjet);

	return *this;
}


/*****************************************
Surcharge de l'opérateur ==
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les graphes sont identiques)
			ou (false : les graphes sont différents).
******************************************/
bool CGraphe::operator==(const CGraphe & GRAobjet) const
{
	unsigned int uiBoucle = 0;

	if (uiGRAnbSommets != GRAobjet.uiGRAnbSommets)
	{
		return false;
	}

	// ---> les deux graphes ont le même nombre de sommets

	// Pour chaque sommet de this, on regarde s'il y a un sommet équivalent dans l'autre graphe
	for (uiBoucle = 1; uiBoucle <= uiGRAnbSommets; uiBoucle++)
	{
		CSommet * pSOMtmp = ppSOMGRAsommets[uiBoucle];
		unsigned int uiNumero = pSOMtmp->SOMgetNumero();

		if (GRAobjet.puiGRApositionsSommets[uiNumero] == GRA_AUCUN_SOMMET)
		{
			// ce sommet n'est pas dans l'autre graphe
			return false;
		}

		// ---> On a trouvé un sommet équivalent dans l'autre graphes
	}

	// + COMPARER LES ARCS

	return true;
}


/*****************************************
Surcharge de l'opérateur !=.
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les graphes sont différents)
			ou (false : les graphes sont identiques).
******************************************/
bool CGraphe::operator!=(const CGraphe & GRAobjet) const
{
	return !operator==(GRAobjet);
}


/*****************************************
Création d'un sommet.
******************************************
Entrée : le numéro du sommet (unsigned int).
Nécessite : le numéro est un nombre > 0.
Sortie : un pointeur sur une instance de CSommet.
Entraîne : la création d'un sommet.
******************************************/
CSommet * CGraphe::GRAcreerSommet(unsigned int uiNumero)
{
	CSommet * pSOMsommet = nullptr;

	try 
	{
		pSOMsommet = new CSommet(this, uiNumero);
	}
	catch (Cexception EXCe)
	{
		delete pSOMsommet;
		pSOMsommet = nullptr;

		erreur(EXCe.EXCgetMessage(), false);
	}

	return pSOMsommet;
}


/*****************************************
Ajout d'un sommet.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : l'ajout du sommet passé en paramètre au graphe.
******************************************/
void CGraphe::GRAajouterSommet(CSommet * pSOMobjet)
{
	unsigned int uiNumero = pSOMobjet->SOMgetNumero();
	if (GRAgetPosSommet(pSOMobjet) != GRA_AUCUN_SOMMET)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Impossible d'ajouter le sommet au graphe : il en existe deja un avec le numero %d.", uiNumero);
		throw Cexception(EXC_SOMMET_UNIQUE, pcMsg);
	}

	ppSOMGRAsommets[uiGRAposProchaineInsertion] = pSOMobjet;

	// So uiNumero + 1 > taille du tableau de positions, on realloue le tableau puis qu'il contienne uiNumero+1 cases
	if (uiGRAtailleTableau <= uiNumero)
	{
		unsigned int * puiTemp = new unsigned int[uiNumero + 1]();

		// On copie le tableau de bases dans uiTmp pour garder les valeurs déjà présentes
		memcpy_s(puiTemp, (uiNumero + 1) * sizeof(unsigned int), puiGRApositionsSommets, (uiGRAtailleTableau) * sizeof(unsigned int));

		uiGRAtailleTableau = uiNumero + 1;

		if (puiTemp == nullptr)
		{
			erreur("Erreur de copie mémoire dans CGraphe::GRAajouterSommet(CSommet*). Le programme s'est arrêté.");
		}

		delete[] puiGRApositionsSommets;
		puiGRApositionsSommets = puiTemp;
	}
	
	puiGRApositionsSommets[uiNumero] = uiGRAposProchaineInsertion;
	uiGRAposProchaineInsertion++;
}


/*****************************************
Lecture d'un sommet.
******************************************
Entrée : le numéro du sommet (unsigned int).
Nécessite : le nméro est > 0.
Sortie : un pointeur sur une instance de CSommet.
Entraîne : rien.
******************************************/
CSommet * CGraphe::GRAgetSommetNumero(unsigned int uiNumero) const
{
	CSommet * pSOMsommet = nullptr;

	// Si le numéro appartient bien au tableau des positions
	if (uiNumero >= 0 && uiNumero < uiGRAtailleTableau)
	{
		// On la récupère
		unsigned int uiPos = puiGRApositionsSommets[uiNumero];
		// Si pos == 0, alors le sommet n'est pas dans le graphe (les sommets commencent à l'indice 1)
		if (uiPos != GRA_AUCUN_SOMMET)
		{
			pSOMsommet = ppSOMGRAsommets[uiPos];
		}
	}

	return pSOMsommet;
}


/*****************************************
Lecture de la position d'un sommet.
******************************************
Entrée : la position du sommet (unsigned int).
Nécessite : la position est > 0.
Sortie : une instance de CSommet.
Entraîne : rien.
******************************************/
CSommet * CGraphe::GRAgetSommetPosition(unsigned int uiPos) const
{
	if (uiPos >= uiGRAnbSommets)
	{
		return nullptr;
	}

	return ppSOMGRAsommets[uiPos + 1];
}


/*****************************************
Lecture de la position d'un sommet.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : la position du sommet (unsigned int).
Entraîne : rien.
******************************************/
unsigned int CGraphe::GRAgetPosSommet(const CSommet * pSOMobjet) const
{
	// On vérifie que le sommet est bien dans ce graphe là
	if (pSOMobjet->SOMgetGraphe() == this)
	{
		unsigned int uiNumero = pSOMobjet->SOMgetNumero();
		if (uiNumero >= uiGRAtailleTableau)
		{
			return GRA_AUCUN_SOMMET;
		}

		return puiGRApositionsSommets[uiNumero];
	}

	return GRA_AUCUN_SOMMET;
}


/*****************************************
Suppression d'un sommet.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : la suppression du sommet passé en paramètre du graphe.
******************************************/
void CGraphe::GRAsupprimerSommet(CSommet * pSOMobjet)
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
	delete pSOMobjet;
	puiGRApositionsSommets[uiNumero] = GRA_AUCUN_SOMMET;

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


/*****************************************
Affichage d'un graphe.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'affichage d'un graphe.
******************************************/
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

/*****************************************
Surchage de l'opérateur <<.
******************************************
Entrée : un flux, une référence sur une instance de CGraphe.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du graphe passé en paramètre.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, const CGraphe & GRAgraphe)
{
	unsigned int uiBoucle;

	oFlux << "----------------------------------" << std::endl;
	oFlux << "Graphe :" << std::endl;
	oFlux << "Nombre de sommets : " << GRAgraphe.GRAgetNbSommets() << std::endl << std::endl;

	for (uiBoucle = 1; uiBoucle <= GRAgraphe.GRAgetNbSommets(); uiBoucle++)
	{
		CSommet * pSOMsommet = GRAgraphe.GRAgetSommetNumero(uiBoucle);
		if (pSOMsommet != nullptr)
		{
			oFlux << *pSOMsommet << std::endl << std::endl;
		}
	}

	oFlux << "----------------------------------" << std::endl;

	return oFlux;
}

/*****************************************
Surchage de l'opérateur <<.
******************************************
Entrée : un flux, un pointeur sur une instance de CGraphe.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du graphe passé en paramètre.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, const CGraphe * GRAgraphe)
{
	oFlux << *GRAgraphe;
	return oFlux;
}
