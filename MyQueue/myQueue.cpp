#include "myQueue.h"

myQueue::myQueue()
{
	mySize = 0;
	last = nullptr;
	first = nullptr;
}

myQueue::myQueue(int size, int num)
{
	mySize = 0;
	last = nullptr;
	first = nullptr;
	for(int i=0;i<size;i++)
	{
		push(num);
	}
}

myQueue::~myQueue()
{
	while(!isEmpty())
	{
		pop();
	}
}

int myQueue::size()
{
	return mySize;
}

bool myQueue::isEmpty()
{
	return mySize==0;
}

int myQueue::front()
{
	if (!isEmpty())
	{
		return first->info;
	}
}

int myQueue::back()
{
	if (!isEmpty())
	{
		return last->info;
	}
}

void myQueue::pop()
{
	if (!isEmpty())
	{
		node *aux = first->previous;
		delete first;
		first = aux;
		if (first != nullptr)
		{
			first->next = nullptr;
		}
		if (mySize > 0)
		{
			mySize--;
		}
	}
}

void myQueue::push(int element)
{
	node *aux = last;
	last = new node{ element,aux,nullptr };
	if(!isEmpty())
	{
		aux->previous = last;
	}
	else
	{
		first = last;
	}
	mySize++;
}
