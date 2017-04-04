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
Entraîne : (0 = entier) || (1 = réel) || (3 = chaine)
******************************************/
int analyserType(char * pcVal)
{
	int iEtat = 0;
	int iType = TAB_TYPE_CHAINE;
	bool bStop = false;
	while (!bStop)
	{
		char cChar = *pcVal;
		switch (iEtat)
		{
		case 0:
			if (cChar == '0') iEtat = 1;
			else if (cChar == '-') iEtat = 2;
			else if (cChar >= '1' && cChar <= '9') iEtat = 3;
			else if (cChar == '.') iEtat = 4; // car ".7" ==> 0.7 avec atof()
			else iEtat = -1;
			break;

		case 1:
			if (cChar == '.') iEtat = 4;
			else if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else { iType = TAB_TYPE_ENTIER; bStop = true; }
			break;

		case 2:
			if (cChar == '0') iEtat = 1;
			else if (cChar >= '1' && cChar <= '9') iEtat = 3;
			else iEtat = -1;
			break;

		case 3:
			if (cChar == '.') iEtat = 4;
			else if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else if (cChar >= '0' && cChar <= '9') iEtat = 3;
			else if (cChar == '\0') { iType = TAB_TYPE_ENTIER; bStop = true; }
			else { iType = TAB_TYPE_CHAINE; bStop = true; }
			break;

		case 4:
			if (cChar >= '0' && cChar <= '9') iEtat = 5;
			else if (cChar == '\0') { iType = TAB_TYPE_ENTIER; bStop = true; } // Car "7." => 7 avec atof()
			else iEtat = -1;
			break;

		case 5:
			if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else if (cChar >= '0' && cChar <= '9') iEtat = 5;
			else { iType = TAB_TYPE_REEL; bStop = true; }
			break;

		case 6:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else if (cChar == '+' || cChar == '-') iEtat = 7;
			else iEtat = -1;
			break;

		case 7:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else iEtat = -1;
			break;

		case 8:
			if (cChar >= '0' && cChar <= '9') iEtat = 8;
			else { iType = TAB_TYPE_REEL; bStop = true; }
			break;

		case -1:
			iType = TAB_TYPE_CHAINE;
			bStop = true;
			break;
		}
		pcVal++;
	}

	return iType;
}


/*****************************************
Extraction d'une sous chaine
******************************************
Entrée : un pointeur sur le début de la sous-chaîne,
Entrée : un pointeur sur la fin de la sous-chaîne.
Nécessite : pcStart >= pcEnd.
Sortie : la sous-chaîne souhaitée (de type char *).
Entraîne : Allocation dynamique d'un char * (malloc)
******************************************/
char * sousChaine(const char * pcStart, const char * pcEnd) {
	unsigned int uiBoucle = 0;
	char * pcStr = (char *)malloc(sizeof(char) * (size_t)(pcEnd - pcStart + 1));
	while (pcStart + uiBoucle != pcEnd && pcStart[uiBoucle] != '\0')
	{
		pcStr[uiBoucle] = pcStart[uiBoucle];
		uiBoucle++;
	}
	pcStr[uiBoucle] = '\0';

	return pcStr;
}


/*****************************************
transformation d'une chaine de caratères en minuscule.
******************************************
Entrée : une chaîne de caractères.
Nécessite : rien.
Sortie : rien.
Entraîne : Modification de la chaine pointée par pcStr
-> tous les caractères sont en minuscule.
******************************************/
void transformerEnMinuscule(char * pcStr)
{
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < strlen(pcStr); uiBoucle++)
	{
		pcStr[uiBoucle] = tolower(pcStr[uiBoucle]);
	}
}


/*****************************************
Suppression des espaces en début et fin de chaine.
******************************************
Entrée : une chaîne de caractères.
Nécessite : rien.
Sortie : Une copie de la chaine de caractère sans les espaces de début et de fin.
Entraîne : rien.
******************************************/
char * supprimerEspaces(char pcStr[])
{
	if (strlen(pcStr) == 0)
		return "";

	char pcResultat[1024] = { 0 };
	char * pcTmp = strchr(pcStr, '\0') - 1;
	// On suprime les espaces avant le début du mot
	while (isspace(*pcStr))
		pcStr++;

	// On supprime les espaces après la fin du mot
	while (isspace(*pcTmp))
		pcTmp--;

	strncpy_s(pcResultat, 1024 , pcStr, pcTmp - pcStr + 1);

	return pcResultat;
}

