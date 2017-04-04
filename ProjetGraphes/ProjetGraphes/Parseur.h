#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Matrice.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"
#include "TableauAssociatif.h"
#include "helpers.h"
#include "constantes.h"


/*************************************************
Classe permettant de créer un CTableau associatif
à partir d'un fichier texte contenant des données.
***************************************************/
class CParseur
{
public:
	
	/*****************************************
	Parse un fichier.
	******************************************
	Entrée : le chemin du fichier à parser.
	Nécessite : rien.
	Sortie : une instance de CTableauAssociatif contenant les données du fichier.
	Entraîne : soulève une Cexception en cas d'erreur de syntaxe dans le fichier
	******************************************/
	static CTableauAssociatif PARparserFichier(char * pcFichier);


	/*****************************************
	Analyseur syntaxique.
	******************************************
	Entrée : le chemin du fichier.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : soulève une Cexception en cas d'erreur de syntaxe dans le fichier
	******************************************/
	static void PARanalyseSyntaxique(char * pcFichier);


	/*****************************************
	Extraire la partie gauche d'une ligne du fichier
	******************************************
	Entrée : la ligne du fichier à analyser
	Nécessite : la ligne contient un (et un seul) '='.
	Sortie : la partie gauche de la ligne.
	Entraîne : rien.
	******************************************/
	static char * PARextraireBalise(char * pcLigne);


	/*****************************************
	Extraire la partie droite d'une ligne du fichier
	******************************************
	Entrée : la ligne du fichier à analyser
	Nécessite : la ligne contient un (et un seul) '='.
	Sortie : la partie droite de la ligne.
	Entraîne : rien.
	******************************************/
	static char *  PARextraireValeur(char * pcLigne);
};
#endif