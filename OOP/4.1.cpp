#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class patient_record
{
protected:

public:
	struct record
	{
		unsigned int day;
		unsigned int month;
		unsigned int year;
		unsigned int hour;
		unsigned int minute;
		string surname;
	};
	patient_record(unsigned int d_day, unsigned int m_month, unsigned int y_year, unsigned int h_hour, unsigned int m_minute, string s_surname)
	{
		record.day = d_day;
		record.month = m_month;
		record.year = y_year;
		record.hour = h_hour;
		record.minute = m_minute;
		record.surname = s_surname;
	}
	
	friend ostream& operator << (ostream &rout, patient_record record& rec) {
		rout << "Surname = " << rec.surname << " Month = " << rec.month << " Day " << rec.day << " Year " « rec.year << "Hour = " << rec.hour << "Minute = " << rec.minute << endl;
		return rout;
	}

	void info()
	{
		
	}
};

int main()
{
	patient_record rec_record(1, 2, 2018, 1, 1, "bakaev");
	cout << rec_record;
	return 0;
}
