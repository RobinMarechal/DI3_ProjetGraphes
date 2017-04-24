#ifndef HERLPERS_H
#define HERLPERS_H

#include "helpers.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/*****************************************
Retourne le type correspondant à la chaine en paramètre
******************************************
Entrée : la chaine à analyser
Nécessite : rien
Sortie : l'entier correspondant au type de la chaine
=> (0 = entier) || (1 = réel) || (3 = chaine)
Entraîne : rien
******************************************/
int analyserType(char * pcCle);


/*****************************************
Extraction d'une sous chaine
******************************************
Entrée : un pointeur sur le début de la sous-chaîne,
Entrée : un pointeur sur la fin de la sous-chaîne.
Nécessite : pcStart >= pcEnd.
Sortie : la sous-chaîne souhaitée (de type char *).
Entraîne : Allocation dynamique d'un char * (malloc)
******************************************/
char * sousChaine(const char * pcStart, const char * pcEnd);


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
Entraîne : rien.
******************************************/
char * supprimerEspaces(char pcStr[]);

#endif;