#pragma once
class myList
{
private:


	// Els atributs de cada un dels elements de la nostra llista, per tant, cada element serà un struct node.
	struct node 
	{
		int info;
		node *prev;
		node *next;
	};

	// Atributs generals de la nostra llista. Per tant aquests van units a la llista en sí, no als seus elements.
	int mySize;
	node *first;
	node *last;

public:

	// Constructor per defecte de la nostra llista.
	myList();

	// Constructor passant el tamany i el valor que ficar a cada element de la llista.
	myList(int f_size, int val);

	// Constructor per copia.
	myList(myList &llista);

	// Ficar un element a l'inici de la llista.
	void push_front(int val);

	// Ficar un element al final de la llista.
	void push_back(int val);

	// Eliminar l'element de l'inici de la llista.
	void pop_front();

	// Eliminar l'element del final de la llista.
	void pop_back();

	// Comprovar si la llisa es buida.
	bool empty();

	// Comprovar el tamany de la llista.
	int size();

	// Comprovar l'element situat al principi de la llista.
	int front();

	// Comprovar l'últim element de la llista.
	int back();

	// Destructor de la nostra llista.
	~myList();
};

