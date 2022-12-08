/*
*  Author: Doga Uras
*  This class design is for the concept of Relations mapped on AxB
*/

#include <iostream>
#include <string>
#include <vector>
#include "MappingRelation.h"

using namespace std;

template <typename typeA, typename typeB>
MappingRelation<typeA,typeB>::MappingRelation(){
    size = 0;
    capacity = 0;
    elements = new Pair<typeA, typeB>[MAX_CARD];
    if (elements == NULL)
        cout << "Not enough memory for this set!" << endl;
    else
        capacity = MAX_CARD;
}

template <typename typeA, typename typeB>
MappingRelation<typeA,typeB>::MappingRelation(const MappingRelation<typeA,typeB>& r){
    size = 0;
    capacity = 0;
    elements = new Pair<typeA,typeB>[r.capacity];
    if (elements == NULL)
        cout << "Not enough memory!" << endl;
    else{
        capacity = r.capacity;
        size = r.size;

        for (int i = 0; i < r.size; ++i)
            elements[i] = r.elements[i];
    }
}

template <typename typeA,typename typeB>
MappingRelation<typeA,typeB>::~MappingRelation(){
    delete[] elements;
}

template <typename typeA,typename typeB>
int MappingRelation<typeA,typeB>::cardinality() {
    return this->size;
}

template <typename typeA,typename typeB>
bool MappingRelation<typeA,typeB>::add_element(typeA p1, typeB p2) {
    int i;
    Pair<typeA,typeB> p = {p1,p2};
    if (size == capacity){
        int new_cap = capacity + MAX_CARD / 2;
        Pair<typeA, typeB>* temp;
        temp = new Pair<typeA, typeB>[new_cap];
        if (temp == NULL){
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

template <typename typeA,typename typeB>
void MappingRelation<typeA,typeB>::remove_element(typeA p1, typeB p2) {
    int i, pos = -1;
    Pair<typeA,typeB> p = {p1,p2};
    for (i = 0; i < size; ++i){
        if (elements[i].first == p.first && elements[i].second == p.second){
            pos = i;
            break;
        }
    }
    if (pos != -1){
        for (i = pos; i < size; ++i)
            elements[i] = elements[i + 1];
        --size;
    }
}

template <typename typeA,typename typeB>
bool MappingRelation<typeA,typeB>::is_member(typeA p1, typeB p2) {
    Pair<typeA,typeB> p = {p1,p2};
    for (int i = 0; i < size; ++i)
        if (elements[i].first == p.first && elements[i].second == p.second) return true;
    return false;
}

// For getting intersection of two relations
// Important: the first variable has to be included in both sets of the two relations, otherwise it does not get added to intersection
template <typename typeA,typename typeB>
MappingRelation<typeA,typeB> MappingRelation<typeA,typeB>::intersection(MappingRelation<typeA, typeB> r) {
    MappingRelation<typeA, typeB> result;
    for (int i = 0; i < size; i++) {
        if (r.is_member(elements[i].first, elements[i].second) && !result.is_member(elements[i].first, elements[i].second)){
            result.add_element(elements[i].first, elements[i].second);
        }
    }
    return result;
}

template <typename typeA, typename typeB>
bool MappingRelation<typeA,typeB>::is_function(){
    int i, j;
    for (i = 0; i < size; ++i){
        for (j = 0; j < size; ++j){
            if (elements[i].first == elements[j].first && elements[i].second != elements[j].second)
                return false;
        }
    }
    return true;
}

// Returns the inverse of the relation
// Important: Since the types can be different (ie Relation can be defined on AxB),
// the set for the inverse will consist of the second elements
template <typename typeA, typename typeB>
MappingRelation<typeB, typeA> MappingRelation<typeA, typeB>::inverse(){
    MappingRelation<typeB, typeA> result;
    for (int i = 0; i < size; ++i){
        Pair<typeB,typeA> p;
        p.first = elements[i].second;
        p.second = elements[i].first;
        result.add_element(p.first,p.second);
    }

    return result;
}

template <typename typeA, typename typeB>
MappingRelation<typeA, typeB> MappingRelation<typeA,typeB>::combination(MappingRelation<typeA, typeB> r){
    int i, j;
    MappingRelation<typeA,typeB> result;

    //result.root = root.Union(r.root); //combination of two relations are defined on AUB

    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < r.size; ++j)
        {
            if((typeid(elements[i].second).name()) == typeid(r.elements[i].first).name()){
                if (elements[i].second == r.elements[j].first)
                {
                    Pair<typeA, typeB> p{elements[i].first, r.elements[j].second};
                    result.add_element(p.first,p.second);
                }
            }
        }
    }
    return result;
}

template <typename typeA, typename typeB>
bool MappingRelation<typeA, typeB>::subset(MappingRelation<typeA, typeB> r)
{
    for (int i = 0; i < size; ++i){
        if (!r.is_member(elements[i].first, elements[i].second)){
            return false;
        }
    }
    return true;
}

template <typename typeA, typename typeB>
bool MappingRelation<typeA, typeB>::operator==(MappingRelation<typeA, typeB> r){
    if (subset(r) && r.subset(*this))
        return true;
    return false;
}

template <typename typeA, typename typeB>
MappingRelation<typeA, typeB> MappingRelation<typeA, typeB>::operator+(MappingRelation<typeA, typeB> r){
    MappingRelation<typeA, typeB> result(*this);
    for (int i = 0; i < r.size; i++){
        if (!result.is_member(r.elements[i].first, r.elements[i].second))
            result.add_element(r.elements[i].first, r.elements[i].second);
    }
    return result;
}

template <typename typeA, typename typeB>
MappingRelation<typeA, typeB> MappingRelation<typeA, typeB>::operator-(MappingRelation<typeA, typeB> r){
    MappingRelation<typeA, typeB> result(*this);
    for (int i = 0; i < r.size; i++){
        if (result.is_member(r.elements[i].first, r.elements[i].second)){
            result.remove_element(r.elements[i].first, r.elements[i].second);
        }
    }
    return result;
}

template <typename typeA, typename typeB>
vector<typeB> MappingRelation<typeA, typeB>::operator[](typeA elem){
    vector<typeB> res;
    for (int i = 0; i < size; ++i) {
        if(elements[i].first == elem){
            res.push_back(elements[i].second);
        }
    }
    return res;
}

template <typename typeA, typename typeB>
MappingRelation<typeA,typeB>& MappingRelation<typeA, typeB>::operator=(MappingRelation<typeA, typeB> r){
    Pair<typeA, typeB>* temp;
    size = 0;
    capacity = 0;
    temp = new Pair<typeA,typeB>[r.capacity];
    if (temp == NULL)
        cout << "Not enough memory!" << endl;
    else{
        capacity = r.capacity;
        size = r.size;

        for (int i = 0; i < r.size; ++i)
            temp[i] = r.elements[i];

        delete[] elements;
        elements = temp;
    }
    return (*this);
}

template <typename typex, typename typey>
ostream& operator <<(ostream& out, MappingRelation<typex,typey>& r){
    int i;
    /*for (int j = 0; j < r.root.cardinality(); ++j) {
        out << r.root.get_item(j) << ",";
    }
    out << endl;*/
    out << "{ ";
    for (i = 0; i < r.size; ++i){
        if (i != 0) out << ", ";
        out << "(" << r.elements[i].first << ", " << r.elements[i].second << ")";
    }
    out << " }" << endl;
    return out;
}
