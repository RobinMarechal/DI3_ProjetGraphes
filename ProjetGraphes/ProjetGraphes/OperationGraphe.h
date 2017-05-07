#ifndef OPERATION_GRAPHE_H
#define OPERATION_GRAPHE_H

#include "Graphe.h"
#include "Sommet.h"
#include "ArcArrivant.h"
#include "ArcPartant.h"
#include "Cexception.h"
#include "helpers.h"

class COperationGraphe
{
public:

	/*****************************************
	Constructeur par défaut.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : rien.
	******************************************/
	COperationGraphe();


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : rien.
	******************************************/
	~COperationGraphe();


	/*****************************************
	Inversion du graphe.
	******************************************
	Entrée : une référence sur une instance de CGraphe.
	Nécessite : rien.
	Sortie : un pointeur sur une instance de CGraphe.
	Entraîne : l'inversion du graphe passé en paramètre.
	******************************************/
	CGraphe * OPGinverserGraphe(const CGraphe & GRAgraphe) const;
};

#endif // OPERATION_GRAPHE_H