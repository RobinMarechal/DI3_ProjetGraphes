#include <iostream>

#include "helpers.h"
#include "Graphe.h"
#include "OperationGraphe.h"

using namespace std;

void gregoire()
{
	CGraphe g;
	CGraphe * g2;

	g.GRAcreerSommet(1);
	g.GRAcreerSommet(2);
	g.GRAcreerSommet(3);

	g.GRAgetSommetNumero(1)->SOMajouterSuccesseur(g.GRAgetSommetNumero(2));
	g.GRAgetSommetNumero(1)->SOMajouterSuccesseur(g.GRAgetSommetNumero(3));
	g.GRAgetSommetNumero(2)->SOMajouterSuccesseur(g.GRAgetSommetNumero(3));
	g.GRAgetSommetNumero(3)->SOMajouterSuccesseur(g.GRAgetSommetNumero(2));


	cout << g << endl << endl;

	COperationGraphe o;

	g2 = o.OPGinverserGraphe(g);

	cout << *g2 << endl;
}

void robin()
{
	char * pcFichier = "C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetGraphes\\JePasse\\fichier01.txt";

	CGraphe g = CGraphe::GRAgenerer(pcFichier);

	cout << g;

}

int main(int argc, char * argv[])
{
	robin();
	//gregoire();

	return 0;
}