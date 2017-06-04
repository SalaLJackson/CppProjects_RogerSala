#include "myList.h"

myList::myList()
{
	first = nullptr;
	last = nullptr;
	mySize = 0;
}

myList::myList(int f_size, int val)
{
	first = nullptr;
	last = nullptr;
	for (int i = 0; i < f_size; i++) 
	{
		push_back(val);
	}
}

myList::myList(myList &llista)
{
	first = nullptr;
	last = nullptr;
	bool isFirst = true;
	node *it=llista.first;
	while(it!=nullptr)
	{
		push_back(it->info);
		if (isFirst)
		{
			first = it;
			isFirst = false;
		}
		it->next;
	}
}

void myList::push_front(int val)
{
	node *aux = first;
	mySize++;
	first = new node{ val,nullptr,aux };
	if (mySize == 1)
	{
		last=first;
	}
}

void myList::push_back(int val)
{
	node *aux = last;
	mySize++;
	last = new node{ val,aux,nullptr };
	if(mySize==1)
	{
		first = last;
	}
}

void myList::pop_front()
{
	if (mySize != 0)
	{
		node* aux = first;
		first = first->next;
		mySize--;
		delete aux;
	}
}

void myList::pop_back()
{
	if (mySize != 0)
	{
		node* aux = last;
		last = last->prev;
		mySize--;
		delete aux;
	}
}

bool myList::empty()
{
	return mySize==0;
}

int myList::size()
{
	return mySize;
}

int myList::front()
{
	return first->info;
}

int myList::back()
{
	return last->info;
}

myList::~myList()
{
	while(!empty())
	{
		pop_back();
	}
}
