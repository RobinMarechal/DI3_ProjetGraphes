#include <iostream>

#include "constantes.h"
#include "helpers.h"
#include "Graphe.h"
#include "ListeArcs.h"

using namespace std;

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
	robin();

	return 0;
}