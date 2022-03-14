#include "polynoms.h"
template <class T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
}

bool operator > (Mon a, Mon b)
{
	if (a.degree > b.degree)
		return 1;
	else return 0;
};
bool operator < (Mon a, Mon b)
{
	if (a > b)
		return 0;
	else return 1;
};
bool operator == (Mon a, Mon b)
{
	if ((b.degree == a.degree) && (b.Value == a.Value))
		return 1;
	else return 0;
};
bool operator != (Mon a, Mon b)
{
	if ((a.degree != b.degree) && (a.Value != b.Value))
		return 1;
	else return 0;
};

template <class T>
void List<T>::insert_front(T x)
{
	Node<T>* a = new Node<T>;
	a->data = x;
	if (head == nullptr)
	{
		a->next = nullptr;
		tail = a;
	}
	else
	{
		a->next = head;
	}
	head = a;
}

template <class T>
void List<T>::insert_at_end(T x)
{
	Node<T>* a = new Node<T>;
	Node<T>* tmp = head;
	a->data = x;
	if (head == nullptr)
	{
		a->next = nullptr;
		head = a;
	}
	else
	{
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		a->next = nullptr;
		tmp->next = a;
	}
	tail = a;
}

template <class T>
void List<T>::insert_after(Node<T>* x, T y)
{
	Node<T>* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == x->data)
		{
			Node<T>* a = new Node<T>;
			a->data = y;
			a->next = tmp->next;
			tmp->next = a;
			return;
		}
		tmp = tmp->next;
	}
}

template <class T>
void List<T>::del(T x)
{
	if (head == nullptr)
	{
		return;
	}
	Node<T>* a = head;
	while (a->next != nullptr)
	{
		if (head->data == x)
		{
			head = head->next;
		}
		else if (a->next->data == x)
		{
			a->next = a->next->next;
			if (a->next == nullptr)
				break;
		}
		a = a->next;
	}
	if (a->data == x)
		del(x);
}

template <class T>
bool List<T>::operator == (const List<T>& a) const
{
	Node <T>* x = head, * y = a.head;
	while ((x != nullptr) && (y != nullptr))
	{
		if (x->data == y->data)
		{
			x = x->next;
			y = y->next;
		}
		else return 0;
	}
	if ((x != nullptr) || (y != nullptr))
		return 0;
	else return 1;
}


Mon operator * (Mon a, Mon b)
{
	setlocale(LC_ALL, "Russian");
	Mon res;
	res.Value = a.Value * b.Value;
	res.degree = a.degree + b.degree;
	int d1, d2;
	d1 = a.degree;
	d2 = b.degree;
	int t = d1 % 10 + d2 % 10;
	if (t < 100)
	{
		d1 = d1 / 100;
		d2 = d2 / 100;
		t = d1 % 100 + d2 % 100;
		if (t < 100)
		{
			d1 = d1 / 100;
			d2 = d2 / 100;
			t = d1 + d2;
			if (t < 100)
			{
			}
			else throw "Степень Y слишком большая";
		}
		else throw "Степень X слишком большая";
	}
	else throw "Степень Z слишком большая";
	return res;
};

Mon operator + (Mon a, Mon b)
{
	setlocale(LC_ALL, "Russian");
	Mon res;
	if (a.degree == b.degree)
	{
		res.degree = a.degree;
		res.Value = a.Value + b.Value;
	}
	else throw "Это не моном";
	return res;
}

void Polinoms::Print()
{
	Node <Mon>* tmp;
	int x, y, z, deg;
	tmp = Polinom.head;
	while (tmp != nullptr)
	{
		if (tmp->data.degree == 0)
		{
			cout << tmp->data.Value;
			if (tmp->next != nullptr)
				cout << " + ";
		}
		else
		{
			deg = tmp->data.degree;
			z = deg % 100;
			deg = deg / 100;
			y = deg % 100;
			deg = deg / 100;
			x = deg;
			cout << tmp->data.Value << "*x^" << x << "*y^" << y << "*z^" << z;
			if (tmp->next != nullptr)
				cout << " + ";
		}
		tmp = tmp->next;
	}
};
 
