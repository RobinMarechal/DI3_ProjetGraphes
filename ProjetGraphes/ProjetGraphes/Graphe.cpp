#include "Graphe.h"

#include <iostream>
#include "Cexception.h"
#include "Sommet.h"
#include "helpers.h"
#include "TableauAssociatif.h"
#include "Parseur.h"

using namespace std;

/*****************************************
Constructeur à un argument.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : la création d'un graphe contenant le nombre de sommets indiqués.
******************************************/
CGraphe::CGraphe()
{
    GRAinit();
}


/*****************************************
Constructeur de recopie.
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : rien.
Entraîne : la création d'une copie du graphe passé en paramètre.
******************************************/
CGraphe::CGraphe(const CGraphe & GRAobjet)
{
	GRArecopierGraphe(GRAobjet);
}


/*****************************************
Destructeur.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : la désallocation de la mémoire allouée et destruction de l'objet.
******************************************/
CGraphe::~CGraphe()
{
    GRAdetruire();
}


/*****************************************
Initialisation d'un graphe.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'initialisation du graphe.
******************************************/
void CGraphe::GRAinit()
{
	uiGRAnbSommets = 0;
	uiGRAtailleTableau = 0;
	ppSOMGRAsommets = nullptr;
	puiGRApositionsSommets = nullptr;
}


/*****************************************
Destruction d'un graphe.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : la destruction du graphe.
******************************************/
void CGraphe::GRAdetruire()
{
	unsigned int uiBoucle;

	for (uiBoucle = 1; uiBoucle <= uiGRAnbSommets; uiBoucle++)
	{
		CSommet * pSOMsommet = ppSOMGRAsommets[uiBoucle];
		if (pSOMsommet != nullptr)
		{
			delete pSOMsommet;
		}
	}

	free(ppSOMGRAsommets);
	delete[] puiGRApositionsSommets;
	ppSOMGRAsommets = nullptr;
	puiGRApositionsSommets = nullptr;
}


/*****************************************
Recopie d'un graphe.
******************************************
Entrée : une instance de CGraphe
Nécessite : rien.
Sortie : rien.
Entraîne : la recopie du graphe passé en paramètre.
******************************************/
void CGraphe::GRArecopierGraphe(const CGraphe & GRAobjet)
{
	unsigned int uiBoucle;
	unsigned int uiNbSommets = GRAobjet.GRAgetNbSommets();

	GRAinit();

	for (uiBoucle = 1; uiBoucle <= uiNbSommets; uiBoucle++)
	{
		GRAcreerSommet(GRAobjet.ppSOMGRAsommets[uiBoucle]->SOMgetNumero());
	}

	// RECOPIER LES ARCS...

	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		unsigned int uiNbSuccesseurs, uiBoucleSuccesseurs;
		CSommet * pSOMsommet = GRAgetSommetPosition(uiBoucle);
		CSommet * pSOMsommetObj = GRAobjet.GRAgetSommetPosition(uiBoucle);

		uiNbSuccesseurs = pSOMsommetObj->SOMgetNbSuccesseurs();

		for (uiBoucleSuccesseurs = 0; uiBoucleSuccesseurs < uiNbSuccesseurs; uiBoucleSuccesseurs++)
		{
			unsigned int uiNumSucc = pSOMsommetObj->SOMgetSuccesseur(uiBoucleSuccesseurs)->SOMgetNumero();
			pSOMsommet->SOMajouterSuccesseur(GRAgetSommetNumero(uiNumSucc));
		}
	}
}


/*****************************************
Surcharge de l'opérateur =.
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : une instance de CGraphe.
Entraîne : l'affectation du graphe passé en paramètre.
******************************************/
CGraphe & CGraphe::operator=(const CGraphe & GRAobjet)
{
	GRAdetruire();

	GRArecopierGraphe(GRAobjet);

	return *this;
}


