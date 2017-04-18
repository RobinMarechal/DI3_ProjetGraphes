#include <iostream>

#include "constantes.h"
#include "helpers.h"
#include "Graphe.h"
#include "ListeArcs.h"

using namespace std;

void robin()
{
	CGraphe g;
	CSommet * s1 = new CSommet(&g, 1);
	CSommet * s2 = new CSommet(&g, 2);

	s1->SOMajouterSuccesseur(s2);
	s2->SOMajouterSuccesseur(s1);

	CListeArcs succ1 = s1->SOMgetListeSuccesseurs();
	CListeArcs pred1 = s1->SOMgetListePredecesseurs();
	CListeArcs succ2 = s2->SOMgetListeSuccesseurs();
	CListeArcs pred2 = s2->SOMgetListePredecesseurs();

	cout << succ1.LISgetDim() << endl;
	cout << pred1.LISgetDim() << endl;
	cout << succ2.LISgetDim() << endl;
	cout << pred2.LISgetDim() << endl;

	cout << *(succ1.LISgetArc(0)) << endl;

	g.GRAdebug();
}

int main(int argc, char * argv[])
{
	robin();

	return 0;
}