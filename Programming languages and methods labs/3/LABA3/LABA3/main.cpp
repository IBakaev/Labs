#include <iostream>
#include "tree.h"
#include <fstream>
#include "stack.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "RUS");

	int e;

	TTree root;
	TTree curr;
	initTree(root);
	createTree(root);

	/*initTree(root, 1);
	LeftSon(root, 2);
	RightSon(root, 3);
	LeftSon(root->left, 4);
	RightSon(root->left, 5);
	LeftSon(root->right, 6);
	RightSon(root->right, 7);*/

	cout << "??????? ?????? ???????\n";
	cin >> e;
	inorderIterative(root, e);
	printTree(root, 0);




	system("pause");
}