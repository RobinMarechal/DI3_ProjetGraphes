#ifndef CARC_ARRIVANT_H
#define CARC_ARRIVANT_H

#include "Sommet.h"
#include "Arc.h"

// trigramme : ARR
class CArcArrivant : public CArc
{
public:
	CArcArrivant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);
	CArcArrivant(CArcArrivant & ARRobjet);
	~CArcArrivant();

	CArcArrivant & operator=(CArcArrivant & ARRobjet);
	bool operator==(CArcArrivant & ARRobjet) const;
	bool operator!=(CArcArrivant & ARRobjet) const;

	void ARCdebug() const;
};

#endif // C_LIEN_SOMMET_PREDECESSEUR_H
