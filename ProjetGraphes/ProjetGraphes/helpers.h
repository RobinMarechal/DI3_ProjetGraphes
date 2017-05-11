#ifndef HERLPERS_H
#define HERLPERS_H

#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/*******************************************
Types de donn�e
********************************************/
#define TYPE_NON_DEFINI 0
#define TYPE_ENTIER 1
#define TYPE_REEL 2
#define TYPE_CHAINE 3

/*****************************************
Retourne le type correspondant � la chaine en param�tre
******************************************
Entr�e : la chaine � analyser
N�cessite : rien
Sortie : l'entier correspondant au type de la chaine
=> TYPE_ENTIER, TYPE_REEL ou TYPE_CHAINE
Entra�ne : rien
******************************************/
int analyserType(char * pcCle);


/*****************************************
Extraction d'une sous chaine
******************************************
Entr�e : un pointeur sur le d�but de la sous-cha�ne,
Entr�e : un pointeur sur la fin de la sous-cha�ne.
N�cessite : pcDebut >= pcFin.
Sortie : la sous-cha�ne souhait�e.
Entra�ne : Allocation dynamique d'un char * (via new)
******************************************/
char * sousChaine(const char * pcDebut, const char * pcFin);


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
Entra�ne : L'allocation sur le tas d'un char* (via new).
******************************************/
char * supprimerEspaces(char pcStr[]);


/*****************************************
Affichage d'un message d'erreur dans la console
******************************************
Entr�e : le message � afficher
Entr�e : true : arr�ter le programme, false sinon
N�cessite : rien
Entra�ne : L'affichage d'un message en rouge dans la console
Entra�ne : L'arr�t du programme si la valeur de bStop est true
******************************************/
void erreur(char * pcMsg, bool bStop = true);


/*****************************************
Tri d'un tableau (ou d'un sous tableau)
******************************************
Entr�e : Le tableau a trier
Entr�e : La taille du tableau
N�cessite : uiTaille <= taille de ptTab
N�cessite : <T> est un type primitif ou une classe qui surchage l'operateur >
Entra�ne : Le changement de l'ordre des valeurs du tableau
******************************************/
template <class T>
void trierTableau(T * ptTab, unsigned int uiTaille);


/*****************************************
Comparaison de deux tableaux (ou sous tableaux)
******************************************
Entr�e : Le tableau a trier
Entr�e : La taille du tableau
N�cessite : uiTaille <= taille de ptTab1
N�cessite : uiTaille <= taille de ptTab2
N�cessite : <T> est un type primitif ou une classe qui surchage les operateurs != et <
Entra�ne : Le tri des tableaux pass�s en param�tre
******************************************/
template <class T>
bool tableauxSontEquivalents(T * ptTab1, T * ptTab2, unsigned int uiTaille);


// Impl�mentation des fonctions templates 

/*****************************************
Tri d'un tableau (ou d'un sous tableau)
******************************************
Entr�e : Le tableau a trier
Entr�e : La taille du tableau
N�cessite : uiTaille <= taille de ptTab
N�cessite : <T> est un type primitif ou une classe qui surchage l'operateur >
Entra�ne : Le changement de l'ordre des valeurs du tableau
******************************************/
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


/*****************************************
Comparaison de deux tableaux (ou sous tableaux)
******************************************
Entr�e : Le tableau a trier
Entr�e : La taille du tableau
N�cessite : uiTaille <= taille de ptTab1
N�cessite : uiTaille <= taille de ptTab2
N�cessite : <T> est un type primitif ou une classe qui surchage les operateurs != et <
Entra�ne : Le tri des tableaux pass�s en param�tre
******************************************/
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