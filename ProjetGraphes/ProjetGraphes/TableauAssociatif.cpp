#include "TableauAssociatif.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

#include "Cexception.h"
#include "constantes.h"


/********************************************************
Initialisation de l'objet
*********************************************************
Entrée : rien
Nécessite : rien
Sortie : rien
Entraîne : Définition de la valeur des attributs :
les pointeurs à NULL et le nombre d'élément à 0
*********************************************************/
void CTableauAssociatif::TABinit() 
{
	ppcTABcles = NULL;
	pvTABvaleurs = NULL;
	puiTypes = NULL;
	uiTABnbElements = 0;
}



/********************************************************
Pré-destruction de l'objet
*********************************************************
Entrée : rien
Nécessite : rien
Sortie : rien
Entraîne : Libération de la mémoire allouée pour les attributs
*********************************************************/
void CTableauAssociatif::TABdetruire() 
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiTABnbElements; uiBoucle++)
	{
		free(ppcTABcles[uiBoucle]);
		if(puiTypes[uiBoucle] == TAB_TYPE_CHAINE)
			free(pvTABvaleurs[uiBoucle].pcChaine);
	}

	free(ppcTABcles);
	free(pvTABvaleurs);
	free(puiTypes);
}


/********************************************************
Constructeur par défaut
*********************************************************
Entrée : rien
Nécessite : rien
Sortie : rien
Entraîne : Création de l'objet
*********************************************************/
CTableauAssociatif::CTableauAssociatif() 
{
	TABinit();
}


/********************************************************
Constructeur de recopie
*********************************************************
Entrée : l'instance de CTableauAssociatif à recopier
Nécessite : rien
Sortie : rien
Entraîne : Création de l'objet en recopiant TABobjet.
=> La recopie des tableau se fait en recopiant les valeurs,
et non l'adresse des pointeurs
*********************************************************/
CTableauAssociatif::CTableauAssociatif(const CTableauAssociatif & TABobjet) 
{
	unsigned int uiBoucle;
	TABinit();
	for (uiBoucle = 0; uiBoucle < TABobjet.uiTABnbElements; uiBoucle++)
	{
		if (TABobjet.puiTypes[uiBoucle] == TAB_TYPE_CHAINE)
		{
			TABajouterChaine(TABobjet.ppcTABcles[uiBoucle], _strdup(TABobjet.pvTABvaleurs[uiBoucle].pcChaine));
		}
		else
		{
			TABajouter(TABobjet.ppcTABcles[uiBoucle], TABobjet.pvTABvaleurs[uiBoucle], TABobjet.puiTypes[uiBoucle]);
		}
	}
}


/********************************************************
Destructeur
*********************************************************
Entrée : rien
Nécessite : rien
Sortie : rien
Entraîne : La destruction de l'objet et la libération
de la mémoire allouée pour les attributs
*********************************************************/
CTableauAssociatif::~CTableauAssociatif() 
{
	TABdetruire();
}


/********************************************************
Opérateur =
*********************************************************
Entrée : l'instance de CTableauAssociatif à affecter à l'objet
Nécessite : rien
Sortie : rien
Entraîne : La recopie des tableau en recopier les valeurs,
et non l'adresse des pointeurs
*********************************************************/
CTableauAssociatif & CTableauAssociatif::operator=(const CTableauAssociatif & TABobjet) 
{
	unsigned int uiBoucle;
	TABdetruire();
	TABinit();
	for (uiBoucle = 0; uiBoucle < TABobjet.uiTABnbElements; uiBoucle++)
	{
		if (TABobjet.puiTypes[uiBoucle] == TAB_TYPE_CHAINE)
		{
			TABajouterChaine(TABobjet.ppcTABcles[uiBoucle], _strdup(TABobjet.pvTABvaleurs[uiBoucle].pcChaine));
		}
		else
		{
			TABajouter(TABobjet.ppcTABcles[uiBoucle], TABobjet.pvTABvaleurs[uiBoucle], TABobjet.puiTypes[uiBoucle]);
		}
	}

	return *this;
}


