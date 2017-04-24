#ifndef CARC_H
#define CARC_H

#include "Sommet.h"

class CSommet;

// Relier 2 sommets pour former un arc
class CSommet::CArc {

	// attributs
	CSommet * pSOMARCsommetVise;

public:

	// constructeurs
	CArc(CSommet * pSOMsommetVise);
	CArc(CArc & ARCarc);
	~CArc();

	CSommet * ARCgetSommetVise() const;

	// operateurs
	virtual CArc & operator=(CArc & ARCarc) = 0;
	virtual bool operator==(CArc & ARCarc) const;
	virtual bool operator!=(CArc & ARCarc) const;
	virtual void ARCdebug() const = 0;
};

#endif // CARC_H