/*****************************************
Surcharge de l'opérateur ==
Compare deux graphes, y compris les sommets et les arcs
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les graphes sont identiques)
			ou (false : les graphes sont différents).
******************************************/
bool CGraphe::operator==(const CGraphe & GRAobjet) const
{
	unsigned int uiBoucle = 0;

	if (uiGRAnbSommets != GRAobjet.uiGRAnbSommets)
	{
		return false;
	}

	// ---> les deux graphes ont le même nombre de sommets

	// Pour chaque sommet de this, on regarde s'il y a un sommet équivalent dans l'autre graphe
	for (uiBoucle = 1; uiBoucle <= uiGRAnbSommets; uiBoucle++)
	{
		CSommet * pSOMtmp = ppSOMGRAsommets[uiBoucle];
		unsigned int uiNumero = pSOMtmp->SOMgetNumero();

		if (GRAobjet.puiGRApositionsSommets[uiNumero] == GRA_AUCUN_SOMMET)
		{
			// ce sommet n'est pas dans l'autre graphe
			return false;
		}

		// ---> On a trouvé un sommet équivalent dans l'autre graphes
	}

	// Comparaison des arcs

	for (uiBoucle = 1; uiBoucle <= uiGRAnbSommets; uiBoucle++)
	{
		unsigned int uiBoucleArcs,
			uiNbSucc,
			uiNbPred,
			*puiThisSuccNumeros,
			*puiObjSuccNumeros;

		CSommet *pSOMthisSommet, *pSOMobjSommet;


		pSOMthisSommet = GRAgetSommetPosition(0);
		pSOMobjSommet = GRAobjet.GRAgetSommetPosition(pSOMthisSommet->SOMgetNumero());

		uiNbSucc = pSOMthisSommet->SOMgetNbSuccesseurs();
		uiNbPred = pSOMthisSommet->SOMgetNbPredecesseurs();

		// Si les deux sommets équivalents n'ont pas le même nombre de successeurs et de predecesseurs, les graphes ne sont pas egaux
		if (uiNbSucc != pSOMobjSommet->SOMgetNbSuccesseurs()
			|| uiNbPred != pSOMobjSommet->SOMgetNbPredecesseurs())
		{
			return false;
		}

		// Comparer les successeurs suffit pour comparer les arcs

		puiThisSuccNumeros = (unsigned int *) malloc(sizeof(unsigned int) * uiNbSucc);
		puiObjSuccNumeros = (unsigned int *) malloc(sizeof(unsigned int) * uiNbSucc);

		for (uiBoucleArcs = 0; uiBoucleArcs < uiNbSucc; uiBoucleArcs++)
		{
			puiThisSuccNumeros[uiBoucleArcs] = pSOMthisSommet->SOMgetSuccesseur(uiBoucleArcs)->SOMgetNumero();
			puiObjSuccNumeros[uiBoucleArcs] = pSOMobjSommet->SOMgetSuccesseur(uiBoucleArcs)->SOMgetNumero();
		}

		if (!tableauxSontEquivalents<unsigned int>(puiThisSuccNumeros, puiObjSuccNumeros, uiNbSucc))
		{
			return false;
		}

		free(puiThisSuccNumeros);
		free(puiObjSuccNumeros);
	}

	return true;
}


/*****************************************
Surcharge de l'opérateur !=.
Compare deux graphes, y compris les sommets et les arcs
******************************************
Entrée : une instance de CGraphe.
Nécessite : rien.
Sortie : un booléen.
Entraîne : (true : les graphes sont différents)
			ou (false : les graphes sont identiques).
******************************************/
bool CGraphe::operator!=(const CGraphe & GRAobjet) const
{
	return !operator==(GRAobjet);
}


/*****************************************
Création d'un sommet.
******************************************
Entrée : le numéro du sommet.
Nécessite : rien.
Sortie : un pointeur sur une instance de CSommet ou nullptr en cas d'echec.
Entraîne : la création d'un sommet ou message d'erreur dans la console.
******************************************/
CSommet * CGraphe::GRAcreerSommet(unsigned int uiNumero)
{
	CSommet * pSOMsommet = nullptr;

	try 
	{
		pSOMsommet = new CSommet(this, uiNumero);
	}
	catch (Cexception EXCe)
	{
		delete pSOMsommet;
		pSOMsommet = nullptr;

		erreur(EXCe.EXCgetMessage(), false);
	}

	return pSOMsommet;
}


