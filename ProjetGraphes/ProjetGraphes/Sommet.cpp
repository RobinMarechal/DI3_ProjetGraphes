#include "Sommet.h"
#include "helpers.h"
#include "Cexception.h"


/*****************************************
Initialisation du sommet.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : l'initialisation du sommet.
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
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : la destruction des arcs reli�s au sommet.
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
Entr�e : une r�f�rence sur une instance de CSommet.
N�cessite : rien.
Sortie : rien.
Entra�ne : la recopie du sommet pass� en param�tre.
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


/*****************************************
Constructeur � deux arguments.
******************************************
Entr�e : un pointeur sur une instance de CGraphe,
		 le nnum�ro du sommet (unsigned int).
N�cessite : rien.
Sortie : rien.
Entra�ne : la cr�ation d'un sommet avec le num�ro indiqu�.
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
Entr�e : une r�f�rence sur une instance de CSommet.
N�cessite : rien.
Sortie : rien.
Entra�ne : la recopie du sommet pass� en param�tre.
******************************************/
CSommet::CSommet(CSommet & SOMobjet)
{
	SOMrecopier(SOMobjet);
}


/*****************************************
Destructeur.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : rien.
Entra�ne : la destruction des arcs du sommet.
******************************************/
CSommet::~CSommet()
{
	SOMdetruire();
}


/*****************************************
Surcharge de l'op�rateur =.
******************************************
Entr�e : une r�f�rence sur une instance de CSommet.
N�cessite : rien.
Sortie : une r�f�rence sur une instance de CSommet.
Entra�ne : l'affectation du sommet pass� en param�tre.
******************************************/
CSommet & CSommet::operator=(CSommet & SOMobjet)
{
	SOMdetruire();
	SOMrecopier(SOMobjet);

	return *this;
}


/*****************************************
Surcharge de l'op�rateur >>.
******************************************
Entr�e : une r�f�rence sur une instance de CSommet.
N�cessite : rien.
Sortie : rien.
Entra�ne : l'ajout d'un successeur au sommet.
******************************************/
void CSommet::operator >> (CSommet * SOMsuccesseur)
{
	SOMajouterSuccesseur(SOMsuccesseur);
}


/*****************************************
Surcharge de l'op�rateur ==.
******************************************
Entr�e : une r�f�rence sur une instance de CSommet.
N�cessite : rien.
Sortie : un bool�en.
Entra�ne : (true : les sommets sont identiques)
			ou (false : les sommets sont diff�rents).
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
Surcharge de l'op�rateur !=.
******************************************
Entr�e : une r�f�rence sur une instance de CSommet.
N�cessite : rien.
Sortie : un bool�en.
Entra�ne : (true : les sommets sont diff�rents)
			ou (false : les sommets dont identiques).
******************************************/
bool CSommet::operator!=(CSommet & SOMobjet) const
{
	return !operator==(SOMobjet);
}


/*****************************************
Lecture du num�ro du sommet.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : le num�ro du sommet (unsigned int).
Entra�ne : rien.
******************************************/
inline unsigned int CSommet::SOMgetNumero() const
{
	return uiSOMnumero;
}


/*****************************************
Lecture du nombre de successeurs.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : le nombre de successeurs (unsigned int).
Entra�ne : rien.
******************************************/
inline unsigned int CSommet::SOMgetNbSuccesseurs() const
{
	return uiSOMnbSuccesseurs;
}


/*****************************************
Lecture du nombre de pr�decesseurs.
******************************************
Entr�e : rien.
N�cessite : rien.
Sortie : le nombre de pr�decesseurs (unsigned int).
Entra�ne : rien.
******************************************/
inline unsigned int CSommet::SOMgetNbPredecesseurs() const
{
	return uiSOMnbPredecesseurs;
}


