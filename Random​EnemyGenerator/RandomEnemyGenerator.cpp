#include <iostream>
#include <ctime>
#include <string>
using namespace std;

enum EnemyType {zombie, vampire,ghost,witch};

string names[] = { "Gruntilda","Pepe","Skel","Vlad","Mattie","Manolo" };

const int NumEnemies = 5;

struct Enemy
{
	int health;
	EnemyType type;
	string name;
};

#include "RandomEnemyGenerator.h"

void main()
{
	cout << "Enemy list: " << endl;
	Enemy BadGuy[NumEnemies];
	bool correct = true;
	for(int i=0;i<NumEnemies;i++)
	{
		BadGuy[i] = CreateRandomEnemy();
		for(int j=0;j<NumEnemies && correct==true;j++)
		{
			if(BadGuy[i]==BadGuy[j])
			{
				i--;
				correct = false;
			}
		}
		cout << "El nom de l'enemic numero " << i << " es " << BadGuy[i].name << " te un total de salut de " << BadGuy[i].health << " i es de tipus " << GetEnemyTypeString(BadGuy[i].type) << endl;
	}
}

bool operator == (Enemy e1,Enemy e2)
{
	if(e1.type==e2.type && e1.name==e2.name)
	{
		return true;
	}
	return false;
}

Enemy CreateRandomEnemy ()
{
	Enemy e;
	srand(time(NULL));
	e.health = rand() % 5;
	e.name = names[rand() % 6];
	int r=rand()%4;
	switch(r)
	{
	case(0): e.type = zombie; break;
	case(1): e.type = vampire; break;
	case(2): e.type = ghost; break;
	default: e.type = witch;
	}
	return e;
}

string GetEnemyTypeString(EnemyType t)
{
	switch(t)
	{
	case(0):return "zombie";
	case(1):return "vampire";
	case(2):return "ghost";
	default:return "witch";
	}
}