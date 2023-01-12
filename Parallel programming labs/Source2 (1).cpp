#include <iostream>
#include "math.h"
#include <ctime>
#include <thread>
#define NTHREADS 4

using namespace std;

struct param
{
    int n;
    int* array;
};


void findMin(int* localArray, int n, int& min) 
{
	min = localArray[0];
	for (int i = 1; i < n; i++)
	{
		if (localArray[i] < min) 
		{
			min = localArray[i];
		}
	}
}


int main() 
{
    srand(time(0));
    int n = 20;
    int nplus = n / NTHREADS;
    int nstart = 0;

    int* newArray = new int[n];
    for (int i = 0; i < n; i++)
    {
        newArray[i] = rand() % 200 - 100;
    }

    for (int i = 0; i < n; i++)
    {
        cout << newArray[i] << " ";
    }

    int pool_min[NTHREADS];
    thread read[NTHREADS];
    param data[NTHREADS];

    for (int i = 0; i < NTHREADS - 1; i++)
    {
        data[i].array = &newArray[nstart];
        data[i].n = nplus;
        nstart += nplus;
    }

    data[NTHREADS - 1].array = &newArray[nstart];
    data[NTHREADS - 1].n = n - nstart;

    time_t start = time(NULL);
    time_t finish;
    time_t duration;

    for (int i = 0; i < NTHREADS; i++) {
        read[i] = thread(findMin, data[i].array, data[i].n, ref(pool_min[i]));
    }

    for (int i = 0; i < NTHREADS; i++) {
        read[i].join();
    }

	int resultMin = pool_min[0];
	
	for (int i = 1; i < NTHREADS; i++)
	{
		if (pool_min[i] < resultMin)
		{
			resultMin = pool_min[i];
		}
	}
	

	finish = time(NULL);
	cout<< endl << "min: " << resultMin << endl;

	duration = finish - start;
    cout << "programm worked for a " << duration << " sec" << endl;
	system("pause");
    return 0;
}