
#ifndef TREE_H
#define TREE_H

struct Node
{
	int data;
	Node *left;
	Node *right;
};

typedef Node *TTree;

void initTree(TTree &root);

void initTree(TTree &root, int elem);

bool isEmpty(TTree &root);

void setRootData(TTree &root, int elem);

void LeftSon(TTree root, int elem);

void RightSon(TTree root, int elem);

void createTree(TTree &root);

void inorderIterative(TTree root, int &e);

int findPlace(TTree root, int elem, TTree &cur);

void printTree(TTree root, int level);


#endif 