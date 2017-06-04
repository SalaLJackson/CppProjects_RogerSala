#pragma once
class myQueue
{
private:

	struct node 
	{
		int info;
		node *next; // Apunta al que est� davant meu.
		node *previous; // Apunta al que est� darrere meu.
	};
	int mySize;
	node *last;
	node *first;

public:

	// Constructor.
	myQueue();

	// Constructor per tamany i valor.
	myQueue(int size, int num);

	// Destructor.
	~myQueue();

	// Funci� que retorna el size.
	int size();

	// Funci� que retorna si la queue es buida.
	bool isEmpty();

	// Retorna el primer element.
	int front();

	// Retorna l'�ltim element.
	int back();

	// Elimina l'element en la primera posici�.
	void pop();

	// Elimina l'element en l'�ltima posici�.
	void push(int element);
};

