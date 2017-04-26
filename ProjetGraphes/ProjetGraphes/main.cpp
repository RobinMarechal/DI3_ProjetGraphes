#include <iostream>

#include "constantes.h"
#include "helpers.h"
#include "Graphe.h"

using namespace std;

void robin()
{
	CGraphe g;

	CSommet * s1 = g.GRAajouterSommet(1);
	CSommet * s2 = g.GRAajouterSommet(2);
	CSommet * s3 = g.GRAajouterSommet(3);

	s1->SOMajouterSuccesseur(s2);

	cout << s1->SOMgetNbSuccesseurs() << endl;
	cout << s1->SOMgetNbPredecesseurs() << endl;
	cout << s2->SOMgetNbSuccesseurs() << endl;
	cout << s2->SOMgetNbPredecesseurs() << endl;

	g.GRAdebug();
}

int main(int argc, char * argv[])
{
	robin();

	return 0;
}