/********************************************************
Supprimer un élément du tableau
*********************************************************
Entrée : la clé à retirer du tableau
Nécessite : L'objet possède la clé en attribut (Sinon la méthode ne fait rien)
Sortie : rien
Entraîne : Réduction de la mémoire allouée aux tableaux en attribut
Et suppression de la clé pcCle et de l'élément dans les autres tableaux
*********************************************************/
void CTableauAssociatif::TABsupprimer(const char * pcCle)
{
	unsigned int uiBoucle;
	unsigned int uiPos = TABgetIndiceCle(pcCle);

	// Si l'élément n'est pas dans le tableau, on ne fait rien
	if (uiPos == -1)
		return;

	// On free la clé
	free(ppcTABcles[uiPos]);

	// Si c'est une chaine qu'on supprime, on la free
	if (puiTypes[uiPos] == TAB_TYPE_CHAINE)
	{
		free(pvTABvaleurs[uiPos].pcChaine);
	}

	// On décale tout ce qui est à droite de uiPos d'une case vers la gauche
	for (uiBoucle = uiPos; uiBoucle < uiTABnbElements - 1; uiBoucle++)
	{
		ppcTABcles[uiBoucle] = ppcTABcles[uiBoucle + 1];
		pvTABvaleurs[uiBoucle] = pvTABvaleurs[uiBoucle + 1];
		puiTypes[uiBoucle] = puiTypes[uiBoucle + 1];
	}

	// On met le pointeur de la dernière case de ppcTABcles à NULL
	// Pas de fuite de mémoire car le pointeur a été copié dans l'avant dernière case
	ppcTABcles[uiTABnbElements - 1] = NULL;

	// Si le dernier élément du tableau est une chaine, on met le pointeur à null
	// On ne la free pas car on a coppié le pointeur dans l'avant dernière 'case'
	if (puiTypes[uiTABnbElements - 1] == TAB_TYPE_CHAINE)
	{
		pvTABvaleurs[uiTABnbElements - 1].pcChaine = NULL;
	}

	uiTABnbElements--;
	ppcTABcles = (char **)realloc(ppcTABcles, uiTABnbElements * sizeof(char *));
	pvTABvaleurs = (Valeur *)realloc(pvTABvaleurs, uiTABnbElements * sizeof(Valeur));
	puiTypes = (unsigned int *)realloc(puiTypes, sizeof(unsigned int) * uiTABnbElements);

	if (ppcTABcles == NULL || pvTABvaleurs == NULL || puiTypes == NULL)
	{
		std::cout << "TABsupprimer() : Une réallocation a échoué, le programme s'est arrêté." << std::endl;
		exit(EXIT_FAILURE);
	}

}



/********************************************************
Ajout d'un union au tableau associatif
*********************************************************
Entrée : la clé,
Entrée : l'union contenant la valeur,
Entrée : Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
Nécessite : rien
Sortie : rien
Entraîne : La réallocations des trois tableaux et l'insertion
des éléments dans les tableaux respectifs.
*********************************************************/
void CTableauAssociatif::TABajouter(const char * pcCle, Valeur vValeur, unsigned int uiType) 
{
	uiTABnbElements++;
	ppcTABcles = (char **)realloc(ppcTABcles, uiTABnbElements * sizeof(char*));
	pvTABvaleurs = (Valeur *)realloc(pvTABvaleurs, uiTABnbElements * sizeof(Valeur));
	puiTypes = (unsigned int *)realloc(puiTypes, uiTABnbElements * sizeof(unsigned int));

	if (ppcTABcles == NULL || pvTABvaleurs == NULL || puiTypes == NULL)
	{
		std::cout << "TABajouter() : Une réallocation a échoué, le programme s'est arrêté." << std::endl;
		exit(EXIT_FAILURE);
	}


	ppcTABcles[uiTABnbElements - 1] = _strdup(pcCle);
	pvTABvaleurs[uiTABnbElements - 1] = vValeur;
	puiTypes[uiTABnbElements - 1] = uiType;
}


/********************************************************
Ajouter un élément de type Réel
*********************************************************
Entrée : la clé de la valeur à ajouter
Entrée : la valeur de type Réel à ajouter
Nécessite : rien
Sortie : rien
Entraîne : Réallocation des tableaux en attribut
et ajout des éléments dans leur tableau respectif
*********************************************************/
void CTableauAssociatif::TABajouterEntier(const char * pcCle, int iVal) 
{
	Valeur vVal;
	vVal.iEntier = iVal;
	TABajouter(pcCle, vVal, TAB_TYPE_ENTIER);
}



