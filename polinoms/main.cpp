#include "polynoms.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int s, Key;
	cout << "������� �����" << endl;
	cout << "1: ������� ���������� ������ ����� �������." << endl;
	cout << "2: ����� ���������� ������ ������ ����� ��������." << endl;
	cout << "3: ��� ����� ������ ������� �������� ����������� ����� ���, ����� ������� �, � � Z." << endl;
	cout << "4: ������� ������ �� ���������� �� ����� ���� ������ 99!" << endl;
	cout << "������� ������� �������" << endl;

one:	Polinoms a;
	cout << "������� ������� � ����� ��������?" << endl;
	cin >> s;
	while (s > 0)
	{
		a.Set();
		s--;
	}
	a.Print();
	cout << endl;
two:	cout << "��� ������ �������?:" << endl;
	cout << "1:��������� �������" << endl;
	cout << "2: ������� �������" << endl;
	cout << "3: �������� �� ���������" << endl;
	cout << "4: �������� �� �������" << endl;
	cin >> Key;
	switch (Key)
	{
	case 1:
	{
		Polinoms b;
		cout << "������� ������� �� ������ ��������?  " << endl;
		cin >> s;
		while (s > 0)
		{
			b.Set();
			s--;
		}
		a = a + b;
		a.Print();
	}
	break;
	case 2:
	{
		Polinoms b;
		cout << "������� ������� �� ������ ��������?  " << endl;
		cin >> s;
		while (s > 0)
		{
			b.Set();
			s--;
		}
		b.Print();
		cout << endl;
		a = a - b;
		a.Print();
	}
	break;
	case 3:
	{
		double c;
		cout << "������� �����" << endl;
		cin >> c;
		a = a * c;
		a.Print();
	}
	break;
	case 4:
	{
		Polinoms b;
		cout << "������� ������� �� ������ ��������?" << endl;
		cin >> s;
		while (s > 0)
		{
			b.Set();
			s--;
		}
		b.Print();
		cout << endl;
		a = a * b;
		a.Print();
	}
	break;
	default:
		break;
	}
	cout << endl;
	cout << "�������� ��������� ��������" << endl;
	cout << "1. �������� � �����������" << endl;
	cout << "2. ����� �������" << endl;
	cout << "3. ��������� ������" << endl;
	cin >> Key;
	switch (Key)
	{
	case 1:
		goto one;
		break;
	case 2:
		goto two;
		break;
	default:
		break;
	}
}