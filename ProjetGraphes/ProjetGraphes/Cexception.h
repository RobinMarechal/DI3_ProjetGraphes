#ifndef CEXCEPTION_H

#define CEXCEPTION_H

#include <string.h>
#include <stdlib.h>
#include "helpers.h"


/*******************************************
Codes d'exceptions
********************************************/
#define EXC_ERREUR_SYNTAXIQUE 0
#define EXC_ECHEC_ALLOCATION 1
#define EXC_ACCES_MEMOIRE 2
#define EXC_SOMMET_UNIQUE 3
#define EXC_SOMMET_HORS_GRAPHE 4
#define EXC_SOMMET_INEXISTANT 5
#define EXC_ERREUR_LEXICALE 6
#define EXC_FICHIER_INTROUVABLE 7
#define EXC_ECHEC_TRANSFORMATION_TYPE 8



/*************************************
Classe de gestion d'exceptions
**************************************
Permet de gérer des exceptions soulevées
dans le programme, avec un code d'erreur
et un message d'erreur particulier.
**************************************/
class Cexception
{
private:

	unsigned int uiEXCValeur; // Code d'erreur
	char * pcEXCMessage; // Message d'erreur

public:

	/*****************************************
	Constructeur par défaut.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet.
	*****************************************/
	Cexception();


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet par copie de l'objet en paramètre.
	*****************************************/
	Cexception(Cexception &EXCexception);


	/*****************************************
	Constructeur à un argument.
	******************************************
	Entrée : un code d'erreur
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet.
	*****************************************/
	Cexception(const unsigned int uiValeur);


	/*****************************************
	Constructeur à deux arguments.
	******************************************
	Entrée : un code d'erreur
	Entrée : un message d'erreur.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : l'initialisation de l'objet.
	******************************************/
	Cexception(const unsigned int uivaleur, char * pcMessage);


	/*****************************************
	Destructeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : rien.
	Entraîne : Libération de la mémoire allouée pour pcEXCMessage.
	******************************************/
	~Cexception();


	/*****************************************
	Opérateur =.
	******************************************
	Entrée : instance de la classe Cexception à copier.
	Nécessite : rien.
	Sortie : l'objet recopié.
	Entraîne : la recopie de l'objet en paramètre.
	******************************************/
	Cexception & operator=(Cexception EXCexception);


	/*****************************************
	Accesseur pour uiEXCValeur.
	******************************************
	Entrée : rien.
	Nécessite : rien.
	Sortie : le code d'erreur
	Entraîne : rien.
	******************************************/
	unsigned int EXCgetValeur() const { return uiEXCValeur; }


	/*****************************************
	Accesseur pour pcEXCMessage.
	******************************************
	Entrée : rien
	Nécessite : rien
	Sortie : un message d'erreur
	Entraîne : rien
	******************************************/
	char * EXCgetMessage() const { return pcEXCMessage; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entrée : un code d'erreur
	Nécessite : rien
	Sortie : rien
	Entraîne : la modification du code d'erreur
	******************************************/
	void EXCsetValeur(unsigned int uiValeur) { uiEXCValeur = uiValeur; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entrée : un message d'erreur
	Nécessite : rien
	Sortie : rien
	Entraîne : la modification du message d'erreur
	******************************************/
	void EXCsetMessage(char * pcMessage) { free(pcEXCMessage); pcEXCMessage = _strdup(pcMessage); }
};

#endif