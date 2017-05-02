#ifndef CSOMMET_H
#define CSOMMET_H

#include "Graphe.h"
#include "ArcPartant.h"
#include "ArcArrivant.h"

class CGraphe;
class CArcPartant;
class CArcArrivant;

class CSommet
{
private:
	unsigned int uiSOMnumero;
	unsigned int uiSOMnbSuccesseurs;
	unsigned int uiSOMnbPredecesseurs;

	// Relations
	CGraphe * pGRASOMgraphe;
	CArcPartant ** pPARSOMarcsPartants;
	CArcArrivant ** pARRSOMarcsArrivants;

	/*****************************************
	Initialisation du sommet.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation du sommet.
	******************************************/
	void SOMinit();


	/*****************************************
	Destruction du sommet.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la destruction des arcs reliés au sommet.
	******************************************/
	void SOMdetruire();


	/*****************************************
	Recopie du sommet.
	******************************************
	Entrée : une référence sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la recopie du sommet passé en paramètre.
	******************************************/
	void SOMrecopier(CSommet & SOMobjet);


	/*****************************************
	Ajout d'un prédecesseur.
	******************************************
	Entrée : un pointeur sur une instance de CSOmmet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'ajout d'un prédecesseur du sommet.
	******************************************/
	void SOMajouterPredecesseur(CSommet * pSOMpredecesseur);


	/*****************************************
	Suppression d'un prédecesseur.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la suppression d'un prédecesseur de sommet.
	******************************************/
	void SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur);

public:

	/*****************************************
	Constructeur à deux arguments.
	******************************************
	Entrée : un pointeur sur une instance de CGraphe,
			 le nnuméro du sommet (unsigned int).
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la création d'un sommet avec le numéro indiqué.
	******************************************/
	CSommet(CGraphe * pGRAgraphe, unsigned int uiNumero);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entrée : une référence sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la recopie du sommet passé en paramètre.
	******************************************/
	CSommet(CSommet & SOMobjet);


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la destruction des arcs du sommet.
	******************************************/
	~CSommet();


	/*****************************************
	Surcharge de l'opérateur =.
	******************************************
	Entrée : une référence sur une instance de CSommet.
	Nécessite : rien.
	Sortie : une référence sur une instance de CSommet.
	Entraîne : l'affectation du sommet passé en paramètre.
	******************************************/
	CSommet & operator=(CSommet & SOMobjet);


	/*****************************************
	Surcharge de l'opérateur >>.
	******************************************
	Entrée : une référence sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'ajout d'un successeur au sommet.
	******************************************/
	void operator>>(CSommet * SOMsuccesseur);


	/*****************************************
	Surcharge de l'opérateur ==.
	******************************************
	Entrée : une référence sur une instance de CSommet.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : les sommets sont identiques)
				ou (false : les sommets sont différents).
	******************************************/
	bool operator==(CSommet & SOMobjet) const;


	/*****************************************
	Surcharge de l'opérateur !=.
	******************************************
	Entrée : une référence sur une instance de CSommet.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : les sommets sont différents)
				ou (false : les sommets dont identiques).
	******************************************/
	bool operator!=(CSommet & SOMobjet) const;


	/*****************************************
	Lecture du graphe.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : un pointeur sur une instance de CGraphe.
	Entraîne : rien.
	******************************************/
	CGraphe * SOMgetGraphe() const;


	/*****************************************
	Lecture d'un successeur.
	******************************************
	Entrée : la position du successeur (unsigned int).
	Nécessite : la position > 0.
	Sortie : un pointeur sur une instance de CSommet.
	Entraîne : rien.
	******************************************/
	CSommet * SOMgetSuccesseur(unsigned int uiPos) const;


	/*****************************************
	Lecture d'un prédecesseur.
	******************************************
	Entrée : la position du prédecesseur (unsigned int).
	Nécessite : la position > 0.
	Sortie : un pointeur sur une instance de CSommet.
	Entraîne : rien.
	******************************************/
	CSommet * SOMgetPredecesseur(unsigned int uiPos) const;


	/*****************************************
	Lecture d'un arc partant.
	******************************************
	Entrée : la position de l'arc (unsigned int).
	Nécessite : la position > 0.
	Sortie : un pointeur sur une instance de CArcPArtant.
	Entraîne : rien.
	******************************************/
	CArcPartant * SOMgetArcPartant(unsigned int uiPos) const;


	/*****************************************
	Lecture d'un arc arrivant.
	******************************************
	Entrée : la position de l'arc arrivant (unsigned int).
	Nécessite : la position > 0.
	Sortie : un pointeur sur une instance de CArcArrivant.
	Entraîne : rien.
	******************************************/
	CArcArrivant * SOMgetArcArrivant(unsigned int uiPos) const;


	/*****************************************
	Lecture du numéro du sommet.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le numéro du sommet (unsigned int).
	Entraîne : rien.
	******************************************/
	unsigned int SOMgetNumero() const;


	/*****************************************
	Lecture du nombre de successeurs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le nombre de successeurs (unsigned int).
	Entraîne : rien.
	******************************************/
	unsigned int SOMgetNbSuccesseurs() const;


	/*****************************************
	Lecture du nombre de prédecesseurs.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le nombre de prédecesseurs (unsigned int).
	Entraîne : rien.
	******************************************/
	unsigned int SOMgetNbPredecesseurs() const;


	/*****************************************
	Lecture de la position d'un successeur.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : la position du successeur (int).
	Entraîne : (la position du successeur s'il existe)
				ou (-1 s'il n'existe pas).
	******************************************/
	int SOMgetPositionSuccesseur(CSommet * pSOMsucc) const;


	/*****************************************
	Lecture de la position d'un prédecesseur.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : la position du prédecesseur (int).
	Entraîne : (la position du prédecesseur s'il existe)
				ou (-1 s'il n'existe pas).
	******************************************/
	int SOMgetPositionPredecesseur(CSommet * pSOMpred) const;


	/*****************************************
	Ajout d'un successeur.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'ajout du sommet indiqué en successeur
			   et création d'un arc entre les deux.
	******************************************/
	void SOMajouterSuccesseur(CSommet *  pSOMsuccesseur);


	/*****************************************
	Suppression d'un successeur.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la suppression du successeur
			   et de l'arc entre les deux.
	******************************************/
	void SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur);

	// A supprimer ?
	void SOMdebug() const;
};

/*****************************************
Affichage du sommet.
******************************************
Entrée : un flux, une référence sur une instance de CSommet.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du sommet.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet);


/*****************************************
Affichage du sommet.
******************************************
Entrée : un flux, un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du sommet.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet);

#endif