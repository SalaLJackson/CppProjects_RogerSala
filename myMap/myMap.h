#pragma once
#include <map>
#include <iostream>
#include <vector>

class myMap
{
private:

	struct node
	{
		int key;
		int info;
		node *next;
		node *previous;
	};
	int mySize;
	node *begin;
	node *end;

public:

	// Sobrecarguem l'operador []
	int operator[](int k)
	{
		node *it = begin;
		while (it != nullptr)
		{
			if (it->key == k)
			{
				return it->info;
			}
			it = it->next;
		}
	}

	myMap();

	~myMap();

	void insert(std::pair<int, int> p);

	int size();

	bool isEmpty();

	void erase(int k);

	void clear();
};

