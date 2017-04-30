#include <iostream>

#include "constantes.h"
#include "helpers.h"
#include "Graphe.h"
#include "OperationGraphe.h"

using namespace std;

void gregoire()
{
	CGraphe g(3);

	g.GRAcreerSommet(1);
	g.GRAcreerSommet(2);
	g.GRAcreerSommet(3);

	g.GRAgetSommetNumero(1)->SOMajouterSuccesseur(g.GRAgetSommetNumero(2));
	g.GRAgetSommetNumero(1)->SOMajouterSuccesseur(g.GRAgetSommetNumero(3));
	g.GRAgetSommetNumero(2)->SOMajouterSuccesseur(g.GRAgetSommetNumero(3));
	g.GRAgetSommetNumero(3)->SOMajouterSuccesseur(g.GRAgetSommetNumero(2));


	cout << g << endl << endl;

	COperationGraphe o;

	cout << o.OPGinverserGraphe(g) << endl;
}

void robin()
{
	CGraphe g(3);

	CSommet * s1 = g.GRAcreerSommet(1);
	CSommet * s3 = g.GRAcreerSommet(3);
	CSommet * s2 = g.GRAcreerSommet(11);

	s1->SOMajouterSuccesseur(s3);
	s2->SOMajouterSuccesseur(s1);	
	s1->SOMajouterSuccesseur(s2);
	s2->SOMajouterSuccesseur(s3);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	g.GRAdebug();

	cout << "Inversion..." << endl;

	COperationGraphe og;

	CGraphe * g2 = og.OPGinverserGraphe(g);

	g2->GRAdebug();

	cout << g2->GRAgetSommetPosition(0) << endl;
	cout << g2->GRAgetSommetPosition(1) << endl;
	cout << g2->GRAgetSommetPosition(2) << endl;
}

int main(int argc, char * argv[])
{
	//robin();
	gregoire();

	return 0;
}