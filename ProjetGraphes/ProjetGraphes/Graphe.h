#ifndef CGRAPHE_H
#define CGRAPHE_H

#include <iostream>

#include "Sommet.h"
#include "helpers.h"

#define GRA_AUCUN_SOMMET 0
#define GRA_BALISE_NB_SOMMETS "NBSommets"
#define GRA_BALISE_NB_ARCS "NBArcs"
#define GRA_BALISE_SOMMETS "Sommets"
#define GRA_BALISE_ARCS "Arcs"
#define GRA_BALISE_NUMERO "Numero"
#define GRA_BALISE_DEBUT "Debut"
#define GRA_BALISE_FIN "Fin"

class CSommet;
class CTableauAssociatif;

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
	unsigned int GRAgetNbSommets() const { return uiGRAnbSommets; };


	/*****************************************
	Cr�ation d'un sommet.
	******************************************
	Entr�e : le num�ro du sommet.
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
	Cr�ation d'un arc reliant deux sommets.
	******************************************
	Entr�e : le num�ro du sommet de d�part.
	Entr�e : le num�ro du sommet d'arriv�e
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : La cr�ation d'un arc entre les deux sommets.
	Entra�ne : Une exception de type Cexception si le graphe ne poss�de 
			   pas de sommets num�ro uiNumDepart et uiNumArrivee.
	Entra�ne : Un exception de type Cexception si la cr�ation de l'arc a �chou�.
	******************************************/
	void GRAcreerArc(unsigned int uiNumDepart, unsigned int uiNumArrivee);


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


	/*****************************************
	V�rifie le contenu d'une instance de CTableauAssociatif
	pour cr�er un objet CGraphe
	******************************************
	Entr�e : Un pointeur sur une instance de CTableauAssociatif.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : une Cexception  est lev�e si le tableau de contient pas "NBSommets", "NBArcs", "Sommets" et "Arcs",
	ou que les types correspondants sont incorrects (resp. Entier, Entier, Chaine, Chaine)
	******************************************/
	static void GRAverifierContenuTableau(CTableauAssociatif * pTABtab);

	/*****************************************
	G�n�ration d'un graphe � partir d'un fichier
	******************************************
	Entr�e : le nom du fichier
	N�cessite : rien.
	Sortie : une instance de CGraphe.
	Entra�ne : La cr�ation d'un objet CGraphe avec les informations du fichier
	Entra�ne : Une exception de type Cexception en cas de fichier introuvable ou d'erreur de syntaxe.
	******************************************/
	static CGraphe GRAgenerer(const char * pcFichier);

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