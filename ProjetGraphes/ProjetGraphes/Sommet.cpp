#include "Sommet.h"
#include "helpers.h"
#include "Cexception.h"


void CSommet::SOMinit()
{
	uiSOMnbSuccesseurs = 0;
	uiSOMnbPredecesseurs = 0;

	pGRASOMgraphe = nullptr;
	pARRSOMarcsArrivants = nullptr;
	pPARSOMarcsPartants = nullptr;
}

void CSommet::SOMdetruire()
{
	// Supprimer les arcs partants et arrivant
	while (uiSOMnbSuccesseurs != 0)
	{
		SOMsupprimerSuccesseur(SOMgetSuccesseur(0));
	}

	while (uiSOMnbPredecesseurs != 0)
	{
		SOMgetPredecesseur(0)->SOMsupprimerSuccesseur(this);
	}

	free(pARRSOMarcsArrivants);
	free(pPARSOMarcsPartants);
}

void CSommet::SOMrecopier(CSommet & SOMobjet)
{
	SOMinit();

	uiSOMnumero = SOMobjet.uiSOMnumero;
	pGRASOMgraphe = SOMobjet.pGRASOMgraphe;
	uiSOMnbSuccesseurs = SOMobjet.uiSOMnbSuccesseurs;
	uiSOMnbPredecesseurs = SOMobjet.uiSOMnbPredecesseurs;

	pPARSOMarcsPartants = (CArcPartant **)malloc(uiSOMnbSuccesseurs * sizeof(CArcPartant*));
	pARRSOMarcsArrivants = (CArcArrivant **)malloc(uiSOMnbPredecesseurs * sizeof(CArcArrivant*));

	if (pPARSOMarcsPartants == nullptr || pARRSOMarcsArrivants == nullptr)
	{
		erreur("Echec d'allocation dans CSommet::SOMrecopier(CSommet). Le programme s'est arr�t�.");
	}

	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < SOMobjet.uiSOMnbSuccesseurs; uiBoucle++)
	{
		//SOMajouterSuccesseur(SOMobjet.SOMgetSuccesseur(uiBoucle));
		//SOMajouterSuccesseur(new CSommet(SOMobjet.pGRASOMgraphe, SOMobjet.SOMgetSuccesseur(uiBoucle)->SOMgetNumero()));
		pPARSOMarcsPartants[uiBoucle] = new CArcPartant(*SOMobjet.pPARSOMarcsPartants[uiBoucle]);

	}

	for (uiBoucle = 0; uiBoucle < SOMobjet.uiSOMnbPredecesseurs; uiBoucle++)
	{
		//SOMajouterSuccesseur(SOMobjet.SOMgetPredecesseur(uiBoucle));
		//SOMajouterPredecesseur(new CSommet(SOMobjet.pGRASOMgraphe, SOMobjet.SOMgetPredecesseur(uiBoucle)->SOMgetNumero()));
		pARRSOMarcsArrivants[uiBoucle] = new CArcArrivant(*SOMobjet.pARRSOMarcsArrivants[uiBoucle]);
	}
}

CSommet::CSommet(CGraphe * pGRAgraphe, unsigned int uiNumero)
{
	SOMinit();
	pGRASOMgraphe = pGRAgraphe;
	uiSOMnumero = uiNumero;

	try {
		pGRAgraphe->GRAajouterSommet(this);
	}
	catch (Cexception EXCe)
	{
		pGRASOMgraphe = nullptr;
		erreur(EXCe.EXCgetMessage(), false);
	}
}

CSommet::CSommet(CSommet & SOMobjet)
{
	SOMrecopier(SOMobjet);
}


CSommet::~CSommet()
{
	SOMdetruire();
}

CSommet & CSommet::operator=(CSommet & SOMobjet)
{
	SOMdetruire();
	SOMrecopier(SOMobjet);

	return *this;
}

void CSommet::operator >> (CSommet * SOMsuccesseur)
{
	SOMajouterSuccesseur(SOMsuccesseur);
}

bool CSommet::operator==(CSommet & SOMobjet) const
{
	if (uiSOMnumero != SOMobjet.SOMgetNumero())
	{
		return false;
	}

	return true;
}

bool CSommet::operator!=(CSommet & SOMobjet) const
{
	return !operator==(SOMobjet);
}

inline unsigned int CSommet::SOMgetNumero() const
{
	return uiSOMnumero;
}

inline unsigned int CSommet::SOMgetNbSuccesseurs() const
{
	return uiSOMnbSuccesseurs;
}

inline unsigned int CSommet::SOMgetNbPredecesseurs() const
{
	return uiSOMnbPredecesseurs;
}

int CSommet::SOMgetPositionSuccesseur(CSommet * pSOMsucc) const
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiSOMnbSuccesseurs; uiBoucle++)
	{
		if (*pPARSOMarcsPartants[uiBoucle]->ARCgetSommetVise() == *pSOMsucc)
		{
			return uiBoucle;
		}
	}

	return -1;
}

int CSommet::SOMgetPositionPredecesseur(CSommet * pSOMpred) const
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiSOMnbPredecesseurs; uiBoucle++)
	{
		if (*pARRSOMarcsArrivants[uiBoucle]->ARCgetSommetVise() == *pSOMpred)
		{
			return uiBoucle;
		}
	}

	return -1;
}

// Peut pas mettre inline, dunno why
CGraphe * CSommet::SOMgetGraphe() const
{
	return pGRASOMgraphe;
}

inline CSommet * CSommet::SOMgetSuccesseur(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbSuccesseurs)
		return nullptr;

	return pPARSOMarcsPartants[uiPos]->ARCgetSommetVise();
}