/********************************************************
Ajouter un élément de type Réel
*********************************************************
Entrée : la clé de la valeur à ajouter
Entrée : la valeur de type Réel à ajouter
Nécessite : rien
Sortie : rien
Entraîne : Réallocation des tableaux en attribut
et ajout des éléments dans leur tableau respectif
*********************************************************/
void CTableauAssociatif::TABajouterReel(const char * pcCle, double dVal) 
{
	Valeur vVal;
	vVal.dReel = dVal;
	TABajouter(pcCle, vVal, TAB_TYPE_REEL);
}



/********************************************************
Ajouter un élément de type Chaine
*********************************************************
Entrée : la clé de la valeur à ajouter
Entrée : la valeur de type Chaine à ajouter
Nécessite : pcVal a été allouée sur le tas.
Sortie : rien
Entraîne : Réallocation des tableaux en attribut
et ajout des éléments dans leur tableau respectif
*********************************************************/
void CTableauAssociatif::TABajouterChaine(const char * pcCle, char * pcVal) 
{
	Valeur vVal;
	vVal.pcChaine = pcVal;
	TABajouter(pcCle, vVal, TAB_TYPE_CHAINE);
}



/********************************************************
Ajouter un élément sans spécifier le type
*********************************************************
Entrée : la clé de la valeur à ajouter
Entrée : la valeur à ajouter sous faire d'une chaine de caractère
Nécessite : rien
Sortie : rien
Entraîne : Déduction du type potentiel de pcVal grâce à un automate,
et l'ajoute au tableau avec le bon type
Exemples : "1.12" => Reel, "5" => Entier, "a12" => Chaine
Exemples : "7." => Entier, ".27" => Reel, "" => Chaine
*********************************************************/
void CTableauAssociatif::TABajouterAuto(const char * pcCle, char * pcVal)
{
	// Format : XX
	int iType = analyserType(pcVal);
	if (iType == TAB_TYPE_ENTIER)
	{
		// On parse la chaine en int
		int iVal = atoi(pcVal);

		// on l'ajoute au tableau
		TABajouterEntier(pcCle, iVal);
	}
	// Format : XX.XX || XX,XX
	else if(iType == TAB_TYPE_REEL)
	{
		// On rajoute un 0 au début et à la fin pour etre sur d'éviter les problèmes pour convertir
		unsigned int uiBoucle;
		unsigned int iTaille = strlen(pcVal);
		char * pcStr = new char[iTaille + 3];

		for (uiBoucle = 0; uiBoucle < iTaille + 2; uiBoucle++)
		{
			pcStr[uiBoucle] = '0';
		}
		pcStr[iTaille + 2] = '\0';

		strcpy_s(pcStr + 1, strlen(pcVal)+1, pcVal);
		*strchr(pcStr, '\0') = '0';

		// On remplace ',' par '.' s'il faut
		if (strchr(pcStr, ',') != NULL)
			pcStr[strchr(pcStr, ',') - pcStr] = '.';

		// On parse la chaine en double;
		double dVal = atof(pcStr);
		// on l'ajoute au tableau
		TABajouterReel(pcCle, dVal);

		delete[] pcStr;
	}
	else
	{
		// on ajoute simplement la chaine
		TABajouterChaine(pcCle, _strdup(pcVal));
	}
}



/********************************************************
Lecture du nombre d'élements du tableau
*********************************************************
Entrée : rien
Nécessite : rien
Sortie : le nombre d'élements du tableau associatif
Entraîne : rien
*********************************************************/
unsigned int CTableauAssociatif::TABgetNbElements() const 
{
	return uiTABnbElements;
}



/********************************************************
Lecture du nombre d'élements du tableau
*********************************************************
Entrée : rien
Nécessite : rien
Sortie : La position de la clé.
>= 0 : La clé est dans le tableau,
== -1 : La clé n'est pas dans le tableau.
Entraîne : rien
*********************************************************/
int CTableauAssociatif::TABgetIndiceCle(const char * pcCle) const 
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiTABnbElements; uiBoucle++)
	{
		if (strcmp(ppcTABcles[uiBoucle], pcCle) == 0)
		{
			return uiBoucle;
		}
	}

	return -1;
}



