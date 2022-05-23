#include<iostream>
#include<windows.h>
using namespace std;
const int max_size = 10;


template<typename Type>
class QUEUE
{
public:
	QUEUE();

	void MAKENULL();
	Type FRONT();
	void ENQUEUE(Type value);
	void DEQUEUE();
	bool EMPTY();
	void Print();

private:
	Type* arr;
	int front;
	int rear;
	int element_arr;
};

template<typename Type>
QUEUE<Type>::QUEUE()
{
	this->MAKENULL();
}

template<typename Type>
void QUEUE<Type>::MAKENULL()
{
	this->arr = new Type[max_size];
	this->front = 0;
	this->rear = -1;
	this->element_arr = 0;
}

template<typename Type>
Type QUEUE<Type>::FRONT()
{
	return this->arr[this->front];
}

template<typename Type>
void QUEUE<Type>::ENQUEUE(Type value)
{
	if (this->rear == max_size - 1)
	{
		this->front += 2;
		this->rear = -1;
		this->element_arr = 0;
	}
	this->rear++;
	this->arr[this->rear] = value;
	this->element_arr++;
}

template<typename Type>
void QUEUE<Type>::DEQUEUE()
{
	if (this->EMPTY())
	{
		cout << endl << "����� � ������" << endl;
	}
	else
	{
		if (++this->front == max_size)
		{
			this->front = 0;
		}
		this->element_arr--;
	}
}

template<typename Type>
bool QUEUE<Type>::EMPTY()
{
	if (this->element_arr == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename Type>
void QUEUE<Type>::Print()
{
	if (this->EMPTY())
	{
		cout << endl << "����� � ������" << endl;
	}
	else
	{
		cout << "�����: ";

		if (this->front > this->rear)
		{
			int a = this->front;
			while (a != max_size)
			{
				cout << this->arr[a] << "; ";
				a++;
			}
			a = 0;
			while (a <= this->rear)
			{
				cout << this->arr[a] << "; ";
				a++;
			}
			cout << endl;
		}
		else if (this->rear > this->front)
		{
			for (int i = this->front; i <= this->rear; i++)
			{
				cout << this->arr[i] << "; ";
			}
			cout << endl;
		}
		else if (this->element_arr == 1)
		{
			cout << this->FRONT() << endl;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	QUEUE<int> Q;

	bool flag = true;
	while (flag)
	{
		cout << "     ���� \n 0) �����; \n 1) ��������� ������ �������� � �����;\n 2) ��������� �������� � �����;\n 3) �������� �����;\n 4) ���� �����;\n>> ";
		int a;
		cin >> a;
		switch (a)
		{
		case 0:
		{
			flag = false;
			break;
		}
		case 1:
		{
			cout << endl << endl << "��������� �������� � �����" << endl;

			int data;
			int value;
			cout << "������ ������� �������� � ����: ";
			cin >> data;
			cout << "������ ��������: " << endl;
			for (int i = 0; i < data; i++)
			{
				cout  << "[" << i + 1 << "] = ";
				cin >> value;
				Q.ENQUEUE(value);
			}
			Q.Print();
			break;
		}
		case 2:
		{
			cout << endl << endl << "��������� �������� � �����" << endl;
			Q.DEQUEUE();
			Q.Print();
			break;
		}
		case 3:
		{
			cout << endl << endl << "�������� �����" << endl;
			Q.MAKENULL();
			Q.Print();
			break;
		}
		case 4:
		{
			cout << endl << endl << "���� �����" << endl;
			Q.Print();
			break;
		}
		default:
		{
			cout << endl << "�������!" << endl << endl;
			break;
		}
		}
	}

	return 0;
}
