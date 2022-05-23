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
        cout << "   Меню\n 0) Вихід з програми; \n 1) Видалити останній елемент з стеку; \n 2) Очистити стек; \n 3) Продублювати останній селемент стеку; \n 4) Додати даний елемент до стеку - буль-яке число(крім тих що в меню);  \n>> ";
        cin >> value;

        switch (value)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << endl << "Виlfkbnb останній елемент стеку" << endl;
            S.POP();
            cout << endl << "Виведення стрічки" << endl;
            S.PRINT();
            break;
        }
        case 2:
        {
            cout << endl << "Очистити стек" << endl;
            S.MAKENULL();
            cout << endl << "Виведення стрічки" << endl;
            S.PRINT();
            break;
        }
        case 3:
        {
            cout << endl << "Продублювати останній елемент стеку" << endl;
            S.PUSH(S.TOP());
            cout << endl << "Виведення стрічки" << endl;
            S.PRINT();
            break;
        }
        default:
        {
            cout << endl << "Додати новий елемент до стеку" << endl;
            S.PUSH(value);
            cout << endl << "Виведення стрічки" << endl;
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
        cout << "Стек порожній!!!" << endl;
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
        cout << "Стек порожній!!!" << endl;
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
        cout << "Стек повний!!!" << endl;
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
        cout << "Стек порожній!!!" << endl;
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
