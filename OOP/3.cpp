#include <iostream>
#include <string>
#include <stdexcept>
#include<stdio.h> 
#include <stdlib.h>
using namespace std;

class Plane {
	protected:
		string mark, model;
		double MaxSpeed, MaxHeight;
		
    public:
    	
    	
    	Plane (string m_mark, string m_model, double M_MaxSpeed, double M_MaxHeight)
    	{
    		if (M_MaxSpeed < 0 || M_MaxHeight < 0)
    		{
    			cout << ("Недопустимые значения!") << endl;
    			system("pause");
    			exit(1);
    		}
    		else
    		{
    		
    		mark = m_mark;
    		model = m_model;
    		MaxSpeed = M_MaxSpeed;
    		MaxHeight = M_MaxHeight;
    	}
    	}
        virtual void cost()
		{
			cout << "Cost: "<< MaxSpeed*1000+MaxHeight*100;
		}  
	    void info()
	    {
	    	cout << "Mark: " << mark << endl;
	    	cout << "Model: " << model << endl;
			cout << "Max. speed (km/h): " << MaxSpeed << endl;
			cout << "Max. height: " << MaxHeight << endl;
			//cout << "Cost of plane: " <<  MaxSpeed*1000+MaxHeight*100 << endl;
			cost();
			cout << endl << endl;
	    }	
};


class BomberPlane : public Plane 
{
	public : 
		BomberPlane (string m_mark, string m_model, double M_MaxSpeed, double M_MaxHeight) : Plane (m_mark, m_model, M_MaxSpeed, M_MaxHeight)
		{}
		
		void cost()
		{
			cout << "Cost: "<< 2*(MaxSpeed*1000+MaxHeight*100) << endl;
		}  
		
		
	
};

class Destroyer : public Plane 
{
	public:
		Destroyer (string m_mark, string m_model, double M_MaxSpeed, double M_MaxHeight) : Plane (m_mark, m_model, M_MaxSpeed, M_MaxHeight)
		{}
		void cost()
		{
			cout << "Cost: "<< 3*(MaxSpeed*1000+MaxHeight*100) << endl;
		}  
};

int main()
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	string m, mm; 
	double s, h;
	cout << "Введите марку, модель, максимальную скорость и максимальную высоту полета самолета: " << endl;
	cin >> m >> mm;
	cin >> s >> h;
    BomberPlane a(m, mm, s, h);
    Destroyer b(m,mm,s,h);
    Plane c(m,mm,s,h);
    Plane *a1 = &a;
    Plane *a2 = &b;
	
    a1->cost();
    a2->cost();
	return 0;
}




