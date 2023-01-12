#include "stack.h"
#include "tree.h"

void initStack(TStack & top)
{
	top = 0;
}

bool isEmpty(TStack top)
{
	return top == 0;
}

void push(TStack & top, TTree elem)
{
	TStack p = new Node1;
	p->data = elem;
	p->next = top;
	top = p;
}

void pop(TStack &top, TTree &elem)
{
	TStack p = top;
	top = top->next;
	elem = p->data;
	p->next = 0;
	delete p;
}

