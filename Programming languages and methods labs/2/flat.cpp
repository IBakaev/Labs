#include "flat.h"

using namespace std;


string ToStr(Flat a)
{
	string B = "";
	B = "Количество комнат: " + to_string(a.AmountOfRooms) + "\nЭтаж: " + to_string(a.Floor) + "\nКоличество жильцов: " + to_string(a.AmountOfTenant) + "\nAдрес: " + a.Adres.Street + " " + a.Adres.NumberOfHouse + "\n";
	a.Square == 1 ? B += "Общая Площадь" : B += "Жилая площадь";
	B += "\n\n";

	return B;
}

bool CreateAdress(fstream &filename, Flat &A) 
{
	if (filename.eof())
		return 0;
	else 
	{ 

		filename >> A.Adres.Street;
		filename >> A.Adres.NumberOfHouse;
		filename >> A.Adres.NumberOfFlat;
		filename >> A.AmountOfRooms;
		filename >> A.AmountOfTenant;
		filename >> A.Floor;
		filename >> A.Square;

		if (filename.eof())
			return 0;

		return 1;
	}
}


bool Comapare(Flat a, Flat b)
{
	return  a.Adres.Street.compare(a.Adres.Street)<0 ;
}