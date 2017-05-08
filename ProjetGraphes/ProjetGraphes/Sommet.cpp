#include "Sommet.h"
#include "helpers.h"
#include "Cexception.h"


/*****************************************
Initialisation du sommet.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'initialisation du sommet.
******************************************/
void CSommet::SOMinit()
{
	uiSOMnbSuccesseurs = 0;
	uiSOMnbPredecesseurs = 0;

	pGRASOMgraphe = nullptr;
	pARRSOMarcsArrivants = nullptr;
	pPARSOMarcsPartants = nullptr;
}


/*****************************************
Destruction du sommet.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : la destruction des arcs reliés au sommet.
******************************************/
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


/*****************************************
Recopie du sommet.
******************************************
Entrée : une référence sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : la recopie du sommet passé en paramètre.
******************************************/
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
		erreur("Echec d'allocation dans CSommet::SOMrecopier(CSommet). Le programme s'est arrêté.");
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


/*****************************************
Constructeur à deux arguments.
******************************************
Entrée : un pointeur sur une instance de CGraphe,
		 le nnuméro du sommet (unsigned int).
Nécessite : rien.
Sortie : rien.
Entraîne : la création d'un sommet avec le numéro indiqué.
******************************************/
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
		throw Cexception(EXCe.EXCgetValeur(), EXCe.EXCgetMessage());
	}
}


/*****************************************
Constructeur de recopie.
******************************************
Entrée : une référence sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : la recopie du sommet passé en paramètre.
******************************************/
CSommet::CSommet(CSommet & SOMobjet)
{
	SOMrecopier(SOMobjet);
}


/*****************************************
Destructeur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : la destruction des arcs du sommet.
******************************************/
CSommet::~CSommet()
{
	SOMdetruire();
}


/*****************************************
Surcharge de l'opérateur =.
******************************************
Entrée : une référence sur une instance de CSommet.
Nécessite : rien.
Sortie : une référence sur une instance de CSommet.
Entraîne : l'affectation du sommet passé en paramètre.
******************************************/
CSommet & CSommet::operator=(CSommet & SOMobjet)
{
	SOMdetruire();
	SOMrecopier(SOMobjet);

	return *this;
}


/*****************************************
Surcharge de l'opérateur >>.
******************************************
Entrée : une référence sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : l'ajout d'un successeur au sommet.
******************************************/
void CSommet::operator >> (CSommet * SOMsuccesseur)
{
	SOMajouterSuccesseur(SOMsuccesseur);
}


/*****************************************
Surcharge de l'opérateur ==.
******************************************
Entrée : une référence sur une instance de CSommet.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les sommets sont identiques)
			ou (false : les sommets sont différents).
******************************************/
bool CSommet::operator==(CSommet & SOMobjet) const
{
	if (uiSOMnumero != SOMobjet.SOMgetNumero())
	{
		return false;
	}

	return true;
}


/*****************************************
Surcharge de l'opérateur !=.
******************************************
Entrée : une référence sur une instance de CSommet.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les sommets sont différents)
			ou (false : les sommets dont identiques).
******************************************/
bool CSommet::operator!=(CSommet & SOMobjet) const
{
	return !operator==(SOMobjet);
}


/*****************************************
Lecture du numéro du sommet.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : le numéro du sommet (unsigned int).
Entraîne : rien.
******************************************/
inline unsigned int CSommet::SOMgetNumero() const
{
	return uiSOMnumero;
}


/*****************************************
Lecture du nombre de successeurs.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : le nombre de successeurs (unsigned int).
Entraîne : rien.
******************************************/
inline unsigned int CSommet::SOMgetNbSuccesseurs() const
{
	return uiSOMnbSuccesseurs;
}


/*****************************************
Lecture du nombre de prédecesseurs.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : le nombre de prédecesseurs (unsigned int).
Entraîne : rien.
******************************************/
inline unsigned int CSommet::SOMgetNbPredecesseurs() const
{
	return uiSOMnbPredecesseurs;
}


