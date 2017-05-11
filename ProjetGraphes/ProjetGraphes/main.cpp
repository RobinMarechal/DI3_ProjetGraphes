#include <iostream>

#include "helpers.h"
#include "Graphe.h"
#include "OperationGraphe.h"

using namespace std;

void gregoire()
{
	CGraphe g;

	g.GRAcreerSommet(1);
	g.GRAcreerSommet(2);
	g.GRAcreerSommet(3);

	g.GRAgetSommetNumero(1)->SOMajouterSuccesseur(g.GRAgetSommetNumero(2));
	g.GRAgetSommetNumero(1)->SOMajouterSuccesseur(g.GRAgetSommetNumero(3));
	g.GRAgetSommetNumero(2)->SOMajouterSuccesseur(g.GRAgetSommetNumero(3));
	g.GRAgetSommetNumero(3)->SOMajouterSuccesseur(g.GRAgetSommetNumero(2));


	cout << g << endl << endl;

	COperationGraphe o;

	CGraphe g2 = o.OPGinverserGraphe(g);

	cout << g2 << endl;
}

void robin()
{
	/*
	char * pcFichier = "C:\\Users\\Robin\\Desktop\\Divers\\Work\\Polytech\\S6\\C++\\DI3_ProjetGraphes\\JePasse\\fichier01.txt";

	CGraphe g = CGraphe::GRAgenerer(pcFichier);
	COperationGraphe o;



	CGraphe g2;
	
	g2 = o.OPGinverserGraphe(g);

	cout << g << endl;

	cout << g2 << endl;
	*/

	CGraphe g;

	g.GRAcreerSommet(0);
	g.GRAcreerSommet(1);

	g.GRAcreerArc(0, 1);
	g.GRAcreerArc(1, 0); 

	cout << g << endl;

	g.GRAsupprimerArc(0, 1);

	cout << g << endl;

	g.GRAgetSommetNumero(1)->SOMsupprimerSuccesseur(g.GRAgetSommetNumero(0));

	cout << g << endl;
}

int main(int argc, char * argv[])
{
	robin();
	//gregoire();

	return 0;
}