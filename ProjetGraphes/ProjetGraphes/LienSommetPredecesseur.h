#ifndef C_LIEN_SOMMET_PREDECESSEUR_H
#define C_LIEN_SOMMET_PREDECESSEUR_H

#include "Sommet.h"
#include "Lien.h"

class CSommet;

// trigramme : LSP
class CSommet::CLienSommetPredecesseur : public CLien
{
public:
	CLienSommetPredecesseur(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);
	~CLienSommetPredecesseur();
};

#endif // C_LIEN_SOMMET_PREDECESSEUR_H
