#include <iostream>
#include<Windows.h>
#include<ctime>
using namespace std;
const int number = 10;


template<typename Type>
class STACK
{
public:

    STACK()
    {
        this->MAKENULL();
    }

    void MAKENULL();
    bool EMPTY();
    void POP();
    Type TOP();
    void PUSH(Type c);
    void PRINT();


private:
    Type* arr = new Type[number];
    int top;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    STACK<int> S;

    int value = 1;

    while (value != 0)
    {
        cout << "   ����\n 0) ����� � ��������; \n 1) �������� ������� ������� � �����; \n 2) �������� ����; \n 3) ������������ ������� �������� �����; \n 4) ������ ����� ������� �� ����� - ����-��� �����(��� ��� �� � ����);  \n>> ";
        cin >> value;

        switch (value)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << endl << "��lfkbnb ������� ������� �����" << endl;
            S.POP();
            cout << endl << "��������� ������" << endl;
            S.PRINT();
            break;
        }
        case 2:
        {
            cout << endl << "�������� ����" << endl;
            S.MAKENULL();
            cout << endl << "��������� ������" << endl;
            S.PRINT();
            break;
        }
        case 3:
        {
            cout << endl << "������������ ������� ������� �����" << endl;
            S.PUSH(S.TOP());
            cout << endl << "��������� ������" << endl;
            S.PRINT();
            break;
        }
        default:
        {
            cout << endl << "������ ����� ������� �� �����" << endl;
            S.PUSH(value);
            cout << endl << "��������� ������" << endl;
            S.PRINT();
            break;
        }

        }
    }



    return 0;
}

template<typename Type>
void STACK<Type>::MAKENULL()
{
    this->top = 0;

}

template<typename Type>
bool STACK<Type>::EMPTY()
{
    if (this->top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename Type>
void STACK<Type>::POP()
{
    if (this->EMPTY())
    {
        cout << "���� �������!!!" << endl;
    }
    else
    {
        this->top--;
    }
}

template<typename Type>
Type STACK<Type>::TOP()
{
    if (this->EMPTY())
    {
        cout << "���� �������!!!" << endl;
    }
    else
    {
        return this->arr[this->top];
    }
}

template<typename Type>
void STACK<Type>::PUSH(Type c)
{
    if (this->top == number - 1)
    {
        cout << "���� ������!!!" << endl;
    }
    else
    {
        this->top++;
        this->arr[this->top] = c;
    }
}

template<typename Type>
void STACK<Type>::PRINT()
{
    if (this->EMPTY())
    {
        cout << "���� �������!!!" << endl;
    }
    else
    {
        int i = this->top;
        while (i > 0)
        {
            cout << this->arr[i] << "; ";
            i--;
        }
        cout << endl << endl;
    }
}