/*****************************************
Ajout d'un sommet.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : l'ajout du sommet passé en paramètre au graphe.
Entraîne : Un exception de type Cexception si le graphe possède déjà un sommet avec ce numéro.
******************************************/
void CGraphe::GRAajouterSommet(CSommet * pSOMobjet)
{
	unsigned int uiNumero = pSOMobjet->SOMgetNumero();
	if (GRAgetPosSommet(pSOMobjet) != GRA_AUCUN_SOMMET)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Impossible d'ajouter le sommet au graphe : il en existe deja un avec le numero %d.", uiNumero);
		throw Cexception(EXC_SOMMET_UNIQUE, pcMsg);
	}

	uiGRAnbSommets++;
	ppSOMGRAsommets = (CSommet **) realloc(ppSOMGRAsommets, sizeof(CSommet *) * (uiGRAnbSommets + 1));

	if (ppSOMGRAsommets == nullptr)
	{
		erreur("Erreur d'allocation memoire dans CGraphe::GRAajouterSommet(CSommet*). Le programme s'est arrete.");
	}

	// Si uiNumero + 1 > taille du tableau de positions, on realloue le tableau puis qu'il contienne uiNumero+1 cases
	if (uiGRAtailleTableau <= uiNumero)
	{
		unsigned int * puiTemp = new unsigned int[uiNumero + 1]();

		// On copie le tableau de bases dans uiTmp pour garder les valeurs déjà présentes
		memcpy_s(puiTemp, (uiNumero + 1) * sizeof(unsigned int), puiGRApositionsSommets, (uiGRAtailleTableau) * sizeof(unsigned int));

		uiGRAtailleTableau = uiNumero + 1;

		if (puiTemp == nullptr)
		{
			erreur("Erreur de copie mémoire dans CGraphe::GRAajouterSommet(CSommet*). Le programme s'est arrêté.");
		}

		delete[] puiGRApositionsSommets;
		puiGRApositionsSommets = puiTemp;
	}
	
	ppSOMGRAsommets[uiGRAnbSommets] = pSOMobjet;
	puiGRApositionsSommets[uiNumero] = uiGRAnbSommets;
}


/*****************************************
Création d'un arc reliant deux sommets.
******************************************
Entrée : le numéro du sommet de départ.
Entrée : le numéro du sommet d'arrivée
Nécessite : rien.
Sortie : rien.
Entraîne : La création d'un arc entre les deux sommets.
Entraîne : Une exception de type Cexception si le graphe ne possède
		   pas de sommets numéro uiNumDepart et uiNumArrivee.
******************************************/
void CGraphe::GRAcreerArc(unsigned int uiNumDepart, unsigned int uiNumArrivee)
{
	CSommet * pSOMdep, * pSOMarr;

	pSOMdep = GRAgetSommetNumero(uiNumDepart);
	pSOMarr = GRAgetSommetNumero(uiNumArrivee);

	if (pSOMdep == nullptr)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, sizeof(pcMsg), "Erreur lors de la création de l'arc entre les sommets %u et %u : "
			"le graphe ne possède pas de sommet numéro %u.", uiNumDepart, uiNumArrivee, uiNumDepart);

		throw Cexception(EXC_SOMMET_INEXISTANT, pcMsg);
	}

	if (pSOMarr == nullptr)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, sizeof(pcMsg), "Erreur lors de la création de l'arc entre les sommets %u et %u : "
			"le graphe ne possède pas de sommet numéro %u.", uiNumDepart, uiNumArrivee, uiNumArrivee);

		throw Cexception(EXC_SOMMET_INEXISTANT, pcMsg);
	}

	pSOMdep->SOMajouterSuccesseur(pSOMarr);
}


