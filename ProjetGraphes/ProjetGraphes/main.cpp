#include <iostream>

#include "helpers.h"
#include "Graphe.h"
#include "OperationGraphe.h"

using namespace std;

int main(int argc, char * argv[])
{
	unsigned int uiBoucle;

	for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
	{
		CGraphe GRAgraphe, GRAgrapheInverse;
		COperationGraphe OPGoperation;

		cout << "------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Graphe numero " << uiBoucle << endl;
		cout << "Fichier : " << argv[uiBoucle] << endl;
		cout << "------------------------------------------------------------------------------------------------------------" << endl << endl;

		try
		{
			// Génération du graphe.

			GRAgraphe = CGraphe::GRAgenerer(argv[uiBoucle]);

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