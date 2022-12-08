/*
*  Author: Doga Uras
*  This class design is for the concept of Relations mapped on AxA
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Set.h"

using namespace std;

template <typename type>
struct Pair
{
    type first;
    type second;
};

template <typename type>
class Relation
{
private:
    int size;
    Set<type> root;
    Pair<type>* elements;
    int capacity;
public:
    Relation(); //default constructor
    Relation(const Relation<type>&); //copy constructor
    ~Relation();//Destructor
    int cardinality();
    bool add_to_set(type);
    bool add_element(type,type);
    void remove_element(type,type);
    bool is_member(type,type);
    bool operator ==(Relation<type>);
    vector<type> operator[](type);
    bool subset(Relation<type>);
    bool reflexive();
    bool irreflexive();
    bool symmetric();
    bool asymmetric();
    bool transitive();
    bool is_function();
    Relation<type> inverse();
    Relation<type> combination(Relation<type>);
    Relation<type>& operator=(Relation<type>);
    template <typename typex> friend ostream& operator <<(ostream&, Relation<typex>&);
};