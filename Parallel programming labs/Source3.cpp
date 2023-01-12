#include <iostream>
#include "math.h"
#include <ctime>
#include <Windows.h>
#define NTHREADS 11

using namespace std;

int minResult = INT_MAX;
volatile long ResourceInUse = false;


struct param
{
	int n;
	int* array;
};


DWORD WINAPI findmin(void* dat)
{
	param* p = (param*)dat;
	int* localArray = p->array;
	int n = p->n;
	int localmin = localArray[0];
	for (int i = 1; i < n; i++)
	{
		if (localArray[i] < localmin)
		{
			localmin = localArray[i];
		}
	}
	while (InterlockedExchange(&ResourceInUse, true))
		Sleep(0);
	if (localmin < minResult)
	{
		minResult = localmin;
	}
	ResourceInUse = false;
	return 0;
}


void main()
{
	srand(time(0));
	int n = 20;
	int nplus = n / NTHREADS;
	int nstart = 0;

	int* newArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		newArray[i] = rand() % 199 - 100;
	}

	for (int i = 0; i < n; i++)
	{
		cout << newArray[i] << " ";
	}

	param* pool = new param[NTHREADS];
	HANDLE thread[NTHREADS];
	param data;

	for (int i = 0; i < NTHREADS - 1; i++)
	{
		data.array = &newArray[nstart];
		data.n = nplus;
		*(pool + i) = data;
		nstart += nplus;
	}

	data.array = &newArray[nstart];
	data.n = n - nstart;
	*(pool + NTHREADS - 1) = data;

	time_t start = time(NULL);
	time_t finish;
	time_t duration;

	for (int i = 0; i < NTHREADS; i++)
	{
		thread[i] = CreateThread(NULL, 0, &findmin, &pool[i], 0, NULL);
	}

	WaitForMultipleObjects(NTHREADS, thread, TRUE, INFINITE);

	finish = time(NULL);
	cout << endl << "min: " << minResult << endl;
	duration = finish - start;
	cout << "programm worked for a " << duration << " sec" << endl;
	system("pause");
}