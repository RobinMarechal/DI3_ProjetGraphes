#include "Cexception.h"

#include <string.h>
#include <stdlib.h>
#include "helpers.h"



/*****************************************
Constructeur par défaut.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'initialisation de l'objet.
*****************************************/
Cexception::Cexception()
{
	uiEXCValeur = 0;
	pcEXCMessage = _strdup("Exception !");
}


/*****************************************
Constructeur de recopie.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'initialisation de l'objet par copie de l'objet en paramètre.
*****************************************/
Cexception::Cexception(Cexception &EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);
}


/*****************************************
Constructeur à un argument.
******************************************
Entrée : un code d'erreur
Nécessite : rien.
Sortie : rien.
Entraîne : l'initialisation de l'objet.
*****************************************/
Cexception::Cexception(const unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup("Exception !");
}



/*****************************************
Constructeur à deux arguments.
******************************************
Entrée : un code d'erreur
Entrée : un message d'erreur.
Nécessite : rien.
Sortie : rien.
Entraîne : l'initialisation de l'objet.
******************************************/
Cexception::Cexception(const unsigned int uiValeur, char * pcMessage)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup(pcMessage);
}


/*****************************************
Destructeur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : Libération de la mémoire allouée pour pcEXCMessage.
******************************************/
Cexception::~Cexception()
{
	free(pcEXCMessage);
}


/*****************************************
Opérateur =.
******************************************
Entrée : instance de la classe Cexception à copier.
Nécessite : rien.
Sortie : l'objet recopié.
Entraîne : la recopie de l'objet en paramètre.
******************************************/
Cexception & Cexception::operator=(Cexception EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);

	return *this; 
}
