#ifndef STACK_H
#define STACK_H
#include"tree.h"

struct Node1 {
	TTree data;
	Node1 * next;
};

typedef Node1 * TStack;

void initStack(TStack &top);
bool isEmpty(TStack top);
void push(TStack &top, TTree elem);
void pop(TStack &top, TTree &elem);

#endif