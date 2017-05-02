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
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation du graphe.
	******************************************/
	void GRAinit();


	/*****************************************
	Destruction d'un graphe.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la destruction du graphe.
	******************************************/
	void GRAdetruire();


	/*****************************************
	Recopie d'un graphe.
	******************************************
	Entr�e : une r�f�rence sur une instance de CGraphe
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la recopie du graphe pass� en param�tre.
	******************************************/
	void GRArecopierGraphe(const CGraphe & GRAobjet);

public:

	/*****************************************
	Constructeur � un argument.
	******************************************
	Entr�e : le nombre de sommets du graphe � construire (unsigned int).
	N�cessite : rien.
	Sortie : une instance de CGraphe.
	Entra�ne : la cr�ation d'un graphe contenant le nombre de sommets indiqu�s.
	******************************************/
	CGraphe();


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entr�e : une instance de CGraphe.
	N�cessite : rien.
	Sortie : une instance de CGraphe.
	Entra�ne : la cr�ation d'une copie du graphe pass� en param�tre.
	******************************************/
	CGraphe(const CGraphe & GRAobjet);


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la d�sallocation des pointeurs.
	******************************************/
	~CGraphe();


	/*****************************************
	Surcharge de l'op�rateur =.
	******************************************
	Entr�e : une instance de CGraphe.
	N�cessite : rien.
	Sortie : une instance de CGraphe.
	Entra�ne : la recopie du graphe pass� en param�tre.
	******************************************/
	CGraphe & operator=(const CGraphe & GRAobjet);


	/*****************************************
	Surcharge de l'op�rateur ==
	******************************************
	Entr�e : une instance de CGraphe.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les graphes sont identiques)
				ou (false : les graphes sont diff�rents).
	******************************************/
	bool operator==(const CGraphe & GRAobjet) const;


	/*****************************************
	Surcharge de l'op�rateur !=.
	******************************************
	Entr�e : une instance de CGraphe.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les graphes sont diff�rents)
				ou (false : les graphes sont identiques).
	******************************************/
	bool operator!=(const CGraphe & GRAobjet) const;



	/*****************************************
	Lecture du nombre de sommets.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le nombre de sommets du graphe (unsigned int).
	Entra�ne : rien.
	******************************************/
	unsigned int GRAgetNbSommets() const { return uiGRAnbSommets; } ;


	/*****************************************
	Cr�ation d'un sommet.
	******************************************
	Entr�e : le num�ro du sommet (unsigned int).
	N�cessite : le num�ro est un nombre > 0.
	Sortie : un pointeur sur une instance de CSommet.
	Entra�ne : la cr�ation d'un sommet.
	******************************************/
	CSommet * GRAcreerSommet(unsigned int uiNumero);


	/*****************************************
	Ajout d'un sommet.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'ajout du sommet pass� en param�tre au graphe.
	******************************************/
	void GRAajouterSommet(CSommet * pSOMobjet);


	/*****************************************
	Lecture d'un sommet.
	******************************************
	Entr�e : le num�ro du sommet (unsigned int).
	N�cessite : le nm�ro est > 0.
	Sortie : un pointeur sur une instance de CSommet.
	Entra�ne : rien.
	******************************************/
	CSommet * GRAgetSommetNumero(unsigned int uiNumero) const;


	/*****************************************
	Lecture de la position d'un sommet.
	******************************************
	Entr�e : la position du sommet (unsigned int).
	N�cessite : la position est > 0.
	Sortie : une instance de CSommet.
	Entra�ne : rien.
	******************************************/
	CSommet * GRAgetSommetPosition(unsigned int uiPos) const;


	/*****************************************
	Lecture de la position d'un sommet.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : la position du sommet (unsigned int).
	Entra�ne : rien.
	******************************************/
	unsigned int GRAgetPosSommet(const CSommet * pSOMobjet) const;


	/*****************************************
	Suppression d'un sommet.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la suppression du sommet pass� en param�tre du graphe.
	******************************************/
	void GRAsupprimerSommet(CSommet * pSOMobjet);
	

	/*****************************************
	Affichage d'un graphe.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'affichage d'un graphe.
	******************************************/
	void GRAafficher() const;

	// A supprimer ?
	void GRAdebug() const;
};

/*****************************************
Surchage de l'op�rateur <<.
******************************************
Entr�e : un flux, une r�f�rence sur une instance de CGraphe.
N�cessite : rien.
Sortie : un flux.
Entra�ne : l'affichage du graphe pass� en param�tre.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, const CGraphe & GRAgraphe);


/*****************************************
Surchage de l'op�rateur <<.
******************************************
Entr�e : un flux, un pointeur sur une instance de CGraphe.
N�cessite : rien.
Sortie : un flux.
Entra�ne : l'affichage du graphe pass� en param�tre.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, const CGraphe * GRAgraphe);

#endif