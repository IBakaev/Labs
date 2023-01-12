#include "list.h"

using namespace std;

void initList(Tlist &list) {
	list = NULL;
}

bool isEmpty(Tlist list) {
	return list == NULL;
}

void AddToHead(Tlist &list, Flat elem) {
	Tlist p = new Node;
	p->data = elem;
	p->next = list;
	list = p;
}

void AddAfterNode(Tlist pNode, Flat elem) {
	Tlist p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}

void deleteFromHead(Tlist &list) {
	Tlist p = list;
	list = list->next;
	p->next = 0;
	delete p;
	p = NULL;

}

void deleteAfterNode(Tlist pNode) {
	Tlist p = pNode->next;
	pNode->next = p->next;
	p->next = 0;
	delete p;

}

Tlist FindPlace(Tlist list, Flat elem) {
	Tlist current = list;
	while ((current->next != 0) && (Comapare(current->data,elem)))
		current = current->next;
	return current;
}

void CreatebyOrderFromFile(Tlist &list, string filename) {
	initList(list);
	Flat A;
	fstream in(filename);
	
	while (CreateAdress(in,A)) 
	{

		if (isEmpty(list)|| Comapare(A,list->data))
			AddToHead(list, A);
		else 
		{
			Tlist place = FindPlace(list, A);
			AddAfterNode(place, A);
		}
	}


	in.close();
}



void ClearList(Tlist &list) {
	while (isEmpty(list) != 0)
		deleteFromHead(list);
}

void PrintList(Tlist list) {
	Tlist current = list;
	while (current != NULL) {
		cout << ToStr(current->data);
		current = current->next;
	}
	cout << endl;
}


void DelCur(Tlist &list, string street, string NumOfHouse)
{
	if ((list->data.Adres.Street == street) && (list->data.Adres.NumberOfHouse == NumOfHouse))
		deleteFromHead(list);
	Tlist cur = list;
	while (cur->next!=NULL)
	{
		if (cur->next->data.Adres.Street == street && cur->next->data.Adres.NumberOfHouse == NumOfHouse)
		{
		deleteAfterNode(cur);
		cout << "1";
	    }
		else
			cur = cur->next;
	}


}