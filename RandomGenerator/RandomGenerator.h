#pragma once

#include <iostream>
#define INITIAL_CAP 10

using namespace std;

class RandomGenerator {
private:
	int s;
	int capacity;
    int size;
	long long int* digits;
public:
	RandomGenerator(); //default constructor
	RandomGenerator(int, int, int);
	RandomGenerator(const RandomGenerator&); //copy constructor
	~RandomGenerator();

    bool add_random(RandomGenerator&,int);
    bool remove_last();
    int generate_random(RandomGenerator, int, int);
    long long int operator [](int);
    bool operator ==(RandomGenerator) const;
    bool operator !=(RandomGenerator) const;
    RandomGenerator& operator =(const RandomGenerator); //has to return reference since we can have multiple assignments (a = b = c)
    RandomGenerator operator +(RandomGenerator);
    RandomGenerator operator -(RandomGenerator);
    RandomGenerator operator *(RandomGenerator);
    RandomGenerator operator +=(RandomGenerator);
    RandomGenerator operator -=(RandomGenerator);
    RandomGenerator operator *=(RandomGenerator);
    RandomGenerator operator ++(); //prefix increment
    RandomGenerator operator ++(int); //postfix increment
    RandomGenerator operator --(); //prefix decrement
    RandomGenerator operator --(int); //postfix decrement
    friend ostream& operator <<(ostream&, RandomGenerator);
};
