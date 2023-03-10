#include "tree.h"
#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;


void initTree(TTree &root)
{
	root = 0;
}

void initTree(TTree &root, int elem)
{
	root = new Node;
	root->data = elem;
	root->left = 0;
	root->right = 0;
}

bool isEmpty(TTree &root)
{
	return root == 0;
}

void setRootData(TTree &root, int elem)
{
	if (isEmpty(root))
	{
		root->data = elem;
	}
	else
	{
		initTree(root, elem);
	}
}

void LeftSon(TTree root, int elem)
{
	if (isEmpty(root))
	{
		cout << "?????? ?????";
	}
	else
	{
		if (root->left)
		{
			cout << "???? ????? ????";
		}
		else
		{
			TTree p = new Node;
			p->data = elem;
			p->left = 0;
			p->right = 0;
			root->left = p;
		}
	}
}

void RightSon(TTree root, int elem)
{
	if (isEmpty(root))
	{
		cout << "?????? ?????";
	}
	else
	{
		if (root->right)
		{
			cout << "???? ?????? ????";
		}
		else
		{
			TTree p = new Node;
			p->data = elem;
			p->left = 0;
			p->right = 0;
			root->right = p;
		}
	}
}

void printTree(TTree root, int level)
{
	if (root) {
		printTree(root->left, level + 1);
		for (int i = 0; i < level; i++)  cout << "    ";
		cout << root->data << endl;
		printTree(root->right, level + 1);
	}
}

int findPlace(TTree root, int elem, TTree &cur)
{
	while (cur)
	{
		if ((cur->left) && (elem < cur->data))
		{
			cur = cur->left;
		}
		else
			if ((!cur->left) && (elem < cur->data))
			{
				return 1;
			}

		if ((cur->right) && (elem > cur->data))
		{
			cur = cur->right;
		}
		else
			if ((!cur->right) && (elem > cur->data))
				return -1;
	}
	return 0;
}

void createTree(TTree &root)
{
	ifstream file;
	file.open("Text.txt");
	if (!file.is_open())
	{
		cout << "???? ?? ??????";
	}
	else
	{
		int elem;
		while (file >> elem)
		{
			TTree cur = root;
			if (isEmpty(root))
			{
				initTree(root, elem);
			}
			else
				if (findPlace(root, elem, cur) == 1)
				{
					LeftSon(cur, elem);
				}
				else
					if (findPlace(root, elem, cur) == -1)
					{
						RightSon(cur, elem);
					}
		}
	}
}


void inorderIterative(TTree root, int &e)
{
	TStack stack;
	initStack(stack);
	TTree cur = root;
	bool done = false;
	int put = 0;
	while (!done)
	{
		if (cur != 0)
		{
			if (cur->data == e)
			{
				cout << "put: " << put << "\n";
			}
			else
			{
				put++;
			}
			push(stack, cur);
			cur = cur->left;
		}
		else
		{
			if (!isEmpty(stack))
			{
				pop(stack, cur);
				if ((cur->left) || (cur->right))
				{
					put--;
				}
				cur = cur->right;
				if (cur)
				{
					put++;
				}
			}
			else done = true;
		}
	}
}