/*****************************************
Lecture de la position d'un successeur.
******************************************
Entr�e : un pointeur sur une instance de CSommet.
N�cessite : rien.
Sortie : la position du successeur (int).
Entra�ne : (la position du successeur s'il existe)
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
Lecture de la position d'un pr�decesseur.
******************************************
Entr�e : un pointeur sur une instance de CSommet.
N�cessite : rien.
Sortie : la position du pr�decesseur (int).
Entra�ne : (la position du pr�decesseur s'il existe)
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
Entr�e : rien.
N�cessite : rien.
Sortie : un pointeur sur une instance de CGraphe.
Entra�ne : rien.
******************************************/
CGraphe * CSommet::SOMgetGraphe() const
{
	return pGRASOMgraphe;
}


/*****************************************
Lecture d'un successeur.
******************************************
Entr�e : la position du successeur (unsigned int).
N�cessite : la position > 0.
Sortie : un pointeur sur une instance de CSommet.
Entra�ne : rien.
******************************************/
inline CSommet * CSommet::SOMgetSuccesseur(unsigned int uiPos) const
{
	if (uiPos < 0 || uiPos >= uiSOMnbSuccesseurs)
		return nullptr;

	return pPARSOMarcsPartants[uiPos]->ARCgetSommetVise();
}


/*****************************************
Lecture d'un pr�decesseur.
******************************************
Entr�e : la position du pr�decesseur (unsigned int).
N�cessite : la position > 0.
Sortie : un pointeur sur une instance de CSommet.
Entra�ne : rien.
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
Entr�e : la position de l'arc (unsigned int).
N�cessite : la position > 0.
Sortie : un pointeur sur une instance de CArcPArtant.
Entra�ne : rien.
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
Entr�e : la position de l'arc arrivant (unsigned int).
N�cessite : la position > 0.
Sortie : un pointeur sur une instance de CArcArrivant.
Entra�ne : rien.
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
Entr�e : un pointeur sur une instance de CSommet.
N�cessite : rien.
Sortie : rien.
Entra�ne : Ajouter d'un arc partant au sommet, ou remplacement si un existait d�j�.
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
				erreur("Echec de r�allocation dans CSommet::SOMajouterSuccesseur(). Le programme s'est arr�t�.");
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
Entr�e : un pointeur sur une instance de CSommet.
N�cessite : rien.
Sortie : rien.
Entra�ne : Suppression d'un arc partant du sommet
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

		// On d�cale tout d'une case vers la gauche � partir de l'indice � supprimer
		for (uiBoucle = iPos; uiBoucle < uiSOMnbSuccesseurs - 1; uiBoucle++)
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


// A supprimer ?
void CSommet::SOMdebug() const
{
}


/*****************************************
Ajout d'un pr�decesseur.
******************************************
Entr�e : un pointeur sur une instance de CSommet.
N�cessite : Cette m�thode doit �tre appel�e uniquement par CSommet::SOMajouterSuccesseur().
Sortie : rien.
Entra�ne : l'ajout d'un arc arrivant au sommet, ou le remplacement s'il existait d�j�.
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
Suppression d'un pr�decesseur.
******************************************
Entr�e : un pointeur sur une instance de CSommet.
N�cessite : Cette m�thode doit �tre appel�e uniquement par CSommet::SOMsupprimerSuccesseur().
Sortie : rien.
Entra�ne : la suppression d'un arc arrivant au sommet.
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

		// On d�cale tout d'une case vers la gauche � partir de l'indice � supprimer
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
Entr�e : un flux, une r�f�rence sur une instance de CSommet.
N�cessite : rien.
Sortie : un flux.
Entra�ne : l'affichage du sommet.
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

	// Affichage des pr�decesseurs.

	oFlux << "   " << SOMsommet.SOMgetNbPredecesseurs() << " pr�decesseurs : { ";

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
Entr�e : un flux, un pointeur sur une instance de CSommet.
N�cessite : rien.
Sortie : un flux.
Entra�ne : l'affichage du sommet.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet)
{
	oFlux << *SOMsommet;
	return oFlux;
}
