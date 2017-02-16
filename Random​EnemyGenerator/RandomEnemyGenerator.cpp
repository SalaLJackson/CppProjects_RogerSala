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
	EnemyType en;
	rand() % 4;
	return en;

}