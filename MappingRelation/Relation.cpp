/*
*  Author: Doga Uras
*  This class design is for the concept of Relations mapped on AxA
*/

#include <iostream>
#include <string>
#include <vector>
#include "Set.h"
#include "Relation.h"

using namespace std;

template <typename type>
Relation<type>::Relation()
{
    //Set<type> r;
    size = 0;
    capacity = 0;
    elements = new Pair<type>[MAX_CARD];
    if (elements == NULL)
        cout << "Not enough memory for this set!" << endl;
    else
        capacity = MAX_CARD;
}

template <typename type>
Relation<type>::Relation(const Relation<type>& r)
{
    int i;
    size = 0;
    capacity = 0;
    elements = new Pair<type>[r.capacity];
    if (elements == NULL)
        cout << "Not enough memory!" << endl;
    else
    {
        capacity = r.capacity;
        size = r.size;
        root = r.root;

        for (i = 0; i < r.size; ++i)
            elements[i] = r.elements[i];
    }
}

template <typename type>
Relation<type>::~Relation()
{
    delete[] elements;
}

template <typename type>
Relation<type>& Relation<type>::operator=(Relation<type> r)
{
    int i;
    Pair<type>* temp;
    size = 0;
    capacity = 0;
    temp = new Pair<type>[r.capacity];
    if (temp == NULL)
        cout << "Not enough memory!" << endl;
    else
    {
        capacity = r.capacity;
        size = r.size;
        root = r.root;

        for (i = 0; i < r.size; ++i)
            temp[i] = r.elements[i];

        delete[] elements;
        elements = temp;
    }

    return (*this);
}

template <typename type>
int Relation<type>::cardinality()
{
    return size;
}

template <typename type>
bool Relation<type>::is_member(type p1, type p2)
{
    int i;
    Pair<type> p = {p1,p2};
    for (i = 0; i < size; ++i)
        if (elements[i].first == p.first && elements[i].second == p.second) return true;

    return false;
}

template <typename type>
bool Relation<type>::add_to_set(type x)
{
    if (root.add_element(x))
        return true;
    return false;
}

template <typename type>
bool Relation<type>::add_element(type p1,type p2)
{
    int i;
    Pair<type> p {p1,p2};
    if (!root.is_member(p.first) || !root.is_member(p.second))
        return false;

    if (size == capacity)
    {
        int new_cap = capacity + MAX_CARD / 2;
        Pair<type>* temp;
        temp = new Pair<type>[new_cap];
        if (temp == NULL)
        {
            cout << "Not Enough Memory" << endl;
            return false;
        }

        for (i = 0; i < size; ++i)
            temp[i] = elements[i];

        delete[] elements;
        elements = temp;
        capacity = new_cap;
    }

    for (i = 0; i < size; ++i)
        if (elements[i].first == p.first && elements[i].second == p.second) return true;

    elements[size++] = p;
    return true;
}

template <typename type>
void Relation<type>::remove_element(type p1, type p2)
{
    int i, pos = -1;
    Pair<type> p = {p1,p2};
    for (i = 0; i < size; ++i)
    {
        if (elements[i].first == p.first && elements[i].second == p.second)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (i = pos; i < size; ++i)
            elements[i] = elements[i + 1];
        --size;
    }
}

template <typename type>
bool Relation<type>::subset(Relation<type> r)
{
    int i;
    for (i = 0; i < size; ++i)
        if (!r.is_member(elements[i].first,elements[i].second)) return false;

    return true;
}

template <typename type>
bool Relation<type>::operator ==(Relation<type> r)
{
    if (subset(r) && r.subset(*this))
        return true;

    return false;
}

template <typename type>
vector<type> Relation<type>::operator[](type elem){
    vector<type> res;
    for (int i = 0; i < size; ++i) {
        if(elements[i].first == elem){
            res.push_back(elements[i].second);
        }
    }
    return res;
}

template <typename type>
bool Relation<type>::reflexive()
{
    int i;
    for (i = 0; i < root.cardinality(); ++i)
    {
        Pair<type> p;
        p.first = p.second = root.get_item(i);
        if (!is_member(p.first,p.second))
            return false;
    }

    return true;
}

template <typename type>
bool Relation<type>::irreflexive()
{
    int i;
    for (i = 0; i < root.cardinality(); ++i)
    {
        Pair<type> p;
        p.first = p.second = root.get_item(i);
        if (is_member(p.first,p.second))
            return false;
    }

    return true;
}

template <typename type>
bool Relation<type>::symmetric()
{
    int i;
    for (i = 0; i < size; ++i)
    {
        Pair<type> p;
        p.first = elements[i].second;
        p.second = elements[i].first;
        if (!is_member(p.first,p.second))
            return false;
    }

    return true;
}

template <typename type>
bool Relation<type>::asymmetric()
{
    int i;
    for (i = 0; i < size; ++i)
    {
        if (elements[i].first != elements[i].second)
        {
            Pair<type> p;
            p.first = elements[i].second;
            p.second = elements[i].first;
            if (is_member(p.first,p.second))
                return false;
        }
    }

    return true;
}

template <typename type>
bool Relation<type>::transitive()
{
    int i, j;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            if (elements[i].second == elements[j].first)
            {
                Pair<type> p;
                p.first = elements[i].first;
                p.second = elements[j].second;
                if (!is_member(p.first,p.second))
                    return false;
            }
        }
    }

    return true;
}

template <typename type>
bool Relation<type>::is_function()
{
    int i, j;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            if (elements[i].first == elements[j].first && elements[i].second != elements[j].second)
                return false;
        }
    }

    return true;
}

template <typename type>
Relation<type> Relation<type>::inverse()
{
    int i;
    Relation<type> result;
    for (i = 0; i < root.cardinality(); ++i)
        result.add_to_set(root.get_item(i));

    for (i = 0; i < size; ++i)
    {
        Pair<type> p;
        p.first = elements[i].second;
        p.second = elements[i].first;
        result.add_element(p.first,p.second);
    }

    return result;
}

template <typename type>
Relation<type> Relation<type>::combination(Relation<type> r)
{
    int i, j;
    Relation<type> result;
    for (i = 0; i < root.cardinality(); ++i)
        result.add_to_set(root.get_item(i));

    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < r.size; ++j)
        {
            if (elements[i].second == r.elements[j].first)
            {
                Pair<type> p;
                p.first = elements[i].first;
                p.second = r.elements[j].second;
                result.add_element(p.first,p.second);
            }
        }
    }

    return result;
}

template <typename typex>
ostream& operator <<(ostream& out, Relation<typex>& relation)
{
    int i;
    /*for (int j = 0; j < relation.root.cardinality(); ++j) {
        out << relation.root.get_item(j) << ",";
    }
    out << endl;*/
    out << "{ ";
    for (i = 0; i < relation.size; ++i)
    {
        if (i != 0) out << ", ";
        out << "(" << relation.elements[i].first << ", " << relation.elements[i].second << ")";
    }
    out << " }" << endl;
    return out;
}