/********************************************************
Lecture de la clé à une position
*********************************************************
Entrée : la position dans le tableau
Nécessite : rien.
Sortie : un pointeur sur la clé, ou NULL si aucune clé ne correspond à uiPos
Entraîne : rien
Attention ! Une modification de la chaine retournée par la
méthode entrainerait la modification de l'élement dans
le tableaux des clés, il ne s'agit pas d'une copie.
*********************************************************/
char * CTableauAssociatif::TABgetCle(unsigned int uiPos) const 
{
	if (uiPos < 0 || uiPos >= uiTABnbElements)
		return NULL;

	return ppcTABcles[uiPos];
}



/********************************************************
Lecture de l'union Valeur associé à une clé
*********************************************************
Entrée : la clé
Nécessite : pcCle est dans le tableau des clés
Sortie : un union Valeur
Entraîne : rien
*********************************************************/
Valeur CTableauAssociatif::TABgetValeur(const char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos];
}



/********************************************************
Lecture de l'union Valeur à une position
*********************************************************
Entrée : la position
Nécessite : 0 <= uiPos < Nombre d'éléments
Sortie : un union Valeur
Entraîne : rien
*********************************************************/
Valeur CTableauAssociatif::TABgetValeurPos(unsigned int uiPos) const
{
	return pvTABvaleurs[uiPos];
}



/********************************************************
Lecture du type de la valeur à une position
*********************************************************
Entrée : la position
Nécessite : 0 <= uiPos < Nombre d'éléments
Sortie: Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
Entraîne : rien
*********************************************************/
unsigned int CTableauAssociatif::TABgetValeurType(unsigned int uiPos) const
{
	return puiTypes[uiPos];
}



/********************************************************
Lecture du type de la valeur associée à une clé
*********************************************************
Entrée : la clé
Nécessite : pcCle est dans le tableau des clés
Sortie : Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
Entraîne : rien
*********************************************************/
unsigned int CTableauAssociatif::TABgetValeurType(const char * pcCle) const
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return TABgetValeurType(uiPos);
}



/********************************************************
Lecture de la valeur au type Entier
*********************************************************
Entrée : la clé
Nécessite : pcCle est dans le tableau des clés
Nécessite : La valeur a été stockée en tant qu'Entier
Sortie : La valeur de type Entier de l'union Valeur associé à la clé.
Entraîne : rien
Attention ! Si la valeur n'a pas été stockée en tant qu'Entier,
La valeur sera faussée.
*********************************************************/
int CTableauAssociatif::TABgetValeurEntier(const char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);

	if (puiTypes[uiPos] == TAB_TYPE_REEL)
	{
		return (int) pvTABvaleurs[uiPos].dReel;
	}
	else
	{
		return pvTABvaleurs[uiPos].iEntier;
	}
}



/********************************************************
Lecture de la valeur au type Reel
*********************************************************
Entrée : la clé
Nécessite : pcCle est dans le tableau des clés
Nécessite : La valeur a été stockée en tant qu'Reel
Sortie : La valeur de type Reel de l'union Valeur associé à la clé.
Entraîne : rien
Attention ! Si la valeur a été stockée en tant que Chaine,
la valeur sera faussée.
*********************************************************/
double CTableauAssociatif::TABgetValeurReel(const char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);

	if (puiTypes[uiPos] == TAB_TYPE_ENTIER)
	{
		return (double) pvTABvaleurs[uiPos].iEntier;
	}
	else
	{
		return pvTABvaleurs[uiPos].dReel;
	}
}



/********************************************************
Lecture de la valeur au type Chaine
*********************************************************
Entrée : la clé
Nécessite : pcCle est dans le tableau des clés
Nécessite : La valeur a été stockée en tant qu'Entier
Sortie : La valeur de type Entier de l'union Valeur associé à la clé.
Entraîne : rien
Attention ! Si la valeur n'a pas été stockée en tant qu'Entier,
La valeur sera faussée.
*********************************************************/
char * CTableauAssociatif::TABgetValeurChaine(const char * pcCle) const 
{
	unsigned int uiPos = TABgetIndiceCle(pcCle);
	return pvTABvaleurs[uiPos].pcChaine;
}
