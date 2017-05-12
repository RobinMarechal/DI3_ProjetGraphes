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
	ppARRSOMarcsArrivants = nullptr;
	ppPARSOMarcsPartants = nullptr;
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
		// La méthode décrémente uiSOMnbSuccesseurs et décale le tableau des successeurs
		SOMsupprimerSuccesseur(SOMgetSuccesseur(0));
	}

	while (uiSOMnbPredecesseurs != 0)
	{
		// La méthode décrémente uiSOMnbPredecesseurs et décale le tableau des predecesseurs
		SOMgetPredecesseur(0)->SOMsupprimerSuccesseur(this);
	}

	free(ppARRSOMarcsArrivants);
	free(ppPARSOMarcsPartants);
}


/*****************************************
Recopie du sommet.
******************************************
Entrée : une instance de CSommet.
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

	ppPARSOMarcsPartants = (CArcPartant **)malloc(uiSOMnbSuccesseurs * sizeof(CArcPartant*));
	ppARRSOMarcsArrivants = (CArcArrivant **)malloc(uiSOMnbPredecesseurs * sizeof(CArcArrivant*));

	if (ppPARSOMarcsPartants == nullptr || ppARRSOMarcsArrivants == nullptr)
	{
		erreur("Echec d'allocation dans CSommet::SOMrecopier(CSommet). Le programme s'est arrêté.");
	}

	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < SOMobjet.uiSOMnbSuccesseurs; uiBoucle++)
	{
		ppPARSOMarcsPartants[uiBoucle] = new CArcPartant(*SOMobjet.ppPARSOMarcsPartants[uiBoucle]);

	}

	for (uiBoucle = 0; uiBoucle < SOMobjet.uiSOMnbPredecesseurs; uiBoucle++)
	{
		ppARRSOMarcsArrivants[uiBoucle] = new CArcArrivant(*SOMobjet.ppARRSOMarcsArrivants[uiBoucle]);
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
Entrée : une instance de CSommet.
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
Entrée : une instance de CSommet.
Nécessite : rien.
Sortie : une instance de CSommet.
Entraîne : l'affectation du sommet passé en paramètre.
******************************************/
CSommet & CSommet::operator=(CSommet & SOMobjet)
{
	SOMdetruire();
	SOMrecopier(SOMobjet);

	return *this;
}

/*****************************************
Surcharge de l'opérateur ==.
******************************************
Entrée : une instance de CSommet.
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
Entrée : une instance de CSommet.
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
		if (*ppPARSOMarcsPartants[uiBoucle]->ARCgetSommetVise() == *pSOMsucc)
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
		if (*ppARRSOMarcsArrivants[uiBoucle]->ARCgetSommetVise() == *pSOMpred)
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
Nécessite : rien.
Sortie : un pointeur sur une instance de CSommet ou nullptr si aucun successeur trouvé.
Entraîne : rien.
******************************************/
inline CSommet * CSommet::SOMgetSuccesseur(unsigned int uiPos) const
{
	if (uiPos >= uiSOMnbSuccesseurs)
		return nullptr;

	return ppPARSOMarcsPartants[uiPos]->ARCgetSommetVise();
}


/*****************************************
Lecture d'un prédecesseur.
******************************************
Entrée : la position du prédecesseur (unsigned int).
Nécessite : rien.
Sortie : un pointeur sur une instance de CSommet ou nullptr si aucun successeur trouvé.
Entraîne : rien.
******************************************/
inline CSommet * CSommet::SOMgetPredecesseur(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return ppARRSOMarcsArrivants[uiPos]->ARCgetSommetVise();
}


/*****************************************
Lecture d'un arc arrivant.
******************************************
Entrée : la position de l'arc arrivant.
Nécessite : rien.
Sortie : un pointeur sur une instance de CArcArrivant ou nullptr si aucun arc trouvé.
Entraîne : rien.
******************************************/
CArcArrivant * CSommet::SOMgetArcArrivant(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbPredecesseurs)
		return nullptr;

	return ppARRSOMarcsArrivants[uiPos];
}


