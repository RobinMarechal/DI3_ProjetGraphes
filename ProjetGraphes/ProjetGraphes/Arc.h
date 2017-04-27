#ifndef CARC_H
#define CARC_H

#include "Sommet.h"

class CSommet;

// Relier 2 sommets pour former un arc
class CArc
{
private:

	// attributs
	CSommet * pSOMARCsommetVise; // Sommet visé par l'arc
	CSommet * pSOMARCsommetParent; // Sommet de départ de l'arc

public:

	// constructeurs
	CArc(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);
	CArc(CArc & ARCarc);
	~CArc();

	CSommet * ARCgetSommetVise() const;
	CSommet * ARCgetSommetParent() const;

	void ARCsetSommetVise(CSommet * pSOMsommetVise);
	void ARCsetSommetParent(CSommet * pSOMsommetParent);

	virtual void ARCdebug() const = 0;
};

#endif // CARC_H
