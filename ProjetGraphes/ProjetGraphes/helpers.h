#ifndef HERLPERS_H
#define HERLPERS_H

#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/*******************************************
Types de donnée
********************************************/
#define TYPE_NON_DEFINI 0
#define TYPE_ENTIER 1
#define TYPE_REEL 2
#define TYPE_CHAINE 3

/*****************************************
Retourne le type correspondant à la chaine en paramètre
******************************************
Entrée : la chaine à analyser
Nécessite : rien
Sortie : l'entier correspondant au type de la chaine
=> TYPE_ENTIER, TYPE_REEL ou TYPE_CHAINE
Entraîne : rien
******************************************/
int analyserType(char * pcCle);


/*****************************************
Extraction d'une sous chaine
******************************************
Entrée : un pointeur sur le début de la sous-chaîne,
Entrée : un pointeur sur la fin de la sous-chaîne.
Nécessite : pcDebut >= pcFin.
Sortie : la sous-chaîne souhaitée.
Entraîne : Allocation dynamique d'un char * (via new)
******************************************/
char * sousChaine(const char * pcDebut, const char * pcFin);


/*****************************************
transformation d'une chaine de caratères en minuscule.
******************************************
Entrée : une chaîne de caractères.
Nécessite : rien.
Sortie : rien.
Entraîne : Modification de la chaine pointée par pcStr
-> tous les caractères sont en minuscule.
******************************************/
void transformerEnMinuscule(char * pcStr);


/*****************************************
Suppression des espaces en début et fin de chaine.
******************************************
Entrée : une chaîne de caractères.
Nécessite : rien.
Sortie : Une copie de la chaine de caractère sans les espaces de début et de fin.
Entraîne : L'allocation sur le tas d'un char* (via new).
******************************************/
char * supprimerEspaces(char pcStr[]);


/*****************************************
Affichage d'un message d'erreur dans la console
******************************************
Entrée : le message à afficher
Entrée : true : arrêter le programme, false sinon
Nécessite : rien
Entraîne : L'affichage d'un message en rouge dans la console
Entraîne : L'arrêt du programme si la valeur de bStop est true
******************************************/
void erreur(char * pcMsg, bool bStop = true);


/*****************************************
Tri d'un tableau (ou d'un sous tableau)
******************************************
Entrée : Le tableau a trier
Entrée : La taille du tableau
Nécessite : uiTaille <= taille de ptTab
Nécessite : <T> est un type primitif ou une classe qui surchage l'operateur >
Entraîne : Le changement de l'ordre des valeurs du tableau
******************************************/
template <class T>
void trierTableau(T * ptTab, unsigned int uiTaille);


/*****************************************
Comparaison de deux tableaux (ou sous tableaux)
******************************************
Entrée : Le tableau a trier
Entrée : La taille du tableau
Nécessite : uiTaille <= taille de ptTab1
Nécessite : uiTaille <= taille de ptTab2
Nécessite : <T> est un type primitif ou une classe qui surchage les operateurs != et <
Entraîne : Le tri des tableaux passés en paramètre
******************************************/
template <class T>
bool tableauxSontEquivalents(T * ptTab1, T * ptTab2, unsigned int uiTaille);


// Implémentation des fonctions templates 

/*****************************************
Tri d'un tableau (ou d'un sous tableau)
******************************************
Entrée : Le tableau a trier
Entrée : La taille du tableau
Nécessite : uiTaille <= taille de ptTab
Nécessite : <T> est un type primitif ou une classe qui surchage l'operateur >
Entraîne : Le changement de l'ordre des valeurs du tableau
******************************************/
template <class T>
void trierTableau(T * ptTab, unsigned int uiTaille)
{
	unsigned int uiBoucleI, uiBoucleJ;

	for (uiBoucleI = 0; uiBoucleI < uiTaille; uiBoucleI++)
	{
		unsigned int uiPos = uiBoucleI;
		T tMin = ptTab[uiBoucleI];

		// récuperer le min et sa position dans le sous tableau partant de uiBoucleI
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
Entrée : Le tableau a trier
Entrée : La taille du tableau
Nécessite : uiTaille <= taille de ptTab1
Nécessite : uiTaille <= taille de ptTab2
Nécessite : <T> est un type primitif ou une classe qui surchage les operateurs != et <
Entraîne : Le tri des tableaux passés en paramètre
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