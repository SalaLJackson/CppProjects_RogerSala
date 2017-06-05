#include "myMap.h"
#include <map>
#include <iostream>

int main()
{
	myMap mP;
	std::pair<int, int> p{ 1,2 };
	std::pair<int, int> p2{ 5,6 };
	std::pair<int, int> p3{ 8,7 };
	mP.insert(p);
	mP.insert(p2);
	mP.insert(p3);
	mP.insert(p3);
	mP.erase(8);
	std::cout << mP[1];
	std::cout << mP[5];
	return 0;
}