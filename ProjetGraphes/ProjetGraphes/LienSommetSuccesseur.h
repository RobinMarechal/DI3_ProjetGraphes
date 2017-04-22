#ifndef C_LIEN_SOMMET_SUCCESSEUR_H
#define C_LIEN_SOMMET_SUCCESSEUR_H

#include "Sommet.h"
#include "Lien.h"

class CSommet;

// trigramme : LSS
class CSommet::CLienSommetSuccesseur : public CLien
{
public:
	CLienSommetSuccesseur(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);
	~CLienSommetSuccesseur();
};

#endif // C_LIEN_SOMMET_SUCCESSEUR_H