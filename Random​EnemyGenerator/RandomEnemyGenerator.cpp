#include <iostream>
#include <string>
#include <ctime>
enum EnemyType { zombie, ghost, vampire, witch };

const int enemyNum = 5;

struct Enemy
{
	EnemyType type;
	int health;
	string name;
};

#include "RandomEnemyGenerator.h"
using namespace std;

void main()
{
	Enemy arr[enemyNum];
}

Enemy CreateRandomEnemy()
{
	Enemy en;
	en.type = rand() % 4;
	en.health = rand() % 100;
	en.name=
}

bool operator == (Enemy e1,Enemy e2)
{
	if(e1.name==e2.name && e1.type==e2.type)
	{
		return true;
	}
	return false;
}