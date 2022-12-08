#pragma once

#include <iostream>
using namespace std;

#define INITIAL_CAP 10 //initial dimension

class Vector {
private:
    int capacity; //capacity of the 'dynamic' array
    int n; //current length of the vector array (n-dimension)
    double* directions; //dynamic array of doubles representing the vector directions
public:
    Vector(); //default constructor
    Vector(double*,int); 
    Vector(const Vector&); //copy constructor
    ~Vector();

    int dimension();
    bool add_dimension(double dimension);
    void remove_dimension(int index);
    bool insert_dimension(int index, double dimension);
    double magnitude();
    double operator [](int);
    bool operator ==(Vector);
    bool operator !=(Vector);
    Vector& operator =(Vector); //has to return reference since we can have multiple assignments (a = b = c)
    Vector operator +(Vector);
    Vector operator -(Vector);
    Vector operator *(double);
    Vector operator +=(Vector);
    Vector operator -=(Vector);
    friend Vector operator *(double, Vector);
    Vector operator *(Vector);
    friend ostream& operator <<(ostream&, Vector);
    //friend istream& operator >>(istream&, Vector);
};


