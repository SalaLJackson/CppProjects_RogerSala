#pragma once
class myQueue
{
private:

	struct node 
	{
		int info;
		node *next; // Apunta al que està davant meu.
		node *previous; // Apunta al que està darrere meu.
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

	// Funció que retorna el size.
	int size();

	// Funció que retorna si la queue es buida.
	bool isEmpty();

	// Retorna el primer element.
	int front();

	// Retorna l'últim element.
	int back();

	// Elimina l'element en la primera posició.
	void pop();

	// Elimina l'element en l'última posició.
	void push(int element);
};