/*****************************************
Lecture de la position d'un successeur.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : la position du successeur (int).
Entraîne : (la position du successeur s'il existe)
			ou (-1 s'il n'existe pas).
******************************************/
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


/*****************************************
Lecture de la position d'un prédecesseur.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : la position du prédecesseur (int).
Entraîne : (la position du prédecesseur s'il existe)
			ou (-1 s'il n'existe pas).
******************************************/
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


/*****************************************
Lecture du graphe.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : un pointeur sur une instance de CGraphe.
Entraîne : rien.
******************************************/
CGraphe * CSommet::SOMgetGraphe() const
{
	return pGRASOMgraphe;
}


/*****************************************
Lecture d'un successeur.
******************************************
Entrée : la position du successeur (unsigned int).
Nécessite : la position > 0.
Sortie : un pointeur sur une instance de CSommet.
Entraîne : rien.
******************************************/
inline CSommet * CSommet::SOMgetSuccesseur(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbSuccesseurs)
		return nullptr;

	return pPARSOMarcsPartants[uiPos]->ARCgetSommetVise();
}


/*****************************************
Lecture d'un prédecesseur.
******************************************
Entrée : la position du prédecesseur (unsigned int).
Nécessite : la position > 0.
Sortie : un pointeur sur une instance de CSommet.
Entraîne : rien.
******************************************/
inline CSommet * CSommet::SOMgetPredecesseur(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return pARRSOMarcsArrivants[uiPos]->ARCgetSommetVise();
}


/*****************************************
Lecture d'un arc partant.
******************************************
Entrée : la position de l'arc (unsigned int).
Nécessite : la position > 0.
Sortie : un pointeur sur une instance de CArcPArtant.
Entraîne : rien.
******************************************/
CArcPartant * CSommet::SOMgetArcPartant(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return pPARSOMarcsPartants[uiPos];
}
	

/*****************************************
Lecture d'un arc arrivant.
******************************************
Entrée : la position de l'arc arrivant (unsigned int).
Nécessite : la position > 0.
Sortie : un pointeur sur une instance de CArcArrivant.
Entraîne : rien.
******************************************/
CArcArrivant * CSommet::SOMgetArcArrivant(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return pARRSOMarcsArrivants[uiPos];
}


/*****************************************
Ajout d'un successeur.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : Ajouter d'un arc partant au sommet, ou remplacement si un existait déjà.
******************************************/
void CSommet::SOMajouterSuccesseur(CSommet * pSOMsuccesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMsuccesseur != nullptr && pSOMsuccesseur != this && pSOMsuccesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		int iPos = SOMgetPositionSuccesseur(pSOMsuccesseur);
		if (iPos >= 0)
		{
			delete pPARSOMarcsPartants[iPos];
			pPARSOMarcsPartants[iPos] = new CArcPartant(this, pSOMsuccesseur);
		}
		else
		{
			// Ajout a la liste des successeurs
			uiSOMnbSuccesseurs++;
			pPARSOMarcsPartants = (CArcPartant **)realloc(pPARSOMarcsPartants, sizeof(CArcPartant*) * uiSOMnbSuccesseurs);
		
			if (pPARSOMarcsPartants == nullptr)
			{
				erreur("Echec de réallocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arrêté.");
			}

			pPARSOMarcsPartants[uiSOMnbSuccesseurs - 1] = new CArcPartant(this, pSOMsuccesseur);

			// Ajout de this a la liste des predecesseurs de pSOMsuccesseur
			pSOMsuccesseur->SOMajouterPredecesseur(this);
		}

	}
}


