#include <vector>
#include <iostream>
#include "Vectors - Guide.h"

void main()
{
	std::vector<int>v1(5); // Inicialitzem un vector de 5 posicions amb valor 0 (es impossible inicialitzar-lo sense valor).
	std::vector<int>v2(10); // Inicialitzem un vector de 10 posicions amb valor 0.
	std::vector<int>v3({ 10,9,8,7,6,5,4,3,2,1 }); // Inicialitzem el vector amb els valors seleccionats.
	std::vector<std::string>v4({ "Gertrudiz","Pancracia","Anacleto","Hipolito","Eustaquio","Fulgencia" }); // Inicialitzem el vector d'strings amb els valors seleccionats.
	std::vector<int>v5(v3); // Inicialitzem vector amb els mateixos valors que v3.
	std::vector<std::string>v6({ "Pepe","21 de noviembre,1997","39408182X","Ginoberto","7 de junio, 1998","40391289Z","Platon","16 de enero","53424231T" });
	std::vector<int>vSum1({ 10,3,5 });
	std::vector<int>vSum2({ 20,8,12 });
	addVectors(vSum1,vSum2);
	concatVectors(vSum1, vSum2);
}

std::vector<int> addVectors(std::vector<int> v1, std::vector<int> v2) // Suma els valors de dos vectors de 1 dimensi�. El resultat queda en un tercer vector.
{
	std::vector<int>vSuma(v1);
	if (v1.size()==v2.size())
	{
		for (int i = 0; i < v1.size(); i++)
		{
			vSuma[i] += v2[i];
		}
		return vSuma;
	}
}

void concatVectors(std::vector<int> &v1, std::vector<int> v2) // Concatena dos vectors i guarda el resultat en el primer vector.
{
	int x = v2.size();
	for(int i=0;i<x;i++)
	{
		v1.push_back(v2[i]);
	}
}

void shiftRifht()
{

}