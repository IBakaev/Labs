#include "list.h"

using namespace std;

void main() 
{
	setlocale(LC_ALL, "Russian");
	

	Tlist A;
	CreatebyOrderFromFile(A, "Adress.txt");
	PrintList(A);


	cout << "---------------------------------------------"<<endl;
	
	cout << "������� �������� ����� � ����� ����, ������ � ������� ����� �������\n";
	string street, flat;
	cin >> street >> flat;

	DelCur(A, street,flat);

	PrintList(A);

	system("pause");
}