void Polinoms::Insert(Mon tmp)
{
	if (tmp.Value != 0)
	{
		Node <Mon>* a = Polinom.head;
		if (a == nullptr)
			Polinom.insert_front(tmp);
		else
		{

			if (a == Polinom.head)
			{
				if (a->data.degree < tmp.degree)
					Polinom.insert_front(tmp);
				else
					if (a->data.degree == tmp.degree)
					{
						a->data.Value += tmp.Value;
					}
					else goto e;
			}
			else
				e:				while (a != nullptr)
			{
				if (a->next == nullptr)
				{
					Polinom.insert_at_end(tmp);
					break;
				}
				else if (a->next->data.degree < tmp.degree)
				{
					Polinom.insert_after(a, tmp);
					break;
				}
				else
					if (a->next->data.degree == tmp.degree)
					{
						a->next->data.Value += tmp.Value;
						break;
					}
					else a = a->next;
			}
		}
	}
};

void Polinoms::Set(double k, double x, double y, double z)
{
	setlocale(LC_ALL, "Russian");
	Mon n;
	n.Value = k;
	if (x > 99)
		throw "Степень X слишком большая";
	else if ((x != (int)x) || (x < 0))
		throw "Неверная степень X";
	else
		n.degree = (int)x * 10000;
	if (y > 99)
		throw "Степень Y слишком большая";
	else if ((y != (int)y) || (y < 0))
		throw "Неверная степень Y";
	else
		n.degree += (int)y * 100;
	if (z > 99)
		throw "Степень Z слишком большая";
	else if ((z != (int)z) || (z < 0))
		throw "Неверная степень Z";
	else
		n.degree += (int)z;
	Insert(n);
};

void Polinoms::Set()
{
	setlocale(LC_ALL, "Russian");
	Mon tmp;
	double k;
	cout << "Введите коэффициент" << endl;
	cin >> tmp.Value;
	cout << "Введите степени X, Y и Z" << endl;
	cin >> k;
	if (k > 99)
		throw "Степень X слишком большая";
	else if ((k != (int)k) || (k < 0))
		throw "Неверная степень X";
	else
		tmp.degree = (int)k * 10000;
	cin >> k;
	if (k > 99)
		throw "Степень Y слишком большая";
	else if ((k != (int)k) || (k < 0))
		throw "Неверная степень Y";
	else
		tmp.degree += (int)k * 100;
	cin >> k;
	if (k > 99)
		throw "Степень Z слишком большая";
	else if ((k != (int)k) || (k < 0))
		throw "Неверная степень Z";
	else
		tmp.degree += (int)k;
	Insert(tmp);
}

bool Polinoms::operator == (const Polinoms a) const
{
	if (Polinom == a.Polinom)
		return 1;
	else return 0;
}

Polinoms Polinoms::operator + (Polinoms a)
{
	Polinoms res;
	Node <Mon>* x = Polinom.head;
	Node <Mon>* y = a.Polinom.head;

	while ((x != nullptr) && (y != nullptr))
	{
		if (x->data > y->data)
		{
			res.Polinom.insert_at_end(x->data);
			x = x->next;
		}
		else if (y->data > x->data)
		{
			res.Polinom.insert_at_end(y->data);
			y = y->next;
		}
		else
		{
			res.Polinom.insert_at_end(y->data + x->data);
			x = x->next;
			y = y->next;
		}
	}
	if ((x == nullptr) && (y != nullptr))
	{
		while (y != nullptr)
		{
			res.Polinom.insert_at_end(y->data);
			y = y->next;
		}
	}
	else if ((y == nullptr) && (x != nullptr))
	{
		while (x != nullptr)
		{
			res.Polinom.insert_at_end(x->data);
			x = x->next;
		}
	}

	x = res.Polinom.head;
	while (x != nullptr)
	{
		if (x->data.Value == 0)
		{
			res.Polinom.del(x->data);
		}
		x = x->next;
	}
	return res;
};

Polinoms Polinoms::operator * (Polinoms a)
{
	Polinoms res;
	Node <Mon>* p1 = Polinom.head;
	Node <Mon>* p2;
	while (p1 != nullptr)
	{
		p2 = a.Polinom.head;
		while (p2 != nullptr)
		{
			res.Insert(p1->data * p2->data);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return res;
};

