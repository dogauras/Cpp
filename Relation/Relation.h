#include "Set.h"
#define INITIAL_CAP 100 //initial amount of pairs

struct Pair
{
    int first;
    int second;
};

class Relation {
private:
    int size; // current length of the pairs array
    int capacity; //capacity of the 'dynamic' array
    Pair* pairs; //dynamic array of pairs
    Set set;
public:
    Relation(); //default constructor
    Relation(const Relation&); //copy constructor
    ~Relation();

    int cardinality();
    void add_element(Pair a);
    void remove_element(Pair a);
    bool is_member(Pair a);
    bool equal(Relation);
    bool reflexive();
    bool irreflexive();
    bool symmetric();
    bool asymmetric();
    bool transitive();
    bool is_function();
    Relation inverse();
    Relation combination(Relation);
    bool add_to_set(int a);
};
