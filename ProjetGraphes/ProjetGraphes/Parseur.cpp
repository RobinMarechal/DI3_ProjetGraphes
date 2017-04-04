#include "Parseur.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Cexception.h"
#include "TableauAssociatif.h"
#include "helpers.h"
#include "constantes.h"


using namespace std;


/*****************************************
Analyseur syntaxique.
******************************************
Entrée : le chemin du fichier.
Nécessite : rien.
Sortie : rien.
Entraîne : soulève une Cexception en cas d'erreur de syntaxe dans le fichier
******************************************/
void CParseur::PARanalyseSyntaxique(char * pcFichier)
{
	bool bBalise = false,
		bValeur = false,
		bEgal = false,
		bCrochetOuvrant = false,
		bCrochetFermant = false,
		bSucces = false;

	int iLigne = 0;

	ifstream IFSfichier(pcFichier);

	// pour chaque ligne...
	while (!IFSfichier.eof())
	{
		char pcLigne[256] = { 0 };
		char pcMsg[1024] = { 0 };
		unsigned int uiBoucle = 0;
		iLigne++;
		IFSfichier.getline(pcLigne, 256);

		// Préparation du message d'erreur au cas où
		sprintf_s(pcMsg, 1024, "Erreur syntaxique à la ligne %d du fichier : \n%s", iLigne, pcFichier);

		// ...on analyse chaque caractere
		while (pcLigne[uiBoucle] != '\n' && pcLigne[uiBoucle] != '\0')
		{
			char cChar = pcLigne[uiBoucle];

			// Les espaces/tabulations ne nous interessent pas
			if (cChar == ' ' || cChar == '\t')
			{
				uiBoucle++;
				continue;
			}


			if (cChar == '[')
				bCrochetOuvrant = true;
			else if (cChar == ']')
				bCrochetFermant = true;

			if (cChar == '=')
			{
				if (bEgal && !bCrochetOuvrant)
				{
					// Il y a 2 '=' ou plus sur cette ligne.
					strcat_s(pcMsg, 1024, "\n--> Deux '=' ou plus sur la même ligne.");
					throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
				}
				bEgal = true;
			}
			else if (!bEgal)
			{
				// On est avant le '=' => balise
				bBalise = true;
			}
			else
			{
				// On est après le '=' => valeur
				bValeur = true;
			}

			// Ce qu'il y a a l'interieur des crochets ne nous interesse pas
			if (bCrochetOuvrant && !bCrochetFermant)
			{
				uiBoucle++;
				continue;
			}

			uiBoucle++;
		}

		// Si la syntaxe n'est pas [BALISE]=[VALEUR], syntaxe invalide
		if (!bBalise || !bEgal || !bValeur)
		{
			strcat_s(pcMsg, 1024, ".");
			throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
		}

		// S'il y a un crochet fermant mais pas de crochet ouvrant, syntaxe invalide
		if (bCrochetFermant && !bCrochetOuvrant)
		{
			strcat_s(pcMsg, 1024, "\n-->, '[' manquant.");
			throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
		}

		// Si il n'y a pas de crochet, ou qu'il y a un ouvrant et un fermant, c'est bon
		if((bCrochetFermant && bCrochetOuvrant) || (!bCrochetOuvrant && !bCrochetFermant))
		{
			bBalise = false;
			bValeur = false;
			bEgal = false;
			bCrochetOuvrant = false;
			bCrochetFermant = false;
			bSucces = true;
		}
	}

	// S'il y a un crochet fermant mais pas de crochet ouvrant, syntaxe invalide
	if (!bCrochetFermant && bCrochetOuvrant)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Ereur syntaxique dans le fichier :\n%s\n-->Un crochet fermant semble manquer.", pcFichier);
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
	}

	// Si les crochets sont ouvert mais jamais fermés, syntaxe invalide
	if (bCrochetOuvrant && !bCrochetFermant && !bSucces)
	{
		char pcMsg[1024] = { 0 };
		iLigne++;

		sprintf_s(pcMsg, 1024, "Erreur syntaxique à la ligne %d du fichier :\n%s\n-->'[' trouvé mais aucun ']' trouvé plus loin.", iLigne, pcFichier);
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, pcMsg);
	}
}


