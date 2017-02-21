#include <iostream>
#include <ctime>
#include <string>
using namespace std;

enum class EnemyType {zombie, vampire,ghost,witch,MAX};//Lo de MAX es un truqillo per coneixer el nombre de enums.

string names[] = { "Gruntilda","Pepe","Skel","Vlad","Mattie","Manolo"}; 

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
	srand(static_cast<unsigned>(time(nullptr)));//Srand de C++, fins ara utilitzavem el de C.
	cout << "Enemy list: " << endl;
	Enemy BadGuy[NumEnemies];
	bool correct = true;
	for (int i{ 0 }; i < NumEnemies; i++)
	{
		BadGuy[i] = createRandomEnemy();
		int j{ 0 };
		while(j < NumEnemies && correct == true)
		{
			if(BadGuy[i]==BadGuy[j] && i!=j)
			{
				i--;
				correct = false;
			}
			j++;
		}
		cout << "El nom de l'enemic numero " << i << " es " << BadGuy[i].name << " te un total de salut de " << BadGuy[i].health << " i es de tipus " << GetEnemyTypeString(BadGuy[i].type) << endl;
	}
}

//Super FOR. L'auto agafa directament el tipus que necessiti de l'array BadGuy.
/*
for(auto &enemy : BadGuy)
{
	std::cout<<enemy.name<<"please stahp"<<enemy.type;
}
*/

bool operator == (const Enemy e1,const Enemy e2)
{
	return e1.name == e2.name && e1.type == e2.type; //Com que demana un bool, puc tornar-lo així directament.
}

Enemy createRandomEnemy () //Notació lower camel case per a funcions.
{
	const int MAX_HEALTH = 100;
	Enemy e;
	e.health = rand() % MAX_HEALTH;
	e.name = names[rand() % (sizeof names / sizeof std::string)];//Gracies a aquesta divisió, aprofito el nombre de bites del struct i el dels strings, per trobar el nombre d'strings de l'struct.
	e.type = static_cast<EnemyType>(rand() % static_cast<int>(EnemyType::MAX));
	return e;
}

string GetEnemyTypeString(EnemyType t)
{
	switch(t)
	{
	case(EnemyType::zombie):return "zombie";
	case(EnemyType::vampire):return "vampire";
	case(EnemyType::ghost):return "ghost";
	default:return "witch";
	}
}