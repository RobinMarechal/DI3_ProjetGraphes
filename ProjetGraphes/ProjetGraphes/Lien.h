#ifndef CLIEN_H
#define CLIEN_H

#include "Sommet.h"

class CSommet;

// Relier 2 sommets pour former un arc
class CLien {

	// attributs
	CSommet * pSOMLIEsommetParent;
	CSommet * pSOMLIEsommetVise;

public:

	// constructeurs
	CLien(CSommet * pSOMsommetParent, CSommet * pSOMsommetVise);
	CLien(CLien & ARCarc);
	~CLien();

	// operateurs
	virtual CLien & operator=(CLien & ARCarc);
	virtual bool operator==(CLien & ARCarc) const;
	virtual bool operator!=(CLien & ARCarc) const;
	virtual void ARCdebug() const;
};

#endif // ARC_H
