#ifndef TABLEAU_ASSOCIATIF_H
#define TABLEAU_ASSOCIATIF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cexception.h"
#include "helpers.h"
#include "constantes.h"

/**************************************************
Union permettant de stocker une valeur dans le 
tableau associatif en tant que reel, entier ou chaine.
***************************************************/
typedef union {
	double dReel;
	int iEntier;
	char * pcChaine;
} Valeur;

/**************************************************
Gestion de tableaux associatifs
***************************************************
Classe permettant de créer et de manipuler des 
tableaux associatifs Clé => Valeur 
Les valeurs peuvent être de type Entier, Réél ou
Chaine grâce à l'utilisation d'unions.
***************************************************/
class CTableauAssociatif
{
	/********************************************************
		Tableau contenant les clés
	*********************************************************/
	char ** ppcTABcles;

	/********************************************************
		Tableau des unions 'Valeur' associés au clés
	*********************************************************/
	Valeur * pvTABvaleurs;

	/********************************************************
		Le nombre d'élement du tableau
	*********************************************************/
	unsigned int uiTABnbElements;
	
	/********************************************************
		Tableau contenant le type de chaque valeur 
		pour faciliter l'utilisation de l'union 'Valeur'
	*********************************************************/
	unsigned int * puiTypes;


	/********************************************************
	Initialisation de l'objet
	*********************************************************
	Entrée : rien
	Nécessite : rien
	Sortie : rien
	Entraîne : Définition de la valeur des attributs : 
	les pointeurs à NULL et le nombre d'élément à 0
	*********************************************************/
	void TABinit();


	/********************************************************
	Pré-destruction de l'objet
	*********************************************************
	Entrée : rien
	Nécessite : rien
	Sortie : rien
	Entraîne : Libération de la mémoire allouée pour les attributs
	*********************************************************/
	void TABdetruire();


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
	void TABajouter( const char * pcCle, Valeur vValeur, unsigned int uiType);


public:


	/********************************************************
	Constructeur par défaut
	*********************************************************
	Entrée : rien
	Nécessite : rien
	Sortie : rien
	Entraîne : Création de l'objet
	*********************************************************/
	CTableauAssociatif();


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
	CTableauAssociatif(const CTableauAssociatif & TABobjet);


	/********************************************************
	Destructeur
	*********************************************************
	Entrée : rien
	Nécessite : rien
	Sortie : rien
	Entraîne : La destruction de l'objet et la libération
	de la mémoire allouée pour les attributs
	*********************************************************/
	~CTableauAssociatif();


	/********************************************************
	Opérateur =
	*********************************************************
	Entrée : l'instance de CTableauAssociatif à affecter à l'objet
	Nécessite : rien
	Sortie : rien
	Entraîne : La recopie des tableau en recopier les valeurs, 
	et non l'adresse des pointeurs
	*********************************************************/
	CTableauAssociatif & operator=(const CTableauAssociatif & TABobjet);


	/********************************************************
	Supprimer un élément du tableau
	*********************************************************
	Entrée : la clé à retirer du tableau
	Nécessite : L'objet possède la clé en attribut (Sinon la méthode ne fait rien)
	Sortie : rien
	Entraîne : Réduction de la mémoire allouée aux tableaux en attribut
	Et suppression de la clé pcCle et de l'élément dans les autres tableaux
	*********************************************************/
	void TABsupprimer(const char * pcCle);


	/********************************************************
	Ajouter un élément de type Entier
	*********************************************************
	Entrée : la clé de la valeur à ajouter
	Entrée : la valeur de type Entier à ajouter
	Nécessite : rien
	Sortie : rien
	Entraîne : Réallocation des tableaux en attribut
			et ajout des éléments dans leur tableau respectif
	*********************************************************/
	void TABajouterEntier(const char * pcCle, int iVal);



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
	void TABajouterReel( const char * pcCle, double dVal);



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
	void TABajouterChaine( const char * pcCle, char * pcVal);



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
	void TABajouterAuto( const char * pcCle, char * pcVal);



	/********************************************************
	Lecture du nombre d'élements du tableau
	*********************************************************
	Entrée : rien
	Nécessite : rien
	Sortie : le nombre d'élements du tableau associatif
	Entraîne : rien
	*********************************************************/
	unsigned int TABgetNbElements() const;



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
	int TABgetIndiceCle( const char * pcCle) const;



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
	char * TABgetCle(unsigned int uiPos) const;



	/********************************************************
	Lecture de l'union Valeur associé à une clé
	*********************************************************
	Entrée : la clé
	Nécessite : pcCle est dans le tableau des clés
	Sortie : un union Valeur
	Entraîne : rien
	*********************************************************/
	Valeur TABgetValeur( const char * pcCle) const;



	/********************************************************
	Lecture de l'union Valeur à une position
	*********************************************************
	Entrée : la position
	Nécessite : 0 <= uiPos < Nombre d'éléments
	Sortie : un union Valeur
	Entraîne : rien
	*********************************************************/
	Valeur TABgetValeurPos(unsigned int uiPos) const;



	/********************************************************
	Lecture du type de la valeur à une position
	*********************************************************
	Entrée : la position
	Nécessite : 0 <= uiPos < Nombre d'éléments
	Sortie: Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
	Entraîne : rien
	*********************************************************/
	unsigned int TABgetValeurType(unsigned int uiPos) const;



	/********************************************************
	Lecture du type de la valeur associée à une clé
	*********************************************************
	Entrée : la clé
	Nécessite : pcCle est dans le tableau des clés
	Sortie : Le type de la valeur (TAB_TYPE_CHAINE, TAB_TYPE_REEL, ou TAB_TYPE_ENTIER)
	Entraîne : rien
	*********************************************************/
	unsigned int TABgetValeurType( const char * pcCle) const;




	/********************************************************
	Lecture de la valeur au type Entier
	*********************************************************
	Entrée : la clé
	Nécessite : pcCle est dans le tableau des clés
	Nécessite : La valeur a été stockée en tant qu'Entier
	Sortie : La valeur de type Entier de l'union Valeur associé à la clé.
	Entraîne : rien
	Attention ! Si la valeur a été stockée en tant qu'Entier,
	la valeur sera tronquée.
	Attention ! Si la valeur a été stockée en tant que Chaine,
	la valeur sera faussée.
	*********************************************************/
	int TABgetValeurEntier( const char * pcCle) const;




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
	double TABgetValeurReel( const char * pcCle) const;




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
	char * TABgetValeurChaine( const char * pcCle) const;


};

#endif