/*****************************************
Extraire la partie gauche d'une ligne du fichier
******************************************
Entrée : la ligne du fichier à analyser
Nécessite : la ligne contient un (et un seul) '='.
Sortie : la partie gauche de la ligne.
Entraîne : rien.
******************************************/
char * CParseur::PARextraireBalise(char * pcLigne)
{
	char pcTmp[1024] = { 0 };
	char * pcEgal = NULL;
	
	strcpy_s(pcTmp, 1024, pcLigne);
	pcEgal = strchr(pcTmp, '=');

	// On revérifie au cas ou la méthode est appelée à un autre moment sans 
	// analyse syntaxique au préalable.
	if (pcEgal == NULL)
	{
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur syntaxique : une ligne du fichier ne contient pas de '='.");
	}

	pcTmp[pcEgal - pcTmp] = '\0';

	return supprimerEspaces(pcTmp);
}


/*****************************************
Extraire la partie droite d'une ligne du fichier
******************************************
Entrée : la ligne du fichier à analyser
Nécessite : la ligne contient un (et un seul) '='.
Sortie : la partie droite de la ligne.
Entraîne : rien.
******************************************/
char * CParseur::PARextraireValeur(char * pcLigne)
{
	char pcTmp[1024] = { 0 };
	char * pcEgal = NULL;
	char * pcFin = NULL;

	strcpy_s(pcTmp, 1024, pcLigne);
	pcEgal = strchr(pcTmp, '=');

	// On revérifie au cas ou la méthode est appelée à un autre moment sans 
	// analyse syntaxique au préalable.
	if (pcEgal == NULL)
	{
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur syntaxique : une ligne du fichier ne contient pas de '='.");
	}

	return supprimerEspaces(pcEgal + 1);
}



/*****************************************
Parse un fichier.
******************************************
Entrée : le chemin du fichier à parser.
Nécessite : rien.
Sortie : une instance de CTableauAssociatif contenant les données du fichier.
Entraîne : soulève une Cexception en cas d'erreur de syntaxe dans le fichier
******************************************/
CTableauAssociatif CParseur::PARparserFichier(char * pcFichier)
{   
	// INITIALISATIONS ////////////////////////////////////////////////////////
	
	CTableauAssociatif TABtab;

	// Souleve une exception si la syntaxe est incorrecte
	PARanalyseSyntaxique(pcFichier);

	ifstream fichier(pcFichier);

	// TRAITEMENT /////////////////////////////////////////////////////////////////

	// Pour chaque balise, on récupère la valeur sous forme de char * à traiter
	while(!fichier.eof())
	{
		char pcLigne[1024] = { 0 }, 
			pcBalise[1024] = { 0 },
			pcValeur[1024] = { 0 };

		fichier.getline(pcLigne, 1024);

		strcpy_s(pcBalise, 1024, PARextraireBalise(pcLigne));
		strcpy_s(pcValeur, 1024, PARextraireValeur(pcLigne));

		// On permet un peu de souplesse par rapport à la casse des valeurs
		// Ex : 'TypeMatrice=DOUble' => fonctionne
		transformerEnMinuscule(pcValeur);

		//ppcValeursBalises[uiBoucle][0] = '\0';
		if (*pcValeur == '[')
		{
			*pcValeur = '\0';
			fichier.getline(pcLigne, 1024);

			// Tant qu'on n'est pas a la fin du fichier
			while (strchr(pcLigne, ']') == NULL)
			{
				unsigned int uiNouvelleTaille = strlen(pcLigne) + strlen(pcValeur) + 1;

				strcat_s(pcValeur, uiNouvelleTaille, pcLigne);
				strcat_s(pcValeur, uiNouvelleTaille + 2, "\n");

				fichier.getline(pcLigne, 1024);
			}

			// On retire le dernier \n (si la chaine n'est pas vide)
			if(pcValeur[0] != 0)
				pcValeur[strlen(pcValeur) - 1] = '\0';

			TABtab.TABajouterChaine(pcBalise, _strdup(supprimerEspaces(pcValeur)));
		}
		else
		{
			TABtab.TABajouterAuto(pcBalise, pcValeur);
		}

	}

	return TABtab;
}