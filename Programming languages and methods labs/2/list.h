#include <iostream>
#include "flat.h"

struct Node {
	Flat data;
	Node *next;
};

typedef Node* Tlist;

void initList(Tlist &list);

bool isEmpty(Tlist list);

void AddToHead(Tlist &list, Flat elem);

void AddAfterNode(Tlist pNode, Flat elem);

void deleteFromHead(Tlist &list);

void deleteAfterNode(Tlist pNode);

Tlist FindPlace(Tlist list, Flat elem);

void CreatebyOrderFromFile(Tlist &list, std::string filename);

void ClearList(Tlist &list);

void PrintList(Tlist list);

void DelCur(Tlist &list, string street, string NumOfHouse);