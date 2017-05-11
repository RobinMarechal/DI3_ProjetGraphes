#ifndef OPERATION_GRAPHE_H
#define OPERATION_GRAPHE_H

#include "Graphe.h"
#include "Sommet.h"
#include "ArcArrivant.h"
#include "ArcPartant.h"
#include "Cexception.h"
#include "helpers.h"


/********************************************
Classe "boite � outils" permettant
d'effectuer des op�rations sur des graphes
*********************************************/
class COperationGraphe
{
public:

	/*****************************************
	Constructeur par d�faut.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : rien.
	******************************************/
	COperationGraphe();


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : rien.
	******************************************/
	~COperationGraphe();


	/*****************************************
	Inversion du graphe.
	******************************************
	Entr�e : une instance de CGraphe.
	N�cessite : rien.
	Sortie : un pointeur sur une instance de CGraphe.
	Entra�ne : l'inversion du graphe pass� en param�tre.
	******************************************/
	CGraphe OPGinverserGraphe(const CGraphe & GRAgraphe) const;
};

#endif // OPERATION_GRAPHE_H