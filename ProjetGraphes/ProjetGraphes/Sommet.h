#ifndef CSOMMET_H
#define CSOMMET_H

#include "Graphe.h"
#include "ArcPartant.h"
#include "ArcArrivant.h"

class CGraphe;
class CArcPartant;
class CArcArrivant;

/********************************************
Classe repr�sentant un sommet dans un graphe
*********************************************/
class CSommet
{
private:
	unsigned int uiSOMnumero; // Num�ro du sommets
	unsigned int uiSOMnbSuccesseurs; // Nombre de sommets successeurs
	unsigned int uiSOMnbPredecesseurs; // Nombre de sommets pr�d�cesseurs

	// Relations
	CGraphe * pGRASOMgraphe; // Graphe auquel le sommet appartient
	CArcPartant ** ppPARSOMarcsPartants; // La liste des arcs partants
	CArcArrivant ** ppARRSOMarcsArrivants; // La liste des arcs arrivants

	/*****************************************
	Initialisation du sommet.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation du sommet.
	******************************************/
	void SOMinit();


	/*****************************************
	Destruction du sommet.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la destruction des arcs reli�s au sommet.
	******************************************/
	void SOMdetruire();


	/*****************************************
	Recopie du sommet.
	******************************************
	Entr�e : une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la recopie du sommet pass� en param�tre.
	******************************************/
	void SOMrecopier(CSommet & SOMobjet);


	/*****************************************
	Ajout d'un pr�decesseur.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : Cette m�thode doit �tre appel�e uniquement par CSommet::SOMajouterSuccesseur().
	Sortie : rien.
	Entra�ne : l'ajout d'un arc arrivant au sommet, ou le remplacement s'il existait d�j�.
	******************************************/
	void SOMajouterPredecesseur(CSommet * pSOMpredecesseur);


	/*****************************************
	Suppression d'un pr�decesseur.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : Cette m�thode doit �tre appel�e uniquement par CSommet::SOMsupprimerSuccesseur().
	Sortie : rien.
	Entra�ne : la suppression d'un arc arrivant au sommet.
	******************************************/
	void SOMsupprimerPredecesseur(CSommet * pSOMpredecesseur);

public:

	/*****************************************
	Constructeur � deux arguments.
	******************************************
	Entr�e : un pointeur sur une instance de CGraphe,
			 le nnum�ro du sommet (unsigned int).
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la cr�ation d'un sommet avec le num�ro indiqu�.
	******************************************/
	CSommet(CGraphe * pGRAgraphe, unsigned int uiNumero);


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entr�e : une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la recopie du sommet pass� en param�tre.
	******************************************/
	CSommet(CSommet & SOMobjet);


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la destruction des arcs du sommet.
	******************************************/
	~CSommet();


	/*****************************************
	Surcharge de l'op�rateur =.
	******************************************
	Entr�e : une instance de CSommet.
	N�cessite : rien.
	Sortie : une instance de CSommet.
	Entra�ne : l'affectation du sommet pass� en param�tre.
	******************************************/
	CSommet & operator=(CSommet & SOMobjet);


	/*****************************************
	Surcharge de l'op�rateur ==.
	******************************************
	Entr�e : une instance de CSommet.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les sommets sont identiques)
				ou (false : les sommets sont diff�rents).
	******************************************/
	bool operator==(CSommet & SOMobjet) const;


	/*****************************************
	Surcharge de l'op�rateur !=.
	******************************************
	Entr�e : une instance de CSommet.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les sommets sont diff�rents)
				ou (false : les sommets dont identiques).
	******************************************/
	bool operator!=(CSommet & SOMobjet) const;


	/*****************************************
	Lecture du graphe.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : un pointeur sur une instance de CGraphe.
	Entra�ne : rien.
	******************************************/
	CGraphe * SOMgetGraphe() const;


	/*****************************************
	Lecture d'un successeur.
	******************************************
	Entr�e : la position du successeur (unsigned int).
	N�cessite : rien.
	Sortie : un pointeur sur une instance de CSommet ou nullptr si aucun successeur trouv�.
	Entra�ne : rien.
	******************************************/
	CSommet * SOMgetSuccesseur(unsigned int uiPos) const;


	/*****************************************
	Lecture d'un pr�decesseur.
	******************************************
	Entr�e : la position du pr�decesseur (unsigned int).
	N�cessite : rien.
	Sortie : un pointeur sur une instance de CSommet ou nullptr si aucun successeur trouv�.
	Entra�ne : rien.
	******************************************/
	CSommet * SOMgetPredecesseur(unsigned int uiPos) const;


	/*****************************************
	Lecture d'un arc arrivant.
	******************************************
	Entr�e : la position de l'arc arrivant.
	N�cessite : rien.
	Sortie : un pointeur sur une instance de CArcArrivant ou nullptr si aucun arc trouv�.
	Entra�ne : rien.
	******************************************/
	CArcArrivant * SOMgetArcArrivant(unsigned int uiPos) const;



	/*****************************************
	Lecture d'un arc partant.
	******************************************
	Entr�e : la position de l'arc partant.
	N�cessite : rien.
	Sortie : un pointeur sur une instance de CArcPartant ou nullptr si aucun arc trouv�.
	Entra�ne : rien.
	******************************************/
	CArcPartant * SOMgetArcPartant(unsigned int uiPos) const;


	/*****************************************
	Lecture du num�ro du sommet.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le num�ro du sommet (unsigned int).
	Entra�ne : rien.
	******************************************/
	unsigned int SOMgetNumero() const { return uiSOMnumero; }


	/*****************************************
	Lecture du nombre de successeurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le nombre de successeurs (unsigned int).
	Entra�ne : rien.
	******************************************/
	unsigned int SOMgetNbSuccesseurs() const { return uiSOMnbSuccesseurs; }


	/*****************************************
	Lecture du nombre de pr�decesseurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le nombre de pr�decesseurs (unsigned int).
	Entra�ne : rien.
	******************************************/
	unsigned int SOMgetNbPredecesseurs() const { return uiSOMnbPredecesseurs; }


	/*****************************************
	Lecture de la position d'un successeur.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : la position du successeur (int).
	Entra�ne : (la position du successeur s'il existe)
				ou (-1 s'il n'existe pas).
	******************************************/
	int SOMgetPositionSuccesseur(CSommet * pSOMsucc) const;


	/*****************************************
	Lecture de la position d'un pr�decesseur.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : la position du pr�decesseur (int).
	Entra�ne : (la position du pr�decesseur s'il existe)
				ou (-1 s'il n'existe pas).
	******************************************/
	int SOMgetPositionPredecesseur(CSommet * pSOMpred) const;


	/*****************************************
	Ajout d'un successeur.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : Ajouter d'un arc partant au sommet, ou remplacement si un existait d�j�.
	******************************************/
	void SOMajouterSuccesseur(CSommet *  pSOMsuccesseur);


	/*****************************************
	Suppression d'un successeur.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : Suppression d'un arc partant du sommet
	******************************************/
	void SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur);
};

/*****************************************
Affichage du sommet.
******************************************
Entr�e : un flux
Entr�e : une instance de CSommet.
N�cessite : rien.
Sortie : un flux.
Entra�ne : l'affichage du sommet.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet);

#endif