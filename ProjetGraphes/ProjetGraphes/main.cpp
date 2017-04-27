#include <iostream>

#include "constantes.h"
#include "helpers.h"
#include "Graphe.h"

using namespace std;

void gregoire()
{
	CGraphe g(3);

	g.GRAajouterSommet(1);
	g.GRAajouterSommet(2);
	g.GRAajouterSommet(3);

	g.GRAgetSommet(1)->SOMajouterSuccesseur(g.GRAgetSommet(2));
	* g.GRAgetSommet(1) >> g.GRAgetSommet(3);

	cout << g.GRAgetSommet(1) << endl;

	g.GRAdebug();
}

void robin()
{
	CGraphe g(3);

	CSommet * s1 = g.GRAajouterSommet(1);
	CSommet * s2 = g.GRAajouterSommet(2);
	CSommet * s3 = g.GRAajouterSommet(3);

	cout << "DEBUG 1:" << endl;
	g.GRAdebug();

	g.GRAsupprimerSommet(s2);

	cout << "DEBUG 2:" << endl;
	g.GRAdebug();

	g.GRAsupprimerSommet(s1);

	cout << "DEBUG 3:" << endl;
	g.GRAdebug();

	CSommet * s5 = g.GRAajouterSommet(4);

	cout << "DEBUG 4:" << endl;
	g.GRAdebug();
}

int main(int argc, char * argv[])
{
	//robin();
	gregoire();
	return 0;
}