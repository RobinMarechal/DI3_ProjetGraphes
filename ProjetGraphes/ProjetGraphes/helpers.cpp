#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>


/*****************************************
Retourne le type correspondant � la chaine en param�tre
******************************************
Entr�e : la chaine � analyser
N�cessite : rien
Sortie : l'entier correspondant au type de la chaine
=> TYPE_ENTIER, TYPE_REEL ou TYPE_CHAINE
Entra�ne : rien
******************************************/
int analyserType(char * pcVal)
{
	int iEtat = 0;
	int iType = TYPE_CHAINE;
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
			else { iType = TYPE_ENTIER; bStop = true; }
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
			else if (cChar == '\0') { iType = TYPE_ENTIER; bStop = true; }
			else { iType = TYPE_CHAINE; bStop = true; }
			break;

		case 4:
			if (cChar >= '0' && cChar <= '9') iEtat = 5;
			else if (cChar == '\0') { iType = TYPE_ENTIER; bStop = true; } // Car "7." => 7 avec atof()
			else iEtat = -1;
			break;

		case 5:
			if (cChar == 'e' || cChar == 'E') iEtat = 6;
			else if (cChar >= '0' && cChar <= '9') iEtat = 5;
			else { iType = TYPE_REEL; bStop = true; }
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
			else { iType = TYPE_REEL; bStop = true; }
			break;

		case -1:
			iType = TYPE_CHAINE;
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
Entr�e : un pointeur sur le d�but de la sous-cha�ne,
Entr�e : un pointeur sur la fin de la sous-cha�ne.
N�cessite : pcDebut >= pcFin.
Sortie : la sous-cha�ne souhait�e.
Entra�ne : Allocation dynamique d'un char * (via new)
******************************************/
char * sousChaine(const char * pcDebut, const char * pcFin) {
	unsigned int uiBoucle = 0;
	char * pcStr = new char[pcFin - pcDebut + 1];
	while (pcDebut + uiBoucle != pcFin && pcDebut[uiBoucle] != '\0')
	{
		pcStr[uiBoucle] = pcDebut[uiBoucle];
		uiBoucle++;
	}
	pcStr[uiBoucle] = '\0';

	return pcStr;
}


/*****************************************
transformation d'une chaine de carat�res en minuscule.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : rien.
Entra�ne : Modification de la chaine point�e par pcStr
-> tous les caract�res sont en minuscule.
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
Suppression des espaces en d�but et fin de chaine.
******************************************
Entr�e : une cha�ne de caract�res.
N�cessite : rien.
Sortie : Une copie de la chaine de caract�re sans les espaces de d�but et de fin.
Entra�ne : L'allocation sur le tas d'un char* (via new).
******************************************/
char * supprimerEspaces(char pcStr[])
{
	if (strlen(pcStr) == 0 || *pcStr == '\n')
		return "";

	char * pcResultat = new char[1024];
	char * pcTmp = strchr(pcStr, '\0') - 1;
	// On suprime les espaces avant le d�but du mot
	while (*pcStr == ' ' || *pcStr == '\t')
		pcStr++;

	// On supprime les espaces apr�s la fin du mot
	while (*pcTmp == ' ' || *pcTmp == '\t')
		pcTmp--;

	strncpy_s(pcResultat, 1024, pcStr, pcTmp - pcStr + 1);

	return pcResultat;
}




/*****************************************
Affichage d'un message d'erreur dans la console
******************************************
Entr�e : le message � afficher
Entr�e : true : arr�ter le programme, false sinon
N�cessite : rien
Entra�ne : L'affichage d'un message en rouge dans la console
Entra�ne : L'arr�t du programme si la valeur de bStop est true
******************************************/
void erreur(char * pcMsg, bool bStop)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// 12 = rouge

	SetConsoleTextAttribute(hConsole, 12);
	std::cout << pcMsg << std::endl;
	// 7 = couleur de base
	SetConsoleTextAttribute(hConsole, 7);

	if (bStop)
	{
		exit(EXIT_FAILURE);
	}
}
