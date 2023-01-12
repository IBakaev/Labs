#include <string>
#include <fstream>

using namespace std;

struct Adress
{
	string Street;
	string NumberOfHouse;
	string NumberOfFlat;
};

struct  Flat
{
	int AmountOfRooms;
	int Floor;
	bool Square;  // 1 - общая 0 - жилая
	int AmountOfTenant;
	Adress Adres;
};


string ToStr(Flat a);

bool CreateAdress(fstream &filename, Flat &A);

bool Comapare(Flat a, Flat b);
