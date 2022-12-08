/*
*  Author: Doga Uras
*  This class design is for the concept of Sets
*/
#include <iostream>
#include "Set.h"

using namespace std;

template <typename type>
Set<type>::Set()
{
    card = 0;
    capacity = 0;
    elements = new type[MAX_CARD];
    if (elements == NULL)
        cout << "Not enough memory for this set!" << endl;
    else
        capacity = MAX_CARD;
}

template <typename type>
Set<type>::Set(const Set<type>& s)
{
    int i;
    card = s.card;
    elements = new type[s.capacity];
    if (elements == NULL)
        cout << "Not enough memory!" << endl;
    else
    {
        capacity = s.capacity;
        card = s.card;


    }
    for (i = 0; i < s.card; ++i)
        elements[i] = s.elements[i];
}

template <typename type>
Set<type>& Set<type>::operator=(Set<type> s)
{
    int i;
    type* temp;
    temp = new type[s.capacity];
    if (temp == NULL)
        cout << "Not enough memory!" << endl;
    else
    {
        capacity = s.capacity;
        card = s.card;

        for (i = 0; i < s.card; ++i)
            temp[i] = s.elements[i];

        delete[] elements;
        elements = temp;
    }
    return *this;
}

template <typename type>
Set<type>::~Set()
{
    delete[] elements;
}

template <typename type>
int Set<type>::cardinality()
{
    return card;
}

template <typename type>
bool Set<type>::is_member(type x)
{
    int i;
    for (i = 0; i < card; ++i)
        if (elements[i] == x) return true;

    return false;
}

template <typename type>
type Set<type>::get_item(int index)
{
    if (index >= 0 && index < card)
        return elements[index];
    cout << "Index out of Range!" << endl;
    return 0; //just a default
}

template <typename type>
bool Set<type>::add_element(type x)
{
    int i;

    if (card >= MAX_CARD)
        return false;
    if (card == capacity)
    {
        int new_cap = capacity + MAX_CARD / 2;
        type* temp;
        temp = new type[new_cap];
        if (temp == NULL)
        {
            cout << "Not Enough Memory" << endl;
            return false;
        }

        for (i = 0; i < card; ++i)
            temp[i] = elements[i];

        delete [] elements;
        elements = temp;
        capacity = new_cap;
        ++card;
        return true;
    }

    for (i = 0; i < card; ++i)
        if (elements[i] == x) return true;

    elements[card++] = x;
    return true;
}

template <typename type>
void Set<type>::remove_element(type x)
{
    int i, p = -1;

    for (i = 0; i < card; ++i)
    {
        if (elements[i] == x)
        {
            p = i;
            break;
        }
    }

    if (p != -1)
    {
        for (i = p; i < card; ++i)
            elements[i] = elements[i + 1];
        --card;
    }
}

template <typename type>
bool Set<type>::subset(Set<type> s)
{
    int i;
    for (i = 0; i < card; ++i)
        if (!s.is_member(elements[i])) return false;

    return true;
}

template <typename type>
bool Set<type>::equal(Set<type> s)
{
    if (subset(s) && s.subset(*this))
        return true;

    return false;
}

template <typename type>
Set<type> Set<type>::Union(Set<type> s)
{
    int i;
    Set result;
    for (i = 0; i < card; ++i)
        result.add_element(elements[i]);

    for (i = 0; i < s.card; ++i)
        result.add_element(s.elements[i]);

    return result;
}

template <typename type>
Set<type> Set<type>::intersection(Set<type> s)
{
    int i;
    Set result;
    for (i = 0; i < card; ++i)
        if (s.is_member(elements[i])) result.add_element(elements[i]);

    return result;
}

template <typename type>
Set<type> Set<type>::difference(Set<type> s)
{
    int i;
    Set result;
    for (i = 0; i < card; ++i)
        if (!s.is_member(elements[i])) result.add_element(elements[i]);

    return result;
}

template <typename type>
Set<type> Set<type>::mutual_difference(Set<type> s)
{
    int i;
    Set s1 = difference(s);
    Set s2 = s.difference(*this);
    return s1.Union(s2);
}

