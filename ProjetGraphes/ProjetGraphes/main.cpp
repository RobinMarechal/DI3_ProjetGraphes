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

	CSommet * s1 = g.GRAajouterSommet(1);
	CSommet * s2 = g.GRAajouterSommet(2);
	CSommet * s3 = g.GRAajouterSommet(3);

	s1->SOMajouterSuccesseur(s2);
	s1->SOMajouterSuccesseur(s3);

	cout << s1->SOMgetNbSuccesseurs() << endl;
	cout << s1->SOMgetNbPredecesseurs() << endl;
	cout << s2->SOMgetNbSuccesseurs() << endl;
	cout << s2->SOMgetNbPredecesseurs() << endl;
	cout << s3->SOMgetNbSuccesseurs() << endl;
	cout << s3->SOMgetNbPredecesseurs() << endl;

	s1->SOMsupprimerSuccesseur(s1);
	cout << "supp 2" << endl;
	s1->SOMsupprimerSuccesseur(s2);

	cout << " Supprimé : " << endl;

	cout << s1->SOMgetNbSuccesseurs() << endl;
	cout << s1->SOMgetNbPredecesseurs() << endl;
	cout << s2->SOMgetNbSuccesseurs() << endl;
	cout << s2->SOMgetNbPredecesseurs() << endl;
	cout << s3->SOMgetNbSuccesseurs() << endl;
	cout << s3->SOMgetNbPredecesseurs() << endl;

	g.GRAdebug();
}

int main(int argc, char * argv[])
{
	//robin();
	gregoire();
	return 0;
}