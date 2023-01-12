#include <iostream>
#include <ctime>
#include <Windows.h>
#define NTHREADS 4

using namespace std;

struct param
{
	int n;
	int* array;
	int min;
};


DWORD WINAPI findMin(void* dat) 
{
	param* p = (param*)dat;
	int* localArray = p->array;
	int n = p->n;
	p->min = localArray[0];
	for (int i = 0; i < n; i++)
	{
		if (localArray[i] < p->min) 
		{
			p->min = localArray[i];
		}
	}
	return 0;
}


void main()
{
	srand(time(0));
	int n = 25;
	int nplus = n / NTHREADS;
	int nstart = 0;

	int* mass = new int[n];
	for (int i = 0; i < n; i++) 
	{
		mass[i] = rand() % 200 - 100;
	}

	for (int i = 0; i < n; i++) 
	{
		cout << mass[i] << " ";
	}

	param* pool = new param[NTHREADS];
	HANDLE thread[NTHREADS];
	param data;

	for (int i = 0; i < NTHREADS - 1; i++) 
	{
		data.array = &mass[nstart];
		data.n = nplus;
		nstart += nplus;
		*(pool + i) = data;
	}
	
	data.array = &mass[nstart];
	data.n = n - nstart;
	*(pool + NTHREADS - 1) = data;

	time_t start = time(NULL);
	time_t finish;
	time_t duration;

	for (int i = 0; i < NTHREADS; i++) 
	{
		thread[i] = CreateThread(NULL, 524288, &findMin, &pool[i], 0, NULL);
	}

	WaitForMultipleObjects(NTHREADS, thread, TRUE, INFINITE);


	int resultMin = pool[0].min;
	for (int i = 1; i < NTHREADS; i++)
	{
		if (pool[i].min < resultMin)
		{
			resultMin = pool[i].min;
		}
	}

	finish = time(NULL);
	cout << endl << "min: "<< resultMin << endl;
	
	duration = finish - start;
	cout << "programm worked for a " << duration << " sec" << endl;
	system("pause");
}