#ifndef CARC_PARTANT_H
#define CARC_PARTANT_H

#include "Sommet.h"
#include "Arc.h"

// trigramme : SUC
class CArcPartant : public CArc
{
public:
	CArcPartant(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);
	CArcPartant(CArcPartant & ARRobjet);
	~CArcPartant();

	CArcPartant & operator=(CArcPartant & ARRobjet);
	bool operator==(CArcPartant & ARRobjet) const;
	bool operator!=(CArcPartant & ARRobjet) const;

	void ARCdebug() const;
};

#endif // CARC_PARTANT_H
