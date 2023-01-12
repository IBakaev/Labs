#include<iostream>
#include<math.h>

using namespace std;

int gcd(int a, int h)
{
	int temp;
	while (1)
	{
		temp = a % h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
}

int main()
{
	//2 простых числа
	double p = 3;
	double q = 7;
	double n = p * q;
	double count;
	double totient = (p - 1)*(q - 1);

	//Публичный ключ
	//Экспонента
	double e = 2;

	while (e<totient) {
		count = gcd(e, totient);
		if (count == 1)
			break;
		else
			e++;
	}

	//Приватный ключ
	//d для расшифровки
	double d;

	double k = 2;

	d = (1 + (k*totient)) / e;
	double msg = 12;
	double c = pow(msg, e);
	double m = pow(c, d);
	c = fmod(c, n);
	m = fmod(m, n);

	cout << "Message = " << msg;
	cout << "\n" << "p = " << p;
	cout << "\n" << "q = " << q;
	cout << "\n" << "n = pq = " << n;
	cout << "\n" << "(p - 1)*(q - 1) = " << totient;
	cout << "\n" << "e = " << e;
	cout << "\n" << "d = " << d;
	cout << "\n" << "Encrypted: " << c;
	cout << "\n" << "Original Message: " << m << endl;
	system("pause");
	return 0;
}