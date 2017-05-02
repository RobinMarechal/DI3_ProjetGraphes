#ifndef HERLPERS_H
#define HERLPERS_H

#include "helpers.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/*****************************************
Retourne le type correspondant � la chaine en param�tre
******************************************
Entr�e : la chaine � analyser
N�cessite : rien
Sortie : l'entier correspondant au type de la chaine
=> (0 = entier) || (1 = r�el) || (3 = chaine)
Entra�ne : rien
******************************************/
int analyserType(char * pcCle);


/*****************************************
Extraction d'une sous chaine
******************************************
Entr�e : un pointeur sur le d�but de la sous-cha�ne,
Entr�e : un pointeur sur la fin de la sous-cha�ne.
N�cessite : pcStart >= pcEnd.
Sortie : la sous-cha�ne souhait�e (de type char *).
Entra�ne : Allocation dynamique d'un char * (malloc)
******************************************/
char * sousChaine(const char * pcStart, const char * pcEnd);


/*****************************************
transformation d'une chaine de carat�res en minuscule.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : rien.
Entra�ne : Modification de la chaine point�e par pcStr
-> tous les caract�res sont en minuscule.
******************************************/
void transformerEnMinuscule(char * pcStr);


/*****************************************
Suppression des espaces en d�but et fin de chaine.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : Une copie de la chaine de caract�re sans les espaces de d�but et de fin.
Entra�ne : rien.
******************************************/
char * supprimerEspaces(char pcStr[]);


void erreur(char * pcMsg, bool bStop = true);


template <class T>
void trierTableau(T * ptTab, unsigned int uiTaille);

template <class T>
bool tableauxSontEquivalents(T * ptTab1, T * ptTab2, unsigned int uiTaille);


template <class T>
void trierTableau(T * ptTab, unsigned int uiTaille)
{
	unsigned int uiBoucleI, uiBoucleJ;

	for (uiBoucleI = 0; uiBoucleI < uiTaille; uiBoucleI++)
	{
		unsigned int uiPos = uiBoucleI;
		T tMin = ptTab[uiBoucleI];

		// r�cuperer le min et sa position dans le sous tableau partant de uiBoucleI
		for (uiBoucleJ = uiBoucleI; uiBoucleJ < uiTaille; uiBoucleJ++)
		{
			if (tMin > ptTab[uiBoucleJ])
			{
				tMin = ptTab[uiBoucleJ];
				uiPos = uiBoucleJ;
			}
		}

		// On inverse les valeurs aux positions uiPos (le min) et uiBoucleI
		ptTab[uiPos] = ptTab[uiBoucleI];
		ptTab[uiBoucleI] = tMin;
	}
}

// pr�condition : meme taille 
template <class T>
bool tableauxSontEquivalents(T * ptTab1, T * ptTab2, unsigned int uiTaille)
{
	unsigned int uiBoucle;

	// On trie les tableaux
	trierTableau<T>(ptTab1, uiTaille);
	trierTableau<T>(ptTab2, uiTaille);

	// On compare chaque valeur
	for (uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++)
	{
		if (ptTab1[uiBoucle] != ptTab2[uiBoucle])
		{
			return false;
		}
	}

	return true;
}

#endif;