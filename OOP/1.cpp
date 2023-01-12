#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

class Date
{
protected:
unsigned short int day, month, year;
public:
Date()
{
day = -1;
month = -1;
year = -1;
}

void info()
{
cout << "Day: " << day << endl;
cout << "Month: " << month << endl;
cout << "Year: " << year << endl;
}
};

class set_Date : public Date
{
public:
set_Date(unsigned short int d_day, unsigned short int m_month, unsigned short int y_year)
{
if (d_day < 1 || d_day > 31 || m_month < 1 || m_month > 12 || y_year < 1) throw std::logic_error("ERROR. INVALID ARGUMENT!");
day = d_day;
month = m_month;
year = y_year;
}
bool Leap_Year(unsigned short int year)
{
return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0);
}
void Increase_Date()
{

if (Leap_Year(year) && (month == 2 && 29 - day<5))
{
day = 5 - (29 - day); month = month + 1;
cout << "1\n";
}
else
if (!(Leap_Year(year)) && (month == 2 && 28 - day<5))
{
month += 1; day = 0 + (5 - (28 - day));
cout << "1\n";
}
else
if (Leap_Year(year) && (month == 2 && (29 - day == 5 || 29 - day>5)))
{
day = day + 5;
cout << "1\n";
}
else
if (!(Leap_Year(year)) && (month == 2 && 28 - day == 5 || 28 - day>5))
{
day += 5;
cout << "1\n";
}
else
if (month == 1 && 31 - day<5)
{
month += 1; day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 1 && 31 - day == 5 || 31 - day>5)
{
day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 3 && 31 - day<5)
{
month += 1; day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 3 && 31 - day == 5 || 31 - day>5)
{
day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 4 && 30 - day<5)
{
month += 1; day = 0 + (5 - (30 - day));
cout << "1\n";
}
else
if (month == 4 && 30 - day == 5 || 30 - day>5)
{
day = 0 + (5 - (30 - day));
cout << "1\n";
}
else
if (month == 5 && 31 - day<5)
{
month += 1; day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 5 && 31 - day == 5 || 31 - day>5)
{
day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 6 && 30 - day<5)
{
month += 1; day = 0 + (5 - (30 - day));
cout << "1\n";
}
else
if (month == 6 && 30 - day == 5 || 30 - day>5)
{
day = 0 + (5 - (30 - day));
cout << "1\n";
}
else
if (month == 7 && 31 - day<5)
{
month += 1; day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 7 && 31 - day == 5 || 31 - day>5)
{
day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 8 && 31 - day<5)
{
month += 1; day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 8 && 31 - day == 5 || 31 - day>5)
{
day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 9 && 30 - day<5)
{
month += 1; day = 0 + (5 - (30 - day));
cout << "1\n";
}
else
if (month == 9 && 30 - day == 5 || 30 - day>5)
{
day = 0 + (5 - (30 - day));
cout << "1\n";
}
else
if (month == 10 && 31 - day<5)
{
month += 1; day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 10 && 31 - day == 5 || 31 - day>5)
{
day = 0 + (5 - (31 - day));
cout << "1\n";
}
else
if (month == 11 && 30 - day<5)
{
month += 1; day = 0 + (5 - (30 - day));
cout << "1\n";
}
else
if (month == 11 && 30 - day == 5 || 30 - day>5)
{
day = 0 + (5 - (30 - day));
cout << "1\n";
}
else
if (month == 12 && 31 - day<5)
{
month = 1;
day = 0 + (5 - (31 - day)); year = year + 1;
cout << "1\n";
}
else
if (month == 12 && (31 - day == 5 || 31 - day>5))
{
day = 0 + (5 - (31 - day));
cout << "1\n";
}

cout << "Увеличим дату на 5 дней: " << endl << "Day: " << day << endl << "Month: " << month << endl << "Year: " << year << endl;
}
};

int main()
{
setlocale(LC_ALL, "Russian_Russia.1251");
unsigned short int d, m, y;
cout << "Введите дату в формате ДД.ММ.ГГ: " << endl;
cin >> d >> m >> y;
set_Date Date(d, m, y);
cout << endl;
Date.info();
Date.Increase_Date();
system("pause");
return 0;
}
