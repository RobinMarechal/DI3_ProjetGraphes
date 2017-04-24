#ifndef CARC_PARTANT_H
#define CARC_PARTANT_H

#include "Sommet.h"
#include "Arc.h"

// trigramme : SUC
class CSommet::CArcPartant : public CArc
{
public:
	CArcPartant(CSommet * pSOMsommetVise);
	~CArcPartant();
};

#endif // CARC_PARTANT_H
