#ifndef CGRAPHE_H
#define CGRAPHE_H

#include <iostream>

#include "Sommet.h"
#include "helpers.h"
#include "constantes.h"
#include "Sommet.h"

class CSommet;

class CGraphe
{
private:

	unsigned int uiGRAnbSommets;
	unsigned int * puiGRApositionsSommets;
	unsigned int uiGRAtailleTableau;

	CSommet ** ppSOMGRAsommets;

	/*****************************************
	Initialisation d'un graphe.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation du graphe.
	******************************************/
	void GRAinit();


	/*****************************************
	Destruction d'un graphe.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la destruction du graphe.
	******************************************/
	void GRAdetruire();


	/*****************************************
	Recopie d'un graphe.
	******************************************
	Entrée : une référence sur une instance de CGraphe
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la recopie du graphe passé en paramètre.
	******************************************/
	void GRArecopierGraphe(const CGraphe & GRAobjet);

public:

	/*****************************************
	Constructeur à un argument.
	******************************************
	Entrée : le nombre de sommets du graphe à construire (unsigned int).
	Nécessite : rien.
	Sortie : une instance de CGraphe.
	Entraîne : la création d'un graphe contenant le nombre de sommets indiqués.
	******************************************/
	CGraphe();


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entrée : une instance de CGraphe.
	Nécessite : rien.
	Sortie : une instance de CGraphe.
	Entraîne : la création d'une copie du graphe passé en paramètre.
	******************************************/
	CGraphe(const CGraphe & GRAobjet);


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la désallocation des pointeurs.
	******************************************/
	~CGraphe();


	/*****************************************
	Surcharge de l'opérateur =.
	******************************************
	Entrée : une instance de CGraphe.
	Nécessite : rien.
	Sortie : une instance de CGraphe.
	Entraîne : la recopie du graphe passé en paramètre.
	******************************************/
	CGraphe & operator=(const CGraphe & GRAobjet);


	/*****************************************
	Surcharge de l'opérateur ==
	******************************************
	Entrée : une instance de CGraphe.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : les graphes sont identiques)
				ou (false : les graphes sont différents).
	******************************************/
	bool operator==(const CGraphe & GRAobjet) const;


	/*****************************************
	Surcharge de l'opérateur !=.
	******************************************
	Entrée : une instance de CGraphe.
	Nécessite : rien.
	Sortie : un booléen.
	Entraîne : (true : les graphes sont différents)
				ou (false : les graphes sont identiques).
	******************************************/
	bool operator!=(const CGraphe & GRAobjet) const;



	/*****************************************
	Lecture du nombre de sommets.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le nombre de sommets du graphe (unsigned int).
	Entraîne : rien.
	******************************************/
	unsigned int GRAgetNbSommets() const { return uiGRAnbSommets; } ;


	/*****************************************
	Création d'un sommet.
	******************************************
	Entrée : le numéro du sommet (unsigned int).
	Nécessite : le numéro est un nombre > 0.
	Sortie : un pointeur sur une instance de CSommet.
	Entraîne : la création d'un sommet.
	******************************************/
	CSommet * GRAcreerSommet(unsigned int uiNumero);


	/*****************************************
	Ajout d'un sommet.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'ajout du sommet passé en paramètre au graphe.
	******************************************/
	void GRAajouterSommet(CSommet * pSOMobjet);


	/*****************************************
	Lecture d'un sommet.
	******************************************
	Entrée : le numéro du sommet (unsigned int).
	Nécessite : le nméro est > 0.
	Sortie : un pointeur sur une instance de CSommet.
	Entraîne : rien.
	******************************************/
	CSommet * GRAgetSommetNumero(unsigned int uiNumero) const;


	/*****************************************
	Lecture de la position d'un sommet.
	******************************************
	Entrée : la position du sommet (unsigned int).
	Nécessite : la position est > 0.
	Sortie : une instance de CSommet.
	Entraîne : rien.
	******************************************/
	CSommet * GRAgetSommetPosition(unsigned int uiPos) const;


	/*****************************************
	Lecture de la position d'un sommet.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : la position du sommet (unsigned int).
	Entraîne : rien.
	******************************************/
	unsigned int GRAgetPosSommet(const CSommet * pSOMobjet) const;


	/*****************************************
	Suppression d'un sommet.
	******************************************
	Entrée : un pointeur sur une instance de CSommet.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : la suppression du sommet passé en paramètre du graphe.
	******************************************/
	void GRAsupprimerSommet(CSommet * pSOMobjet);
	

	/*****************************************
	Affichage d'un graphe.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'affichage d'un graphe.
	******************************************/
	void GRAafficher() const;

	// A supprimer ?
	void GRAdebug() const;
};

/*****************************************
Surchage de l'opérateur <<.
******************************************
Entrée : un flux, une référence sur une instance de CGraphe.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du graphe passé en paramètre.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, const CGraphe & GRAgraphe);


/*****************************************
Surchage de l'opérateur <<.
******************************************
Entrée : un flux, un pointeur sur une instance de CGraphe.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du graphe passé en paramètre.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, const CGraphe * GRAgraphe);

#endif