/*****************************************
Suppression d'un arc
******************************************
Entrée : le numéro du sommet de départ.
Entrée : le numéro du sommet d'arrivée.
Nécessite : rien.
Sortie : rien.
Entraîne : La suppression de l'arc entre les deux sommets.
Entraîne : Une exception de type Cexception si le graphe ne possède
		   pas de sommets numéro uiNumDepart ou uiNumArrivee.
******************************************/
void CGraphe::GRAsupprimerArc(unsigned int uiNumDepart, unsigned int uiNumArrivee)
{
	CSommet * pSOMdep, *pSOMarr;

	pSOMdep = GRAgetSommetNumero(uiNumDepart);
	pSOMarr = GRAgetSommetNumero(uiNumArrivee);

	if (pSOMdep == nullptr)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, sizeof(pcMsg), "Erreur lors de la suppression de l'arc entre les sommets %u et %u : "
			"le graphe ne possède pas de sommet numéro %u.", uiNumDepart, uiNumArrivee, uiNumDepart);

		throw Cexception(EXC_SOMMET_INEXISTANT, pcMsg);
	}

	if (pSOMarr == nullptr)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, sizeof(pcMsg), "Erreur lors de la suppression de l'arc entre les sommets %u et %u : "
			"le graphe ne possède pas de sommet numéro %u.", uiNumDepart, uiNumArrivee, uiNumArrivee);

		throw Cexception(EXC_SOMMET_INEXISTANT, pcMsg);
	}

	pSOMdep->SOMsupprimerSuccesseur(pSOMarr);
}

/*****************************************
Récupération d'un sommet en fonction de son numéro.
******************************************
Entrée : le numéro du sommet
Nécessite : rien
Sortie : un pointeur sur une instance de CSommet ou nullptr.
Entraîne : rien.
******************************************/
CSommet * CGraphe::GRAgetSommetNumero(unsigned int uiNumero) const
{
	CSommet * pSOMsommet = nullptr;

	// Si le numéro appartient bien au tableau des positions
	if (uiNumero < uiGRAtailleTableau)
	{
		// On la récupère
		unsigned int uiPos = puiGRApositionsSommets[uiNumero];
		// Si pos == 0, alors le sommet n'est pas dans le graphe (les sommets commencent à l'indice 1)
		if (uiPos != GRA_AUCUN_SOMMET)
		{
			pSOMsommet = ppSOMGRAsommets[uiPos];
		}
	}

	return pSOMsommet;
}


/*****************************************
Récupération d'un sommet en fonction de sa position dans le tableau
******************************************
Entrée : la position du sommet.
Nécessite : rien
Sortie : un pointeur sur une instance de CSommet ou nullptr.
Entraîne : rien.
******************************************/
CSommet * CGraphe::GRAgetSommetPosition(unsigned int uiPos) const
{
	if (uiPos >= uiGRAnbSommets)
	{
		return nullptr;
	}

	return ppSOMGRAsommets[uiPos + 1];
}


/*****************************************
Lecture de la position d'un sommet.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : la position du sommet ou 0 si le sommet n'est pas dans le graphe.
Entraîne : rien.
******************************************/
unsigned int CGraphe::GRAgetPosSommet(const CSommet * pSOMobjet) const
{
	// On vérifie que le sommet est bien dans ce graphe là
	if (pSOMobjet->SOMgetGraphe() == this)
	{
		unsigned int uiNumero = pSOMobjet->SOMgetNumero();
		if (uiNumero >= uiGRAtailleTableau)
		{
			return GRA_AUCUN_SOMMET;
		}

		return puiGRApositionsSommets[uiNumero];
	}

	return GRA_AUCUN_SOMMET;
}


