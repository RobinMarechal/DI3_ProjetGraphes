#ifndef CARC_ARRIVANT_H
#define CARC_ARRIVANT_H

#include "Sommet.h"
#include "ARC.h"

// trigramme : ARR
class CSommet::CArcArrivant : public CSommet::CArc
{
public:
	CArcArrivant(CSommet * pSOMsommetVise);
	CArcArrivant(CArcArrivant & ARRobjet);
	CArcArrivant(CSommet::CArc & ARCobjet);
	~CArcArrivant();

	CSommet::CArcArrivant & operator=(CArc & ARCobjet);
};

#endif // C_LIEN_SOMMET_PREDECESSEUR_H