inline CSommet * CSommet::SOMgetPredecesseur(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return pARRSOMarcsArrivants[uiPos]->ARCgetSommetVise();
}

CArcPartant * CSommet::SOMgetArcPartant(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return pPARSOMarcsPartants[uiPos];
}
	
CArcArrivant * CSommet::SOMgetArcArrivant(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return pARRSOMarcsArrivants[uiPos];
}

void CSommet::SOMajouterSuccesseur(CSommet * pSOMsuccesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMsuccesseur != nullptr && pSOMsuccesseur != this && pSOMsuccesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		// Ajout a la liste des successeurs
		uiSOMnbSuccesseurs++;
		pPARSOMarcsPartants = (CArcPartant **)realloc(pPARSOMarcsPartants, sizeof(CArcPartant*) * uiSOMnbSuccesseurs);
		
		if (pPARSOMarcsPartants == nullptr)
		{
			erreur("Echec de r�allocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arr�t�.");
		}

		pPARSOMarcsPartants[uiSOMnbSuccesseurs - 1] = new CArcPartant(this, pSOMsuccesseur);

		// Ajout de this a la liste des predecesseurs de pSOMsuccesseur
		pSOMsuccesseur->SOMajouterPredecesseur(this);
	}
}

void CSommet::SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMsuccesseur != nullptr && pSOMsuccesseur != this && pSOMsuccesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		unsigned int uiBoucle;
		unsigned int uiPos = SOMgetPositionSuccesseur(pSOMsuccesseur);

		// Si ce sommet n'est pas dans la liste des successeurs, on ne fait rien
		if (uiPos == -1)
		{
			return;
		}

		delete pPARSOMarcsPartants[uiPos];

		// On d�cale tout d'une case vers la gauche � partir de l'indice � supprimer
		for (uiBoucle = uiPos; uiBoucle < uiSOMnbSuccesseurs - 1; uiBoucle++)
		{
			pPARSOMarcsPartants[uiBoucle] = pPARSOMarcsPartants[uiBoucle + 1];
		}

		// On realloue la nouvelle taille
		uiSOMnbSuccesseurs--;
		pPARSOMarcsPartants = (CArcPartant **)realloc(pPARSOMarcsPartants, sizeof(CArcPartant*) * uiSOMnbSuccesseurs);

		if (pPARSOMarcsPartants == nullptr && uiSOMnbSuccesseurs != 0)
		{
			erreur("Echec de r�allocation dans CSommet::SOMsupprimerSuccesseur(). Le programme s'est arr�t�.");
		}

		// Suppression de this de la liste des predecesseurs de pSOMsuccesseur
		pSOMsuccesseur->SOMsupprimerPredecesseur(this);
	}
}

void CSommet::SOMdebug() const
{
}

// private

void CSommet::SOMajouterPredecesseur(CSommet * pSOMpredecesseur)
{
	uiSOMnbPredecesseurs++;
	pARRSOMarcsArrivants = (CArcArrivant **)realloc(pARRSOMarcsArrivants, sizeof(CArcPartant*) * uiSOMnbPredecesseurs);

	if (pARRSOMarcsArrivants == nullptr)
	{
		erreur("echec de reallocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arrete.");
	}

	pARRSOMarcsArrivants[uiSOMnbPredecesseurs - 1] = new CArcArrivant(this, pSOMpredecesseur);
}

void CSommet::SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMpredecesseur != nullptr && pSOMpredecesseur != this && pSOMpredecesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		unsigned int uiBoucle;
		unsigned int uiPos = SOMgetPositionPredecesseur(pSOMpredecesseur);

		// Si ce sommet n'est pas dans la liste des successeurs, on ne fait rien
		if (uiPos == -1)
		{
			return;
		}

		delete pARRSOMarcsArrivants[uiPos];

		// On d�cale tout d'une case vers la gauche � partir de l'indice � supprimer
		for (uiBoucle = uiPos; uiBoucle < uiSOMnbPredecesseurs - 1; uiBoucle++)
		{
			pARRSOMarcsArrivants[uiBoucle] = pARRSOMarcsArrivants[uiBoucle + 1];
		}

		// On realloue la nouvelle taille
		uiSOMnbPredecesseurs--;
		pARRSOMarcsArrivants = (CArcArrivant **)realloc(pARRSOMarcsArrivants, sizeof(CArcArrivant*) * uiSOMnbPredecesseurs);

		if (pARRSOMarcsArrivants == nullptr && uiSOMnbPredecesseurs != 0)
		{
			erreur("Echec de reallocation dans CSommet::SOMsupprimerPredecesseur(). Le programme s'est arrete.");
		}
	}
}

std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet)
{
	unsigned int uiBoucle;

	oFlux << "{" << SOMsommet.SOMgetNumero() << "}" << std::endl;

	// Affichage des successeurs.

	oFlux << "   " << SOMsommet.SOMgetNbSuccesseurs() << " successeurs : { ";

	for (uiBoucle = 0; uiBoucle < SOMsommet.SOMgetNbSuccesseurs(); uiBoucle++)
	{
		oFlux << SOMsommet.SOMgetSuccesseur(uiBoucle)->SOMgetNumero() << " ";
	}

	oFlux << "}" << std::endl;

	// Affichage des pr�decesseurs.

	oFlux << "   " << SOMsommet.SOMgetNbPredecesseurs() << " pr�decesseurs : { ";

	for (uiBoucle = 0; uiBoucle < SOMsommet.SOMgetNbPredecesseurs(); uiBoucle++)
	{
		oFlux << SOMsommet.SOMgetPredecesseur(uiBoucle)->SOMgetNumero() << " ";
	}

	oFlux << "}";

	return oFlux;
}

std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet)
{
	oFlux << *SOMsommet;
	return oFlux;
}