/*****************************************
Suppression d'un sommet.
******************************************
Entrée : un pointeur sur une instance de CSommet.
Nécessite : rien.
Sortie : rien.
Entraîne : la suppression du sommet passé en paramètre du graphe.
******************************************/
void CGraphe::GRAsupprimerSommet(CSommet * pSOMobjet)
{
	unsigned int uiBoucle, uiNumero, uiPos, uiNbArcs;

	uiNumero = pSOMobjet->SOMgetNumero();
	uiPos = GRAgetPosSommet(pSOMobjet);

	if (uiPos < 0)
	{
		char pcMsg[1024] = { 0 };
		sprintf_s(pcMsg, 1024, "Impossible de supprimer le sommet numéro %d, il n'est pas dans le graphe.", uiNumero);
		throw Cexception(EXC_SOMMET_HORS_GRAPHE, pcMsg);
	}

	// On commence par désallouer le sommet à supprimer et par actualiser le tableau des positions
	delete pSOMobjet;
	puiGRApositionsSommets[uiNumero] = GRA_AUCUN_SOMMET;

	// Décaler les sommets d'une case vers la gauche 
	// + décrémenter les valeurs de puiGRApositionsSommets

	for (uiBoucle = uiPos; uiBoucle < uiGRAnbSommets; uiBoucle++)
	{
		unsigned int uiNumeroSommetBoucle;

		// décalage
		ppSOMGRAsommets[uiBoucle] = ppSOMGRAsommets[uiBoucle + 1];

		if (ppSOMGRAsommets[uiBoucle] != nullptr)
		{
			// décrémentation de la position dans le tableau des positions
			uiNumeroSommetBoucle = ppSOMGRAsommets[uiBoucle]->SOMgetNumero();
			puiGRApositionsSommets[uiNumeroSommetBoucle]--;
		}
	}

	// On retire une case au tableau
	ppSOMGRAsommets = (CSommet **) realloc(ppSOMGRAsommets, sizeof(CSommet *) * uiGRAnbSommets);
	uiGRAnbSommets--;
}


/*****************************************
Affichage d'un graphe.
******************************************
Entrée : rien.
Nécessite : rien.
Sortie : rien.
Entraîne : l'affichage d'un graphe dans la console.
******************************************/
void CGraphe::GRAafficher() const
{
	cout << *this << endl;
}


/*****************************************
Vérifie le contenu d'une instance de CTableauAssociatif
pour créer un objet CGraphe
******************************************
Entrée : Un pointeur sur une instance de CTableauAssociatif.
Nécessite : rien.
Sortie : rien.
Entraîne : une Cexception  est levée si le tableau de contient pas "NBSommets", "NBArcs", "Sommets" et "Arcs",
           ou que les types correspondants sont incorrects (resp. Entier, Entier, Chaine, Chaine)
******************************************/
void CGraphe::GRAverifierContenuTableau(CTableauAssociatif * pTABtab)
{
	char * pcValeurSommets, * pcValeurArcs;

	// On vérifie d'abord si toutes les balises son présentes

	if (pTABtab->TABgetIndiceCle(GRA_BALISE_NB_SOMMETS) == -1)
	{
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs '" GRA_BALISE_NB_SOMMETS "'  non renseigné.");
	}

	if (pTABtab->TABgetIndiceCle(GRA_BALISE_NB_ARCS) == -1)
	{
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs '" GRA_BALISE_NB_ARCS "'  non renseigné.");
	}

	if (pTABtab->TABgetIndiceCle(GRA_BALISE_SOMMETS) == -1)
	{
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs '" GRA_BALISE_SOMMETS "'  non renseigné.");
	}

	if (pTABtab->TABgetIndiceCle(GRA_BALISE_ARCS) == -1)
	{
		throw Cexception(EXC_ERREUR_SYNTAXIQUE, "Erreur : champs '" GRA_BALISE_ARCS "'  non renseigné.");
	}


	// Puis si leur valeur est correcte

	if (pTABtab->TABgetValeurType(GRA_BALISE_NB_SOMMETS) != TYPE_ENTIER || pTABtab->TABgetValeurEntier(GRA_BALISE_NB_SOMMETS) < 0)
	{
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation du graphe : La valeur de '" GRA_BALISE_NB_SOMMETS "' doit etre un nombre entier positif.");
	}

	if (pTABtab->TABgetValeurType(GRA_BALISE_NB_ARCS) != TYPE_ENTIER || pTABtab->TABgetValeurEntier(GRA_BALISE_NB_ARCS) < 0)
	{
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation du graphe : La valeur de '" GRA_BALISE_NB_ARCS "' doit etre un nombre entier positif.");
	}

	pcValeurSommets = supprimerEspaces(pTABtab->TABgetValeurChaine(GRA_BALISE_SOMMETS));

	// On vérifie que c'est bien une liste, c'est à dire une chaine qui commence par [ et termine par ]
	if (pTABtab->TABgetValeurType(GRA_BALISE_SOMMETS) != TYPE_CHAINE
		|| (pcValeurSommets[0] != '[' || pcValeurSommets[strlen(pcValeurSommets) - 1] != ']'))
	{
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation du graphe : La valeur de '" GRA_BALISE_SOMMETS "' doit etre une liste ('[....]')");
	}

	pcValeurArcs = supprimerEspaces(pTABtab->TABgetValeurChaine(GRA_BALISE_ARCS));

	// On vérifie que c'est bien une liste, c'est à dire une chaine qui commence par [ et termine par ]
	if (pTABtab->TABgetValeurType(GRA_BALISE_ARCS) != TYPE_CHAINE
		|| (pcValeurArcs[0] != '[' || pcValeurArcs[strlen(pcValeurArcs) - 1] != ']'))
	{
		throw Cexception(EXC_ERREUR_LEXICALE, "Erreur de creation du graphe : La valeur de '" GRA_BALISE_ARCS "' doit etre une liste ('[....]')");
	}

	delete[] pcValeurSommets;
	delete[] pcValeurArcs;
}

