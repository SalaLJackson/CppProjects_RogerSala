#include "Activitat 9 2 - Stack.h"

int main()
{
	myStack *ay;
	ay=new myStack(2,4);
	ay->top();
	ay->pop();
	ay->push(5);
	ay->pop();
	ay->pop();
	ay->pop();
	ay->pop();
	ay->pop();
	return 0;
}