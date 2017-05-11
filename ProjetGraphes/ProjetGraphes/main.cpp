#include <iostream>

#include "helpers.h"
#include "Graphe.h"
#include "OperationGraphe.h"

using namespace std;

int main(int argc, char * argv[])
{
	CGraphe GRAgraphe;
	CGraphe GRAgrapheInverse;

	COperationGraphe OPGoperation;

	try
	{
		// G�n�ration du graphe.

		GRAgraphe = CGraphe::GRAgenerer(argv[1]);

		cout << GRAgraphe << endl;


		// G�n�ration du graphe inverse.

		GRAgrapheInverse = OPGoperation.OPGinverserGraphe(GRAgraphe);

		cout << GRAgrapheInverse << endl;

	} catch(Cexception EXCe)
	{
		cout << EXCe.EXCgetMessage() << endl;
	}

	return 0;
}