/*****************************************
Génération d'un graphe à partir d'un fichier
******************************************
Entrée : le nom du fichier
Nécessite : rien.
Sortie : une instance de CGraphe.
Entraîne : La création d'un objet CGraphe avec les informations du fichier
Entraîne : Une exception de type Cexception en cas de fichier introuvable, d'erreur syntaxique ou lexicale.
******************************************/
CGraphe CGraphe::GRAgenerer(const char * pcFichier)
{
	CGraphe GRAobj;
	CTableauAssociatif * pTABtab;
	unsigned int uiBoucle, uiNbArcs, uiNbSommets;
	char * pcListeSommets, * pcListeArcs;
	char * pcDebutSousChaine; // pointeur sur le 'N' de la uiBoucle-ième ligne "Numero=x\n"
	char * pcFinSousChaine; // pointeur sur le '\n' de la uiBoucle-ième ligne "Numero=x\n"

	pTABtab = CParseur::PARparserFichier(pcFichier);

	// Throw une exception si le contenu est incorrect
	CGraphe::GRAverifierContenuTableau(pTABtab);

	uiNbSommets = pTABtab->TABgetValeurEntier(GRA_BALISE_NB_SOMMETS);
	uiNbArcs = pTABtab->TABgetValeurEntier(GRA_BALISE_NB_ARCS);

	pcListeSommets = pTABtab->TABgetValeurChaine(GRA_BALISE_SOMMETS);
	pcListeArcs = pTABtab->TABgetValeurChaine(GRA_BALISE_ARCS);

	pcFinSousChaine = pcListeSommets;


	// Construction des sommets
	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		char * pcSousChaine; // "Numero=x\n"
		char * pcBalise; // "Numero", les espaces sont supprimés par la méthode
		char * pcValeur; // "x", les espaces sont supprimés par la méthode

		// Recherche du début de la chaine "Numero=x\n" de la uiBoucle-ieme ligne
		pcDebutSousChaine = strstr(pcFinSousChaine, GRA_BALISE_NUMERO);

		if (pcDebutSousChaine == nullptr) // moins de lignes que prévu ou la balise n'est pas "Numero"
		{
			throw Cexception(EXC_ERREUR_LEXICALE, "Erreur lors de la creation du graphe, 2 possibilites : \n"  
				"\t- La liste '" GRA_BALISE_SOMMETS "' contient moins de valeurs que precise par la balise '" GRA_BALISE_NB_SOMMETS  "\n"
				"\t- La syntaxe est mauvaise, elle doit ressembler a : '" GRA_BALISE_NUMERO "=x'.");
		}

		// La fin de la ligne est le caractère '\0' au lieu de '\n'
		pcFinSousChaine = strchr(pcDebutSousChaine, '\n');

		if (pcFinSousChaine == nullptr) // ']' sur la même ligne (la méthode GRAverifierContenuTableau() vérifie que la chaine termine bien par ']')
		{
			// La fin de la ligne est le caractère ']' au lieu de '\n'
			pcFinSousChaine = strchr(pcDebutSousChaine, '\0');
		}

		pcSousChaine = sousChaine(pcDebutSousChaine, pcFinSousChaine); // "Numero=x\n"

		pcBalise = CParseur::PARextrairePartieGauche(pcSousChaine); // "Numero", les espaces sont supprimés par la méthode
		pcValeur = CParseur::PARextrairePartieDroite(pcSousChaine); // "x", les espaces sont supprimés par la méthode

		if (analyserType(pcValeur) != TYPE_ENTIER || pcValeur[0] == '-')
		{
			// "x" ne correspond pas à un entier OU "x" correspond à un entier mais est négatif
			throw Cexception(EXC_ERREUR_LEXICALE, "Erreur lors de la creation du graphe : la valeur de la balise '" GRA_BALISE_NUMERO 
				"' doit être un entier positif ou nul");
		}

		try
		{
			// Création du sommet de numéro (int)pcValeur
			GRAobj.GRAcreerSommet(strtol(pcValeur, NULL, 10));
		}
		catch (Cexception EXCe)
		{
			char pcMsg[1024] = "Erreur lors de la création du graphe, l'exception suivante a ete lancee :\n\t";
			strcat_s(pcMsg, 1024, EXCe.EXCgetMessage());

			throw Cexception(EXC_ECHEC_TRANSFORMATION_TYPE, pcMsg);
		}
		
		delete[] pcBalise;
		delete[] pcValeur;
		delete[] pcSousChaine;
	}


	pcFinSousChaine = pcListeArcs;

	// Construction des arcs
	for (uiBoucle = 0; uiBoucle < uiNbArcs; uiBoucle++)
	{
		char * pcSousChaine; // "Debut=x,Fin=y\n"
		char * pcDebut; // "Debut=x"
		char * pcFin; // "Fin=y"
		char * pcBalise; // "Debut" ou "Fin" 
		char * pcValeur; // "x" ou "y"
		unsigned int uiNumSommetDebut; // x
		unsigned int uiNumSommetFin; // y

		// Recherche du début de la chaine "Debut=x,Fin=y\n" de la uiBoucle-ieme ligne
		pcDebutSousChaine = strstr(pcFinSousChaine, GRA_BALISE_DEBUT);

		if (pcDebutSousChaine == nullptr) // moins de lignes que prévu ou la balise n'est pas "Debut"
		{
			throw Cexception(EXC_ERREUR_LEXICALE, "Erreur lors de la creation du graphe, 2 possibilites : \n"
				"\t- La liste '" GRA_BALISE_ARCS "' contient moins de valeurs que precise par la balise '" GRA_BALISE_NB_ARCS "\n"
				"\t- La syntaxe est mauvaise, elle doit ressembler a : '" GRA_BALISE_DEBUT "=x, " GRA_BALISE_FIN "=y'.");
		}

		// Recherche de la fin de la chaine "Debut=x,Fin=y\n" de la uiBoucle-ieme ligne
		pcFinSousChaine = strchr(pcDebutSousChaine, '\n');

		if (pcFinSousChaine == nullptr) // ']' sur la même ligne (la méthode GRAverifierContenuTableau() vérifie que la chaine termine bien par ']')
		{
			// La fin de la ligne est le caractère '\0' au lieu de '\n'
			pcFinSousChaine = strchr(pcDebutSousChaine, '\0');
		}

		pcSousChaine = sousChaine(pcDebutSousChaine, pcFinSousChaine); // "Debut=x,Fin=y\n"

		// Séparation de "Debut=x" et "Fin=y"

		pcDebut = CParseur::PARextrairePartieGauche(pcSousChaine, ','); // "Debut=x"
		pcFin = CParseur::PARextrairePartieDroite(pcSousChaine, ','); // "Fin=y"

		// partie "Debut=x" ---------------------------------------------------------------------

		pcBalise = CParseur::PARextrairePartieGauche(pcDebut); // "Debut"
		pcValeur = CParseur::PARextrairePartieDroite(pcDebut); // "x"

		// la chaine "Debut" est forcément présente, pas besoin de tester

		if (analyserType(pcValeur) != TYPE_ENTIER || pcValeur[0] == '-')
		{
			// "x" ne correspond pas à un entier OU "x" correspond à un entier mais est négatif
			throw Cexception(EXC_ERREUR_LEXICALE, "Erreur lors de la creation du graphe : la valeur de la balise '" GRA_BALISE_DEBUT
				"' doit être un entier positif ou nul");
		}

		uiNumSommetDebut = strtol(pcValeur, nullptr, 10); // x

		delete[] pcBalise;
		delete[] pcValeur;


		// partie "Fin=y" -----------------------------------------------------------------------

		pcBalise = CParseur::PARextrairePartieGauche(pcFin); // "Fin"
		pcValeur = CParseur::PARextrairePartieDroite(pcFin); // "y"

		// la chaine "Fin" est forcément présente, pas besoin de tester

		if (analyserType(pcValeur) != TYPE_ENTIER || pcValeur[0] == '-')
		{
			// "y" ne correspond pas à un entier OU "y" correspond à un entier mais est négatif
			throw Cexception(EXC_ERREUR_LEXICALE, "Erreur lors de la creation du graphe : la valeur de la balise '" GRA_BALISE_FIN
				"' doit être un entier positif ou nul");
		}

		uiNumSommetFin = strtol(pcValeur, nullptr, 10); // y

		delete[] pcBalise;
		delete[] pcValeur;

		// Création de l'arc x --> y
		try 
		{
			GRAobj.GRAcreerArc(uiNumSommetDebut, uiNumSommetFin);
		}
		catch (Cexception EXCe)
		{
			erreur("Une erreur est survenue lors de la creation d'un arc. L'exception suivante a ete soulevee : \n", false);
			cout << EXCe.EXCgetMessage() << endl;
			cout << "Le programme continue..." << endl;
		}

		delete[] pcDebut;
		delete[] pcFin;
		delete[] pcSousChaine;
	}

	return GRAobj;
}

/*****************************************
Surchage de l'opérateur <<.
******************************************
Entrée : un flux, une instance de CGraphe.
Nécessite : rien.
Sortie : un flux.
Entraîne : l'affichage du graphe passé en paramètre.
******************************************/
std::ostream & operator<<(std::ostream & oFlux, const CGraphe & GRAgraphe)
{
	unsigned int uiBoucle;
	unsigned int uiNbSommets = GRAgraphe.GRAgetNbSommets();;

	oFlux << "----------------------------------" << std::endl;
	oFlux << "Graphe :" << std::endl;
	oFlux << "Nombre de sommets : " << uiNbSommets << std::endl << std::endl;

	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++)
	{
		CSommet * pSOMsommet = GRAgraphe.GRAgetSommetPosition(uiBoucle);
		if (pSOMsommet != nullptr)
		{
			oFlux << *pSOMsommet << std::endl << std::endl;
		}
	}

	oFlux << "----------------------------------" << std::endl;

	return oFlux;
}