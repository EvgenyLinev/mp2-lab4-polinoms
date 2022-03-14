#include "pch.h"
#include "../polinoms/polynoms.cpp"
#include <iostream>
using namespace std;

TEST(List, can_insert_element_front)
{
	List <int> test1;
	List <int> test2;
	int k;
	k = 2;
	test1.insert_front(k);
	test2.insert_front(k);
	k = 3;
	test1.insert_front(k);
	test2.insert_front(k);
	EXPECT_EQ(test1, test2);
}

TEST(List, can_insert_element_at_end)
{
	List <int> test1;
	List <int> test2;
	test1.insert_front(2);
	test2.insert_at_end(3);
	test1.insert_front(3);
	test2.insert_at_end(2);
	EXPECT_EQ(test1, test2);
}

TEST(List, can_insert_element_after_element)
{
	List <int> test1;
	List <int> test2;
	test1.insert_front(4);
	test1.insert_front(2);
	test1.insert_front(3);
	test2.insert_front(4);
	test2.insert_front(3);
	Node<int>* a = test2.head;
	test2.insert_after(a, 2);
	EXPECT_EQ(test1, test2);
}

TEST(List, can_delete_element)
{
	List <int> test1;
	List <int> test2;
	test1.insert_front(0);
	test1.insert_front(3);
	test2.insert_front(0);
	test2.insert_front(2);
	test2.insert_front(3);
	test2.del(2);
	EXPECT_EQ(test1, test2);
}
TEST(Polinoms, can_insert_element)
{
	Polinoms a;
	ASSERT_NO_THROW(a.Set(2, 2, 2, 2));
}
TEST(Polinoms, can_insert_element_wiht_sorts)
{
	Polinoms a;
	Polinoms b;
	a.Set(-1, 1, 1, 1);
	a.Set(2, 2, 2, 2);
	cout << endl;
	a.Print();
	Mon tmp;
	tmp.Value = -1;
	tmp.degree = 10101;
	b.Insert(tmp);
	tmp.Value = 2;
	tmp.degree = 20202;
	b.Insert(tmp);
	cout << endl;
	b.Print();
	cout << endl;
	EXPECT_EQ(a, b);
}
TEST(Polinoms, cant_insert_element_with_negative_degree_of_X)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, -1, 1, 1));
}
TEST(Polinoms, cant_insert_element_with_negative_degree_of_Y)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, 1, -1, 1));
}
TEST(Polinoms, cant_insert_element_with_negative_degree_of_Z)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, 1, 1, -1));
}
TEST(Polinoms, cant_insert_element_with_not_int_degree_of_X)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, 1.1, 1, 1));
}
TEST(Polinoms, cant_insert_element_with_not_int_degree_of_Y)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, 1, 1.1, 1));
}
TEST(Polinoms, cant_insert_element_with_not_int_degree_of_Z)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, 1, 1, 1.1));
}
TEST(Polinoms, cant_insert_element_with_too_large_degree_of_X)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, 100, 1, 1));
}
TEST(Polinoms, cant_insert_element_with_too_large_degree_of_Y)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, 1, 100, 1));
}
TEST(Polinoms, cant_insert_element_with_too_large_degree_of_Z)
{
	Polinoms a;
	ASSERT_ANY_THROW(a.Set(1, 1, 1, 100));
}
TEST(Polinoms, can_add_polinom)
{
	Polinoms a;
	Polinoms b;
	Polinoms res;
	Mon tmp;
	tmp.Value = 1;
	tmp.degree = 1;
	a.Insert(tmp);
	b.Insert(tmp);
	tmp.degree = 3;
	a.Insert(tmp);
	b.Insert(tmp);
	tmp.Value = 2;
	tmp.degree = 1;
	res.Insert(tmp);
	tmp.degree = 3;
	res.Insert(tmp);
	EXPECT_EQ(res, a + b);
}
TEST(Polinoms, add_associativity)
{
	Polinoms a;
	Polinoms b;
	Mon tmp;
	tmp.Value = 1;
	tmp.degree = 1;
	a.Insert(tmp);
	b.Insert(tmp);
	tmp.degree = 3;
	a.Insert(tmp);
	b.Insert(tmp);

	EXPECT_EQ(b + a, a + b);
}
TEST(Polinoms, delete_zero_element_in_add)
{
	Polinoms a;
	Polinoms b;
	Polinoms res;
	a.Set(1, 1, 1, 1);
	a.Set(1, 1, 1, 2);
	b.Set(-1, 1, 1, 2);
	b.Set(-1, 1, 1, 4);
	res.Set(1, 1, 1, 1);
	res.Set(-1, 1, 1, 4);
	EXPECT_EQ(res, a + b);
}
TEST(Polinoms, can_substract_polinom)
{
	Polinoms a;
	Polinoms b;
	Polinoms res;
	a.Set(1, 1, 1, 1);
	a.Set(1, 1, 1, 2);
	b.Set(-1, 1, 1, 3);
	b.Set(-1, 1, 1, 4);
	res.Set(1, 1, 1, 1);
	res.Set(1, 1, 1, 2);
	res.Set(1, 1, 1, 3);
	res.Set(1, 1, 1, 4);
	EXPECT_EQ(res, a - b);
}
TEST(Polinoms, delete_zero_element_in_subctraction)
{
	Polinoms a;
	Polinoms b;
	Polinoms res;
	a.Set(1, 1, 1, 1);
	a.Set(1, 1, 1, 2);
	b.Set(-1, 1, 1, 3);
	b.Set(1, 1, 1, 1);
	res.Set(1, 1, 1, 2);
	res.Set(1, 1, 1, 3);
	EXPECT_EQ(res, a - b);
}

TEST(Polinoms, can_mult_polinoms)
{
	Polinoms a;
	Polinoms b;
	Polinoms res;
	a.Set(1, 1, 1, 1);
	a.Set(1, 1, 1, 2);
	b.Set(-1, 1, 1, 3);
	b.Set(1, 1, 1, 1);
	res.Set(-1, 2, 2, 4);
	res.Set(1, 2, 2, 2);
	res.Set(-1, 2, 2, 5);
	res.Set(1, 2, 2, 3);

	EXPECT_EQ(res, a * b);
}

TEST(Polinoms, mult_associativity)
{
	Polinoms a;
	Polinoms b;
	a.Set(1, 1, 1, 1);
	a.Set(1, 1, 1, 2);
	b.Set(-1, 1, 1, 3);
	b.Set(1, 1, 1, 1);
	EXPECT_EQ(a * b, b * a);
}
TEST(Polinoms, mult_add_similar_terms)
{
	Polinoms a;
	Polinoms res;
	a.Set(1, 1, 1, 1);
	a.Set(1, 1, 1, 2);
	res.Set(1, 2, 2, 2);
	res.Set(1, 2, 2, 4);
	res.Set(2, 2, 2, 3);
	EXPECT_EQ(res, a * a);
}
TEST(Polinoms, can_mult_on_const)
{
	Polinoms a;
	Polinoms res;
	a.Set(1, 1, 1, 1);
	a.Set(1, 1, 1, 2);
	res.Set(2, 1, 1, 1);
	res.Set(2, 1, 1, 2);
	EXPECT_EQ(res, a * 2);
}
TEST(Polinoms, delete_polinoms_when_mult_on_zero)
{
	Polinoms a;
	Polinoms res;
	a.Set(1, 1, 1, 1);
	a.Set(1, 1, 1, 2);
	EXPECT_EQ(res, a * 0);
}
