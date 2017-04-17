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
	std::vector<int>vSum3{ {20,20,20,1,2,2} };
	addVectors(vSum1,vSum2);
	concatVectors(vSum1, vSum2);
	shiftRight(vSum1);
	rotateLeft(vSum2);
	searchAdjacent(vSum3);
}

std::vector<int> addVectors(std::vector<int> v1, std::vector<int> v2) // Suma els valors de dos vectors de 1 dimensió. El resultat queda en un tercer vector.
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

void shiftRight(std::vector<int> &v1)
{
	int lastOne = v1[v1.size() - 1];
	for(int i=v1.size()-1;i>=0;i--)
	{
		if(i==0)
		{
			v1[i] = lastOne;
		}
		else
		{
			v1[i] = v1[i - 1];
		}
	}
}

void rotateLeft(std::vector<int> &v1)
{
	int med = v1.size()/2+0.5;
	for(int i=0;i<med;i++)
	{
		int aux = v1[i];
		v1[i] = v1[v1.size() - 1 - i];
		v1[v1.size() - 1 - i]=aux;
	}
}

void searchAdjacent(std::vector<int> &v1)
{
	for(int i=0;i<v1.size();i++)
	{
		if(i>1)
		{
			if(v1[i]==v1[i-1] && v1[i]==v1[i-2])
			{
				v1[i] = rand();
				v1[i - 1] = rand();
				v1[i - 2] = rand();
			}
		}
	}
}