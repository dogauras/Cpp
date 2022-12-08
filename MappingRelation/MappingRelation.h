/*
*  Author: Doga Uras
*  This class design is for the concept of Relations mapped on AxB
*/
#pragma once

#include <iostream>
#include <string>

#define MAX_CARD 1000

using namespace std;

template <typename typeA,typename typeB>
struct Pair
{
    typeA first;
    typeB second;
};

template <typename typeA,typename typeB>
class MappingRelation
{
private:
    int size;
    Pair<typeA, typeB>* elements;
    int capacity;
public:

    MappingRelation(); //default constructor
    MappingRelation(const MappingRelation<typeA,typeB>&); //copy constructor
    ~MappingRelation();//Destructor
    int cardinality();
    bool add_element(typeA, typeB);
    void remove_element(typeA, typeB);
    bool is_member(typeA, typeB);
    bool subset(MappingRelation<typeA, typeB>);
    bool operator==(MappingRelation<typeA,typeB>);
    MappingRelation<typeA,typeB>& operator=(MappingRelation<typeA,typeB>);
    MappingRelation<typeA,typeB> operator+(MappingRelation<typeA,typeB>);
    MappingRelation<typeA,typeB> operator-(MappingRelation<typeA,typeB>);
    vector<typeB> operator[](typeA);
    MappingRelation<typeA,typeB> intersection(MappingRelation<typeA, typeB>);
    bool is_function();
    MappingRelation<typeB,typeA> inverse();
    MappingRelation<typeA,typeB> combination(MappingRelation<typeA,typeB>);
    template <typename typex,typename typey> friend ostream& operator <<(ostream&, MappingRelation<typex,typey>&);
};