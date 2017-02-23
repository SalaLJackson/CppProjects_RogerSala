#include <iostream>
#include <ctime>
#include <string>

enum Weapon{FISTS,GUN,SHOTGUN,REVOLVER,SNIPER,MACHINE_GUN,MAX};

const int ZOMB_NUM = 10;

class Zombie; // Forward Declaration.

class Player
{
public:
	Weapon weapon;
	float precision;
	int life;
	void attack(Zombie &);
	bool isAlive();
	Player(); // Constructor
};

class Zombie
{
public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;
	void attack(Player&);
	bool isAlive();
	Zombie();
};

Player::Player()
{
	weapon= static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX));
	precision = (rand() % 100)/100.0;
	life = rand() % 101;
}

Zombie::Zombie()
{
	distanceToPlayer = rand() % 181 + 20;
	speed = rand() % 21;
	damage = rand() % 21;
	life = rand() % 101;
}

bool Zombie::isAlive()
{
	return life != 0 || life > 0;
}

bool Player::isAlive()
{
	return life != 0 || life > 0;
}

void Player::attack(Zombie &z)
{
	z.life = z.life - (static_cast<int>(weapon)*precision);
}

void Zombie::attack(Player &p)
{
	if(distanceToPlayer<=0)
	{
		p.life = p.life - damage;
	}
	else
	{
		distanceToPlayer--;
	}
}

#include "TheWalkingDead.h"

void main()
{
	srand(time(nullptr));
	Player player;
	Zombie zombies[ZOMB_NUM];
	bool zombiesAreAlive;
	do{
		zombiesAreAlive = false;
		for(int i=0;i<ZOMB_NUM;i++)
		{
			if(zombies[i].isAlive()==true)
			{
				player.attack(zombies[i]);
				zombies[i].attack(player);
				zombiesAreAlive = true;
			}
		}
	} while (player.isAlive() == true && zombiesAreAlive == true);
}