/*****************************************
Suppression d'un successeur.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : Suppression d'un arc partant du sommet
******************************************/
void CSommet::SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMsuccesseur != nullptr && pSOMsuccesseur != this && pSOMsuccesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		unsigned int uiBoucle;
		int iPos = SOMgetPositionSuccesseur(pSOMsuccesseur);

		// Si ce sommet n'est pas dans la liste des successeurs, on ne fait rien
		if (iPos == -1)
		{
			return;
		}

		delete pPARSOMarcsPartants[iPos];

		// On décale tout d'une case vers la gauche à partir de l'indice à supprimer
		for (uiBoucle = iPos; uiBoucle < uiSOMnbSuccesseurs - 1; uiBoucle++)
		{
			pPARSOMarcsPartants[uiBoucle] = pPARSOMarcsPartants[uiBoucle + 1];
		}

		// On realloue la nouvelle taille
		uiSOMnbSuccesseurs--;
		pPARSOMarcsPartants = (CArcPartant **)realloc(pPARSOMarcsPartants, sizeof(CArcPartant*) * uiSOMnbSuccesseurs);

		if (pPARSOMarcsPartants == nullptr && uiSOMnbSuccesseurs != 0)
		{
			erreur("Echec de réallocation dans CSommet::SOMsupprimerSuccesseur(). Le programme s'est arrêté.");
		}

		// Suppression de this de la liste des predecesseurs de pSOMsuccesseur
		pSOMsuccesseur->SOMsupprimerPredecesseur(this);
	}
}


// A supprimer ?
void CSommet::SOMdebug() const
{
}


/*****************************************
Ajout d'un prédecesseur.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : Cette méthode doit être appelée uniquement par CSommet::SOMajouterSuccesseur().
Sortie : rien.
Entraîne : l'ajout d'un arc arrivant au sommet, ou le remplacement s'il existait déjà.
******************************************/
void CSommet::SOMajouterPredecesseur(CSommet * pSOMpredecesseur)
{
	int iPos = SOMgetPositionPredecesseur(pSOMpredecesseur);
	if (iPos >= 0)
	{
		delete pARRSOMarcsArrivants[iPos];
		pARRSOMarcsArrivants[iPos] = new CArcArrivant(this, pSOMpredecesseur);
	}
	else
	{
		uiSOMnbPredecesseurs++;
		pARRSOMarcsArrivants = (CArcArrivant **)realloc(pARRSOMarcsArrivants, sizeof(CArcPartant*) * uiSOMnbPredecesseurs);

		if (pARRSOMarcsArrivants == nullptr)
		{
			erreur("echec de reallocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arrete.");
		}

		pARRSOMarcsArrivants[uiSOMnbPredecesseurs - 1] = new CArcArrivant(this, pSOMpredecesseur);
	}

}


/*****************************************
Suppression d'un prédecesseur.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : Cette méthode doit être appelée uniquement par CSommet::SOMsupprimerSuccesseur().
Sortie : rien.
Entraîne : la suppression d'un arc arrivant au sommet.
******************************************/
void CSommet::SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur)
{
	// Si le sommet a ajouter n'est pas null est qu'ils sont dans le meme graphe...
	if (pSOMpredecesseur != nullptr && pSOMpredecesseur != this && pSOMpredecesseur->pGRASOMgraphe == pGRASOMgraphe)
	{
		unsigned int uiBoucle;
		int iPos = SOMgetPositionPredecesseur(pSOMpredecesseur);

		// Si ce sommet n'est pas dans la liste des successeurs, on ne fait rien
		if (iPos == -1)
		{
			return;
		}

		delete pARRSOMarcsArrivants[iPos];

		// On décale tout d'une case vers la gauche à partir de l'indice à supprimer
		for (uiBoucle = iPos; uiBoucle < uiSOMnbPredecesseurs - 1; uiBoucle++)
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


/*****************************************
Affichage du sommet.
******************************************
Entrée : un flux, une référence sur une instance de CSommet.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du sommet.
******************************************/
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

	// Affichage des prédecesseurs.

	oFlux << "   " << SOMsommet.SOMgetNbPredecesseurs() << " prédecesseurs : { ";

	for (uiBoucle = 0; uiBoucle < SOMsommet.SOMgetNbPredecesseurs(); uiBoucle++)
	{
		oFlux << SOMsommet.SOMgetPredecesseur(uiBoucle)->SOMgetNumero() << " ";
	}

	oFlux << "}";

	return oFlux;
}


/*****************************************
Affichage du sommet.
******************************************
Entrée : un flux, un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du sommet.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet)
{
	oFlux << *SOMsommet;
	return oFlux;
}
