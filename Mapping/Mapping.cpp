//
// Created by dogau on 2022-11-15.
//

#include <iostream>
#include <set>
#include "Mapping.h"

using namespace std;

template <typename type1, typename type2>
Mapping<type1, type2>::Mapping() {
    //dictionary = new map<type1, set<type2> >;
}

template <typename type1, typename type2>
Mapping<type1, type2>::Mapping(const Mapping<type1,type2>& map) {
    dictionary = map.dictionary;
}

template <typename type1, typename type2>
bool Mapping<type1, type2>::add_item(type1 key,type2 value){
    //check if key already exists
    if(dictionary.find(key) != dictionary.end()){
        dictionary.find(key)->second.insert(value); //insert value to the set
    }
    else { //add a new entry to the dictionary
        set<type2> empty = {value};
        dictionary[key] = empty;
    }
    return true;
}

template <typename type1, typename type2>
void Mapping<type1, type2>::remove_item(type1 key,type2 value){
    //check if key exists in the dictionary
    if(dictionary.find(key) != dictionary.end()){
        dictionary.find(key)->second.erase(value); //remove value from the associated set
        if( dictionary.find(key)->second.size() == 0){//remove key from dict if it is no longer associated with a value (empty set)
            dictionary.erase(key);
        }
    }
}

template <typename type1, typename type2>
void Mapping<type1, type2>::clear_item(type1 key){
    //removes the key,value pair if the key exists in the dictionary
    if(dictionary.find(key) != dictionary.end()){
        dictionary.erase(key);
    }
}

template <typename type1, typename type2>
set<type2> Mapping<type1, type2>::find_item(type1 key) {
    if(dictionary.find(key) != dictionary.end()){
        //return the set associated with key
        return dictionary.find(key)->second;
    }
    return set<type2>{}; //empty set if key does not exist in dictionary
}

template <typename type1, typename type2>
set<type2> Mapping<type1, type2>::operator[](type1 key){
    return find_item(key);
}

template <typename type1, typename type2>
Mapping<type1, type2>& Mapping<type1, type2>::operator=(Mapping& map){
    dictionary = map.dictionary;
    return *this;
}

template <typename typex,typename typey>
ostream& operator <<(ostream& out, Mapping<typex,typey>& map){
    int i=0,j;
    out << "[";
    for (auto it = map.dictionary.begin(); it != map.dictionary.end(); ++it) {
        out << it->first << ": {";
        i++;
        j = 0;
        for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1){
            cout << *it1 ;
            j++;
            if(j != it->second.size())
                out << ",";
        }
        out <<  "}";
        if(i != map.dictionary.size())
            out << ", ";
    }
    out << "]" << endl;
    return out;
}

template <typename type1, typename type2>
void Mapping<type1, type2>::print_set(set<type2> ret) {
    cout << "{";
    int cur = 0;
    for (int const& val : ret){
        cout << val;
        cur++;
        if(cur != ret.size())
            cout << ",";
    }
    cout << "}" << endl;
}
