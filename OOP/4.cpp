#include <iostream>
#include <string>
using namespace std;
class List
{
private:
    struct Patient
    {
        string FIO;
        int numOfPolicy;
        string specialist;
        string receptionTime;
        Patient *pNextPatient;  //  Указатель на след. пациента
 
        Patient()
        {
            pNextPatient = 0;
        }
    };
public:
    Patient *pFirstPatient; //  Указатель на первого пациента
    List()
    {
        pFirstPatient = NULL;
    }
    void Add(string inFIO, int inNumOfPolicy, string inSpecialist, string inReceptionTime)
    {
        Patient* pAddingPatient = new Patient;
            pAddingPatient->FIO = inFIO;
            pAddingPatient->numOfPolicy = inNumOfPolicy;
            pAddingPatient->receptionTime = inReceptionTime;
            pAddingPatient->specialist = inSpecialist;
        
        if(pFirstPatient!=NULL) { // если список не пуст,
            GetLast()->pNextPatient = pAddingPatient;   // делаем пациента pAdd последней
        }
        else { //   если список пуст, то добавлем данные в начало списка.
            pFirstPatient = pAddingPatient;
        }
    }
    Patient* GetLast()
    {
        Patient *pCurrentPatient = pFirstPatient;   //  Указатель на очередные данные в списке.
        if(pCurrentPatient == NULL) {// Если список пуст, то возвращаем NULL.
            return NULL;
        }
        while(pCurrentPatient->pNextPatient!=NULL) {// Пока есть следующий элемент списка переводим указатель на следующий
            pCurrentPatient = pCurrentPatient->pNextPatient;
        }
        return pCurrentPatient;
    };
    void ShowAll()
    {   
        Patient *pCurrentPatient = pFirstPatient;   //  Указатель на очередные данные в списке.
        if(pCurrentPatient == NULL) {// Если список пуст, то это и напишем.
            cout << "Empty" << endl;
            getchar();
        }
        else
        {
            // Пока есть следующий элемент списка.
            do  {   // Выводим на консоль очередной элемент.
                cout << pCurrentPatient->FIO << endl <<
                        pCurrentPatient->numOfPolicy << endl <<
                        pCurrentPatient->specialist << endl <<
                        pCurrentPatient->receptionTime << endl << endl;
                }
            while((pCurrentPatient = pCurrentPatient->pNextPatient)!=NULL); // Переводим pCurr на следующий элемент в списке.
                                                                            // Если он равен NULL, то заканчиваем.
            getchar();
        }
        getchar();
    }   
 
};
 
                
 
int main()
{   
    List *pList = new List;
    pList->Add("Ivanov",1234,"Surgeon","31.10.2008 09:20");
    pList->Add("Petrov",5678,"Surgeon","31.10.2008 09:20");
    pList->Add("Sidorov",91011,"Surgeon","31.10.2008 09:40");
    pList->ShowAll();
    getchar();  //  Заглушка.
    return 0;
}
