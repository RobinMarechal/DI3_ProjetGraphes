#ifndef OPERATION_GRAPHE_H
#define OPERATION_GRAPHE_H

#include "Graphe.h"
#include "Sommet.h"
#include "ArcArrivant.h"
#include "ArcPartant.h"
#include "constantes.h"
#include "Cexception.h"
#include "helpers.h"

class COperationGraphe
{
public:
	COperationGraphe();
	~COperationGraphe();

	CGraphe * OPGinverserGraphe(const CGraphe & GRAgraphe) const;
};

#endif // OPERATION_GRAPHE_H