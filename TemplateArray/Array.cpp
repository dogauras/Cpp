#include <iostream>
#include "Array.h"

using namespace std;

template <typename type>
Array<type>::Array()
{
	capacity = 0;
	lowerbound = 0;
	upperbound = -1;
	dummy = 0;
	elements = NULL;
}

template <typename type>
Array<type>::Array(int n)
{
	capacity = 0;
	lowerbound = 0;
	upperbound = -1;
	dummy = 0;
	elements = new int[n + MAX_ELEM];
	if (elements == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		lowerbound = 0;
		upperbound = n - 1;
		capacity = n + MAX_ELEM;
	}
}

template <typename type>
Array<type>::Array(int lb, int ub)
{
	int n = ub - lb + 1;
	capacity = 0;
	lowerbound = 0;
	upperbound = -1;
	dummy = 0;
	elements = new int[n + MAX_ELEM];
	if (elements == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		lowerbound = lb;
		upperbound = ub;
		capacity = n + MAX_ELEM;
	}
}

template <typename type>
Array<type>::Array(const Array<type>& ar)
{
	int i;
	capacity = 0;
	lowerbound = 0;
	upperbound = -1;
	dummy = 0;
	int* temp = new int[ar.capacity];
	if (temp == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		int n = ar.upperbound - ar.lowerbound + 1;
		for (i = 0; i < n; ++i)
			temp[i] = ar.elements[i];
		lowerbound = ar.lowerbound;
		upperbound = ar.upperbound;
		capacity = ar.capacity;
		delete[] elements;
		elements = temp;
	}
}

template <typename type>
Array<type>::~Array()
{
	delete[] elements;
}

template <typename type>
bool Array<type>::add_item(type x)
{
	int i, n = upperbound - lowerbound + 1;
	if (n == capacity)
	{
		int* temp = new int[capacity + MAX_ELEM / 2];
		if (temp == NULL)
		{
			cout << "Not enough memory!" << endl;
			return false;
		}

		for (i = 0; i < n; ++i)
			temp[i] = elements[i];

		delete[] elements;
		elements = temp;
	}

	elements[n] = x;
	++upperbound;
	return true;
}

template <typename type>
bool Array<type>::insert_item(int pos, type x)
{
	if (pos < lowerbound || pos > upperbound)
	{
		cout << "Index out of range!" << endl;
		return false;
	}

	int i, n = upperbound - lowerbound + 1;
	if (n == capacity)
	{
		int* temp = new int[capacity + MAX_ELEM / 2];
		if (temp == NULL)
		{
			cout << "Not enough memory!" << endl;
			return false;
		}

		for (i = 0; i < n; ++i)
			temp[i] = elements[i];

		delete[] elements;
		elements = temp;
	}

	for (i = n; i >= pos - lowerbound; --i)
		elements[i] = elements[i - 1];

	elements[pos - lowerbound] = x;
	++upperbound;
	return true;
}

template <typename type>
void Array<type>::remove_item()
{
	if (lowerbound < upperbound)
		--upperbound;
}

template <typename type>
void Array<type>::remove_item(type item)
{
	int pos = -1;
	int n = upperbound - lowerbound + 1;
	for (int i = lowerbound; i < upperbound; i++) {
		if (elements[i-lowerbound] == item) {
			erase_item(i);
		}
	}
		
}

template <typename type>
void Array<type>::erase_item(int pos)
{
	if (pos < lowerbound || pos > upperbound)
	{
		cout << "Index out of range!" << endl;
		return;
	}

	int i, n = upperbound - lowerbound + 1;
	for (i = pos - lowerbound; i < n; ++i)
		elements[i] = elements[i + 1];

	--upperbound;
}

template <typename type>
bool Array<type>::find_item(int x, type& pos)
{
	int i;
	for (i = lowerbound; i <= upperbound; ++i)
	{
		if (elements[i - lowerbound] == x)
		{
			pos = i;
			return true;
		}
	}

	pos = lowerbound - 1;
	return false;
}

template <typename type>
Array<type>& Array<type>::operator=(Array<type>& ar)
{
	int i;
	capacity = 0;
	lowerbound = upperbound = -1;
	dummy = 0;
	int* temp = new int[ar.capacity];
	if (temp == NULL)
		cout << "Not enough memory!" << endl;
	else
	{
		int n = ar.upperbound - ar.lowerbound + 1;
		for (i = 0; i < n; ++i)
			temp[i] = ar.elements[i];
		lowerbound = ar.lowerbound;
		upperbound = ar.upperbound;
		capacity = ar.capacity;
		delete[] elements;
		elements = temp;
	}

	return *this;
}

template <typename type>
type& Array<type>::operator[](int index)
{
	if (index < lowerbound || index > upperbound)
	{
		cout << "Index out of range!" << endl;
		return dummy;
	}

	return elements[index - lowerbound];
}

template <typename typex>
ostream& operator <<(ostream& out, Array<typex>& ar) {
	int n = (ar.upperbound - ar.lowerbound);
	for (int i = 0; i < n; i++) {
		out << ar.elements[i] << ", ";
	}
	out << ar.elements[n] << endl;
	return out;
}