/*****************************************
Lecture d'un arc partant.
******************************************
Entrée : la position de l'arc partant.
Nécessite : rien.
Sortie : un pointeur sur une instance de CArcPartant ou nullptr si aucun arc trouvé.
Entraîne : rien.
******************************************/
CArcPartant * CSommet::SOMgetArcPartant(unsigned int uiPos) const
{
	if (uiPos >= uiSOMnbSuccesseurs)
		return nullptr;

	return ppPARSOMarcsPartants[uiPos];
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
			// Si le sommet était déjà un successeur, on écrase l'arc
			delete ppPARSOMarcsPartants[iPos];
			ppPARSOMarcsPartants[iPos] = new CArcPartant(this, pSOMsuccesseur);
		}
		else
		{
			// Ajout a la liste des successeurs
			uiSOMnbSuccesseurs++;
			ppPARSOMarcsPartants = (CArcPartant **)realloc(ppPARSOMarcsPartants, sizeof(CArcPartant*) * uiSOMnbSuccesseurs);
		
			if (ppPARSOMarcsPartants == nullptr)
			{
				erreur("Echec de réallocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arrêté.");
			}

			ppPARSOMarcsPartants[uiSOMnbSuccesseurs - 1] = new CArcPartant(this, pSOMsuccesseur);

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

		delete ppPARSOMarcsPartants[iPos];

		// On décale tout d'une case vers la gauche à partir de l'indice à supprimer
		for (uiBoucle = iPos; uiBoucle < uiSOMnbSuccesseurs - 1; uiBoucle++)
		{
			ppPARSOMarcsPartants[uiBoucle] = ppPARSOMarcsPartants[uiBoucle + 1];
		}

		// On realloue la nouvelle taille
		uiSOMnbSuccesseurs--;
		ppPARSOMarcsPartants = (CArcPartant **)realloc(ppPARSOMarcsPartants, sizeof(CArcPartant*) * uiSOMnbSuccesseurs);

		if (ppPARSOMarcsPartants == nullptr && uiSOMnbSuccesseurs != 0)
		{
			erreur("Echec de réallocation dans CSommet::SOMsupprimerSuccesseur(). Le programme s'est arrêté.");
		}

		// Suppression de this de la liste des predecesseurs de pSOMsuccesseur
		pSOMsuccesseur->SOMsupprimerPredecesseur(this);
	}
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
		delete ppARRSOMarcsArrivants[iPos];
		ppARRSOMarcsArrivants[iPos] = new CArcArrivant(this, pSOMpredecesseur);
	}
	else
	{
		uiSOMnbPredecesseurs++;
		ppARRSOMarcsArrivants = (CArcArrivant **)realloc(ppARRSOMarcsArrivants, sizeof(CArcPartant*) * uiSOMnbPredecesseurs);

		if (ppARRSOMarcsArrivants == nullptr)
		{
			erreur("echec de reallocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arrete.");
		}

		ppARRSOMarcsArrivants[uiSOMnbPredecesseurs - 1] = new CArcArrivant(this, pSOMpredecesseur);
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

		delete ppARRSOMarcsArrivants[iPos];

		// On décale tout d'une case vers la gauche à partir de l'indice à supprimer
		for (uiBoucle = iPos; uiBoucle < uiSOMnbPredecesseurs - 1; uiBoucle++)
		{
			ppARRSOMarcsArrivants[uiBoucle] = ppARRSOMarcsArrivants[uiBoucle + 1];
		}

		// On realloue la nouvelle taille
		uiSOMnbPredecesseurs--;
		ppARRSOMarcsArrivants = (CArcArrivant **)realloc(ppARRSOMarcsArrivants, sizeof(CArcArrivant*) * uiSOMnbPredecesseurs);

		if (ppARRSOMarcsArrivants == nullptr && uiSOMnbPredecesseurs != 0)
		{
			erreur("Echec de reallocation dans CSommet::SOMsupprimerPredecesseur(). Le programme s'est arrete.");
		}
	}
}

/*****************************************
Affichage du sommet.
******************************************
Entrée : un flux
Entrée : une instance de CSommet.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du sommet.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet)
{
	//oFlux << " {numero = " << SOMsommet.SOMgetNumero() << "}";

	oFlux << SOMsommet.SOMgetNumero();

	return oFlux;
}
