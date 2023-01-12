#include <iostream>
#include <stdexcept>
#include<stdio.h> 
#include <cmath>
using namespace std;

class Proper_fraction
{
	protected:
		int numerator, denominator, whole_part;
    public:
		
	void info()
	{   double division = numerator/denominator;
		cout << "Numerator: " << numerator << endl;
        cout << "Denominator: " << denominator << endl;
        cout << "Division result: " << division << endl;
	}	
};

class Mixed_fraction : public Proper_fraction
{	private: 
      int whole_part;
	public:
		Mixed_fraction(int n_numerator, int d_denominator, int w_whole_part)
		{
			if (d_denominator == 0) 
			{
			throw logic_error("Division by zero expected! Please enter the correct number in denominator! "); 
			}
			else 
			numerator = n_numerator;
			denominator = d_denominator;
			whole_part = w_whole_part;
		}
		
		void Mixed_to_Decimal()
		{
		int d_denominator = denominator;   
		int w_whole_part = whole_part;
		double n_numerator = w_whole_part*d_denominator+n_numerator;
		//	printf("%d/%d => %.4f\n", n_numerator, d_denominator, (double)n_numerator/d_denominator);	
			double division=n_numerator/d_denominator;
			cout<<round(division*1000)/1000;
		}
		
		
};


int main()
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	int n, d, w;
	cout << "¬ведите целую часть, числитель, знаменатель: " << endl; 
	cin >> w >> n >> d;
	Mixed_fraction fraction(n, d, w);
	cout << endl;
	fraction.info();
	fraction.Mixed_to_Decimal();
	cin.get();
	return 0;
}
