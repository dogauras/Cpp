//
// Created by dogau on 2022-11-15.
//
#include <iostream>
#include <map>
#include <set>

using namespace std;

template <typename type1, typename type2>
class Mapping{
private:
    map<type1,set<type2> > dictionary;
public:
    Mapping(); //default constructor
    Mapping(const Mapping<type1,type2>&); //copy constructor
    //~Mapping(); //destructor, not needed as there is no dynamic memory
    bool add_item(type1,type2);
    void remove_item(type1,type2);
    void clear_item(type1);
    set<type2> find_item(type1);
    set<type2> operator[](type1);
    Mapping& operator=(Mapping&);
    template<typename typex,typename typey> friend ostream& operator <<(ostream&, Mapping<typex,typey>&);
    void print_set(set<type2>); //helper function to print set
};
