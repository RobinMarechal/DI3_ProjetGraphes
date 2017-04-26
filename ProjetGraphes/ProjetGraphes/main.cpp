#include <iostream>

#include "constantes.h"
#include "helpers.h"
#include "Graphe.h"

using namespace std;

void gregoire()
{
	CGraphe g;

	g.GRAajouterSommet(1);
	g.GRAajouterSommet(2);
	g.GRAajouterSommet(3);

	g.GRAgetSommet(1)->SOMajouterSuccesseur(g.GRAgetSommet(2));

	g.GRAdebug();
}

void robin()
{
	CGraphe g;

	g.GRAajouterSommet(1);
	g.GRAajouterSommet(2);
	g.GRAajouterSommet(3);

	g.GRAdebug();
}

int main(int argc, char * argv[])
{
	//robin();
	gregoire();
	return 0;
}