#include "myMap.h"
#include <map>

myMap::myMap()
{
	mySize = 0;
	begin = nullptr;
	end = nullptr;
}

myMap::~myMap()
{
	clear();
}

void myMap::insert(std::pair<int, int> p)
{
	bool copied = false;
	node *it = begin;
	while(it!=nullptr)
	{
		if(it->key==p.first)
		{
			copied = true;
		}
		it = it->next;
	}
	if (!copied)
	{
		if (!isEmpty())
		{
			node *aux = begin;
			begin = new node{ p.first,p.second,aux,nullptr };
			aux->previous = begin;
		}
		else
		{
			begin = new node{ p.first,p.second,nullptr,nullptr };
			end = begin;
		}
		mySize++;
	}
}

int myMap::size()
{
	return mySize;
}

bool myMap::isEmpty()
{
	return mySize==0;
}

void myMap::erase(int k)
{
	if(!isEmpty())
	{
		node *it = begin;
		while(it!=nullptr)
		{
			if(k==it->key)
			{
				if(begin==it)
				{
					node *aux = begin;
					begin = it->next;
					begin->previous = nullptr;
					delete it;
					it = nullptr;
				}
				else if(end==it)
				{
					node*aux = end;
					end = it->previous;
					end->next = nullptr;
					delete it;
					it = nullptr;
				}
				else
				{
					node *auxPrev = it->previous;
					node *auxNext = it->next;
					auxPrev->next = auxNext;
					auxNext->previous = auxPrev;
					delete it;
					it = nullptr;
				}
				mySize--;
			}
			if (it != nullptr)
			{
				it = it->next;
			}
		}
	}
}

void myMap::clear()
{
	while(!isEmpty())
	{
		node *aux = begin;
		begin = begin->next;
		delete aux;
		mySize--;
	}
}
