#pragma once

class myStack
{
public:
	// Llista de nodes.
	struct node
	{
		int info;
		node *next; // Estructura recursiva: a dintre de node tenim un punter a node.
	};
	// Punter que apuntarà al primer element de la llista.
	node *s;
	// Constructor de myStack.
	myStack();
	// Constructor per copia.
	myStack(myStack &ms);
	// Constructor por elemento i numero de elementos.
	myStack(int num, int element);
	// Destructor.
	~myStack();
	// Metode pop.
	void pop();
	// Metode push.
	void push(int i);
	// Metode top.
	int top();
	// Metode size.
	int size();
	// Metode isEmpty.
	bool isEmpty();
};