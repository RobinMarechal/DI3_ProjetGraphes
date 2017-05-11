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
Permet de g�rer des exceptions soulev�es
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
	Constructeur par d�faut.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet.
	*****************************************/
	Cexception();


	/*****************************************
	Constructeur de recopie.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet par copie de l'objet en param�tre.
	*****************************************/
	Cexception(Cexception &EXCexception);


	/*****************************************
	Constructeur � un argument.
	******************************************
	Entr�e : un code d'erreur
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet.
	*****************************************/
	Cexception(const unsigned int uiValeur);


	/*****************************************
	Constructeur � deux arguments.
	******************************************
	Entr�e : un code d'erreur
	Entr�e : un message d'erreur.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : l'initialisation de l'objet.
	******************************************/
	Cexception(const unsigned int uivaleur, char * pcMessage);


	/*****************************************
	Destructeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : rien.
	Entra�ne : Lib�ration de la m�moire allou�e pour pcEXCMessage.
	******************************************/
	~Cexception();


	/*****************************************
	Op�rateur =.
	******************************************
	Entr�e : instance de la classe Cexception � copier.
	N�cessite : rien.
	Sortie : l'objet recopi�.
	Entra�ne : la recopie de l'objet en param�tre.
	******************************************/
	Cexception & operator=(Cexception EXCexception);


	/*****************************************
	Accesseur pour uiEXCValeur.
	******************************************
	Entr�e : rien.
	N�cessite : rien.
	Sortie : le code d'erreur
	Entra�ne : rien.
	******************************************/
	unsigned int EXCgetValeur() const { return uiEXCValeur; }


	/*****************************************
	Accesseur pour pcEXCMessage.
	******************************************
	Entr�e : rien
	N�cessite : rien
	Sortie : un message d'erreur
	Entra�ne : rien
	******************************************/
	char * EXCgetMessage() const { return pcEXCMessage; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entr�e : un code d'erreur
	N�cessite : rien
	Sortie : rien
	Entra�ne : la modification du code d'erreur
	******************************************/
	void EXCsetValeur(unsigned int uiValeur) { uiEXCValeur = uiValeur; }


	/*****************************************
	Mutateur pour pcEXCMessage.
	******************************************
	Entr�e : un message d'erreur
	N�cessite : rien
	Sortie : rien
	Entra�ne : la modification du message d'erreur
	******************************************/
	void EXCsetMessage(char * pcMessage) { free(pcEXCMessage); pcEXCMessage = _strdup(pcMessage); }
};

#endif