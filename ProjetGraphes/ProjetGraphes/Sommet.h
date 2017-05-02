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
	Entr�e : une r�f�rence sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la recopie du sommet pass� en param�tre.
	******************************************/
	void SOMrecopier(CSommet & SOMobjet);


	/*****************************************
	Ajout d'un pr�decesseur.
	******************************************
	Entr�e : un pointeur sur une instance de CSOmmet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'ajout d'un pr�decesseur du sommet.
	******************************************/
	void SOMajouterPredecesseur(CSommet * pSOMpredecesseur);


	/*****************************************
	Suppression d'un pr�decesseur.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la suppression d'un pr�decesseur de sommet.
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
	Entr�e : une r�f�rence sur une instance de CSommet.
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
	Entr�e : une r�f�rence sur une instance de CSommet.
	N�cessite : rien.
	Sortie : une r�f�rence sur une instance de CSommet.
	Entra�ne : l'affectation du sommet pass� en param�tre.
	******************************************/
	CSommet & operator=(CSommet & SOMobjet);


	/*****************************************
	Surcharge de l'op�rateur >>.
	******************************************
	Entr�e : une r�f�rence sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'ajout d'un successeur au sommet.
	******************************************/
	void operator>>(CSommet * SOMsuccesseur);


	/*****************************************
	Surcharge de l'op�rateur ==.
	******************************************
	Entr�e : une r�f�rence sur une instance de CSommet.
	N�cessite : rien.
	Sortie : un bool�en.
	Entra�ne : (true : les sommets sont identiques)
				ou (false : les sommets sont diff�rents).
	******************************************/
	bool operator==(CSommet & SOMobjet) const;


	/*****************************************
	Surcharge de l'op�rateur !=.
	******************************************
	Entr�e : une r�f�rence sur une instance de CSommet.
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
	N�cessite : la position > 0.
	Sortie : un pointeur sur une instance de CSommet.
	Entra�ne : rien.
	******************************************/
	CSommet * SOMgetSuccesseur(unsigned int uiPos) const;


	/*****************************************
	Lecture d'un pr�decesseur.
	******************************************
	Entr�e : la position du pr�decesseur (unsigned int).
	N�cessite : la position > 0.
	Sortie : un pointeur sur une instance de CSommet.
	Entra�ne : rien.
	******************************************/
	CSommet * SOMgetPredecesseur(unsigned int uiPos) const;


	/*****************************************
	Lecture d'un arc partant.
	******************************************
	Entr�e : la position de l'arc (unsigned int).
	N�cessite : la position > 0.
	Sortie : un pointeur sur une instance de CArcPArtant.
	Entra�ne : rien.
	******************************************/
	CArcPartant * SOMgetArcPartant(unsigned int uiPos) const;


	/*****************************************
	Lecture d'un arc arrivant.
	******************************************
	Entr�e : la position de l'arc arrivant (unsigned int).
	N�cessite : la position > 0.
	Sortie : un pointeur sur une instance de CArcArrivant.
	Entra�ne : rien.
	******************************************/
	CArcArrivant * SOMgetArcArrivant(unsigned int uiPos) const;


	/*****************************************
	Lecture du num�ro du sommet.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le num�ro du sommet (unsigned int).
	Entra�ne : rien.
	******************************************/
	unsigned int SOMgetNumero() const;


	/*****************************************
	Lecture du nombre de successeurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le nombre de successeurs (unsigned int).
	Entra�ne : rien.
	******************************************/
	unsigned int SOMgetNbSuccesseurs() const;


	/*****************************************
	Lecture du nombre de pr�decesseurs.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le nombre de pr�decesseurs (unsigned int).
	Entra�ne : rien.
	******************************************/
	unsigned int SOMgetNbPredecesseurs() const;


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
	Entra�ne : l'ajout du sommet indiqu� en successeur
			   et cr�ation d'un arc entre les deux.
	******************************************/
	void SOMajouterSuccesseur(CSommet *  pSOMsuccesseur);


	/*****************************************
	Suppression d'un successeur.
	******************************************
	Entr�e : un pointeur sur une instance de CSommet.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : la suppression du successeur
			   et de l'arc entre les deux.
	******************************************/
	void SOMsupprimerSuccesseur(CSommet * pSOMsuccesseur);

	// A supprimer ?
	void SOMdebug() const;
};

/*****************************************
Affichage du sommet.
******************************************
Entr�e : un flux, une r�f�rence sur une instance de CSommet.
N�cessite : rien.
Sortie : un flux.
Entra�ne : l'affichage du sommet.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, CSommet & SOMsommet);


/*****************************************
Affichage du sommet.
******************************************
Entr�e : un flux, un pointeur sur une instance de CSommet.
N�cessite : rien.
Sortie : un flux.
Entra�ne : l'affichage du sommet.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, CSommet * SOMsommet);

#endif