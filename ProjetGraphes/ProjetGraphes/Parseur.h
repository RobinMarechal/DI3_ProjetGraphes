#ifndef CPARSEUR_H
#define CPARSEUR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"
#include "TableauAssociatif.h"
#include "helpers.h"


/*************************************************
Classe permettant de cr�er un CTableau associatif
� partir d'un fichier texte contenant des donn�es.
***************************************************/
class CParseur
{
public:

	/*****************************************
	Parse un fichier.
	******************************************
	Entr�e : le chemin du fichier � parser.
	N�cessite : rien.
	Sortie : une instance de CTableauAssociatif contenant les donn�es du fichier allou�e sur le tas.
	Entra�ne : soul�ve une Cexception en cas d'erreur de syntaxe dans le fichier
	Entra�ne : Allocation d'une chaine de caract�re (via new).
	******************************************/
	static CTableauAssociatif * PARparserFichier(const char * pcFichier);


	/*****************************************
	Analyseur syntaxique.
	******************************************
	Entr�e : le chemin du fichier.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : soul�ve une Cexception en cas d'erreur de syntaxe dans le fichier
	******************************************/
	static void PARanalyseSyntaxique(const char * pcFichier);


	/*****************************************
	Extraire la partie gauche d'une ligne du fichier
	******************************************
	Entr�e : la ligne du fichier � analyser
	Entr�e : le caract�re qui s�pare les deux parties
	N�cessite : la ligne contient un (et un seul) '='.
	Sortie : la partie gauche de la ligne allou�e sur le tas.
	Entra�ne : Allocation d'une chaine de caract�re (via new).
	******************************************/
	static char * PARextrairePartieGauche(const char * pcLigne, const char cSeparateur = '=');


	/*****************************************
	Extraire la partie gauche d'une ligne du fichier
	******************************************
	Entr�e : la ligne du fichier � analyser
	Entr�e : le caract�re qui s�pare les deux parties
	N�cessite : la ligne contient un (et un seul) '='.
	Sortie : la partie gauche de la ligne allou�e sur le tas, ou nullptr
	si le s�parateur ne fait pas partie de la chaine.
	Entra�ne : Allocation d'une chaine de caract�re (via new).
	******************************************/
	static char *  PARextrairePartieDroite(const char * pcLigne, const char cSeparateur = '=');
};
#endif