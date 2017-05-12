#include <iostream>

#include "helpers.h"
#include "Graphe.h"
#include "OperationGraphe.h"

using namespace std;

int main(int argc, char * argv[])
{
	int iBoucle;

	for (iBoucle = 1; iBoucle < argc; iBoucle++)
	{
		CGraphe GRAgraphe, GRAgrapheInverse;
		COperationGraphe OPGoperation;

		cout << "------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Graphe numero " << iBoucle << endl;
		cout << "Fichier : " << argv[iBoucle] << endl;
		cout << "------------------------------------------------------------------------------------------------------------" << endl << endl;

		try
		{
			// Génération du graphe.

			GRAgraphe = CGraphe::GRAgenerer(argv[iBoucle]);

			cout << GRAgraphe << endl;

			// Inversion du graphe.

			GRAgrapheInverse = OPGoperation.OPGinverserGraphe(GRAgraphe);

			cout << "Graphe inverse : " << endl;
			cout << GRAgrapheInverse << endl;

		} 
		catch(Cexception EXCe)
		{
			cout << EXCe.EXCgetMessage() << endl;
		}
	}
	

	return 0;
}