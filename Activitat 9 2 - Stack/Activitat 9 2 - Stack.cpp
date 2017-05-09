#include "Activitat 9 2 - Stack.h"
#include <iostream>

myStack::myStack()
{

}

myStack::myStack(myStack &ms)
{

}

myStack::myStack(int numb,int el)
{

}

myStack::~myStack()
{

}

void myStack::pop()
{
	node *t = s;
	s = s->next;
	delete t;
}

void myStack::push(int i)
{
	s = new node{i,s};
}

int myStack::top()
{
	return s->info;
}

int myStack::size()
{
	
}

bool myStack::isEmpty()
{
	return s == nullptr;
}