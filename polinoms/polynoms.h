#include <iostream>
using namespace std;


template <class T>

struct Node
{
	T data;
	Node<T>* next;
};

template <class T>
class List {
public:
	Node<T>* head;
	Node<T>* tail;
	List();
	void insert_front(T x);
	void insert_at_end(T x);
	void insert_after(Node<T>* x, T y);
	void del(T x);
	bool operator == (const List<T>& a) const;
};

struct Mon
{
	double Value;
	int degree;
};

class Polinoms
{
public:
	List <Mon> Polinom;
	Polinoms() {};
	void Print();
	void Insert(Mon tmp);
	void Set(double k, double x, double y, double z);
	void Set();
	bool operator == (const Polinoms a) const;
	Polinoms operator + (Polinoms a);
	Polinoms operator * (Polinoms a);
	Polinoms operator - (Polinoms a)
	{
		return (*this + a * (-1));
	}; 
	Polinoms operator* (double a)
	{
		Polinoms res;
		Node <Mon>* p;
		p = Polinom.head;
		if (a == 0)
			Polinom.head = nullptr;
		else
			while (p != nullptr)
			{
				p->data.Value = p->data.Value * a;
				res.Insert(p->data);
				p = p->next;
			}
		return res;
	};	
};