#include "Activitat 9 2 - Stack.h"
#include <iostream>
#include <stack>

myStack::myStack()
{
	first = nullptr;
	mySize = 0;
}

myStack::myStack(myStack &ms)
{
	first = nullptr;
	mySize = 0;
	node *it = ms.first;
	while(it!=nullptr)
	{
		push(it->info);
		it = it->next;
	}
}

myStack::myStack(int numb,int el)
{
	first = nullptr;
	mySize = 0;
	for(int i=0;i<numb;i++)
	{
		push(el);
	}
}

myStack::~myStack()
{
	while(!isEmpty())
	{
		pop();
	}
}

void myStack::pop()
{
	if(!isEmpty())
	{
		node *aux = first->next;
		delete first;
		first = aux;
		mySize--;
	}
}

void myStack::push(int i)
{
	node* aux = first;
	first = new node{ i, nullptr };
	first->next=aux;
	mySize++;
}

int myStack::top()
{
	if (!isEmpty())
	{
		return first->info;
	}
	return 0;
}

int myStack::size()
{
	return mySize;
}

bool myStack::isEmpty()
{
	return mySize == 0;
}