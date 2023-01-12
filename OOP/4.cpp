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
        Patient *pNextPatient;  //  ��������� �� ����. ��������
 
        Patient()
        {
            pNextPatient = 0;
        }
    };
public:
    Patient *pFirstPatient; //  ��������� �� ������� ��������
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
        
        if(pFirstPatient!=NULL) { // ���� ������ �� ����,
            GetLast()->pNextPatient = pAddingPatient;   // ������ �������� pAdd ���������
        }
        else { //   ���� ������ ����, �� �������� ������ � ������ ������.
            pFirstPatient = pAddingPatient;
        }
    }
    Patient* GetLast()
    {
        Patient *pCurrentPatient = pFirstPatient;   //  ��������� �� ��������� ������ � ������.
        if(pCurrentPatient == NULL) {// ���� ������ ����, �� ���������� NULL.
            return NULL;
        }
        while(pCurrentPatient->pNextPatient!=NULL) {// ���� ���� ��������� ������� ������ ��������� ��������� �� ���������
            pCurrentPatient = pCurrentPatient->pNextPatient;
        }
        return pCurrentPatient;
    };
    void ShowAll()
    {   
        Patient *pCurrentPatient = pFirstPatient;   //  ��������� �� ��������� ������ � ������.
        if(pCurrentPatient == NULL) {// ���� ������ ����, �� ��� � �������.
            cout << "Empty" << endl;
            getchar();
        }
        else
        {
            // ���� ���� ��������� ������� ������.
            do  {   // ������� �� ������� ��������� �������.
                cout << pCurrentPatient->FIO << endl <<
                        pCurrentPatient->numOfPolicy << endl <<
                        pCurrentPatient->specialist << endl <<
                        pCurrentPatient->receptionTime << endl << endl;
                }
            while((pCurrentPatient = pCurrentPatient->pNextPatient)!=NULL); // ��������� pCurr �� ��������� ������� � ������.
                                                                            // ���� �� ����� NULL, �� �����������.
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
    getchar();  //  ��������.
    return 0;
}
