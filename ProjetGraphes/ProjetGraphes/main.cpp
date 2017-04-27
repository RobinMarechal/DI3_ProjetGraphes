#include <iostream>

#include "constantes.h"
#include "helpers.h"
#include "Graphe.h"

using namespace std;

void gregoire()
{
	CGraphe g(3);

	g.GRAcreerSommet(1);
	g.GRAcreerSommet(2);
	g.GRAcreerSommet(3);

	g.GRAgetSommet(1)->SOMajouterSuccesseur(g.GRAgetSommet(2));
	* g.GRAgetSommet(1) >> g.GRAgetSommet(3);

	cout << g.GRAgetSommet(1) << endl;

	g.GRAdebug();
}

void robin()
{
	CGraphe g(4);

	CSommet * s1 = g.GRAcreerSommet(1);
	CSommet * s3 = g.GRAcreerSommet(3);
	CSommet * s2 = g.GRAcreerSommet(2);
	CSommet * s0 = g.GRAcreerSommet(0);

	s1->SOMajouterSuccesseur(s3);
	s2->SOMajouterSuccesseur(s1);
	s1->SOMajouterSuccesseur(s2);

	CSommet * sCopy = new CSommet(*s1);
	CSommet sCopy2 = *s1;

	cout << sCopy << endl;
	cout << (sCopy2 == *sCopy) << endl;

	cout << "OK" << endl;

	CArcPartant * t = s1->SOMgetArcPartant(0);

	s1->SOMgetArcPartant(0)->ARCdebug();
	t->ARCdebug();
}

int main(int argc, char * argv[])
{
	robin();
	//gregoire();
	return 0;
}