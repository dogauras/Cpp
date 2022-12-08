#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

//default constructor
Vector::Vector() {
	n = 0; //vector must at least be 2-dimensional
	directions = new double[INITIAL_CAP];
	capacity = INITIAL_CAP;
}

Vector::Vector(double* dirs, int dimension) {
	n = dimension;
	directions = new double[dimension];
	capacity = dimension;
	if (directions == NULL) {
		cout << "Not enough memory" << endl;
	}
	for (int i = 0; i < dimension; i++) {
		directions[i] = dirs[i];
	}
}

Vector::Vector(const Vector& vector) {
	directions = new double[vector.capacity];
	if (directions == NULL) {
		cout << "Not enough memory" << endl;
	}
	n = vector.n;
	for (int i = 0; i < vector.n; i++)
	{
		directions[i] = vector.directions[i];
	}
	capacity = vector.capacity;
}

Vector::~Vector() {
	delete[] directions;
}

int Vector::dimension() {
	return n;
}

bool Vector::add_dimension(double dimension) {
	if (n == capacity) {
		int new_cap = capacity + INITIAL_CAP / 2;
		double* temp = new double[new_cap]; //re-allocate memory
		capacity = new_cap;
		if (temp == NULL) {
			return false;
		}
		for (int i = 0; i < n; i++)
		{
			temp[i] = directions[i];
		}
		delete[] directions; //free the memory directions used to point at
		directions = temp;
	}
	directions[n++] = dimension;
	return true;
}

void Vector::remove_dimension(int index) {
	for (int i= index; i < n; i++) {
		if (i != n - 1)
			directions[i] = directions[i + 1];
		else
			directions[i] = 0;
	}
	n--;
}

bool Vector::insert_dimension(int index, double dimension) {
	if (n == capacity) {
		int new_cap = capacity + INITIAL_CAP / 2;
		double* temp = new double[new_cap];
		capacity = new_cap;
		for (int i = 0; i < n; i++)
		{
			temp[i] = directions[i];
		}
		delete[] directions;
		directions = temp;
	}
	for (int j = n; j >= index; --j) {
		directions[j] = directions[j - 1];
	}
	directions[index] = dimension;
	n++;
	return true;
}

double Vector::magnitude() {
	double temp = 0.0;
	for (int i = 0; i < n; i++) {
		temp = temp + pow(directions[i], 2.0);
	}
	return sqrt(temp);
}

double Vector::operator [](int i) {
	if (i >= 0 && i < n)
		return directions[i];
	else
		return -1;
}

bool Vector::operator ==(Vector vector) {
	if (n != vector.n) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		if (directions[i] != vector.directions[i]) {
			return false;
		}
	}
	return true;
}

bool Vector::operator !=(Vector vector) {
	return !(*this == vector);
}

//has to return reference since we can have multiple assignments (a = b = c)
Vector& Vector::operator =(Vector vector) {
	delete[] directions;

	n = vector.n;
	capacity = vector.capacity;
	directions = new double[capacity];
	for (int i = 0; i < n; i++) {
		directions[i] = vector.directions[i];
	}
	return *this;
}

Vector Vector::operator +(Vector vector) {
	Vector result;
	int smaller = 0, bigger = 0;
	bool isThisBigger;
	if (n < vector.n) {
		smaller = n;
		bigger = vector.n;
		isThisBigger = false;
	}
	else {
		smaller = vector.n;
		bigger = n;
		isThisBigger = true;
	}

	for (int i = 0; i < smaller; i++) {
		result.add_dimension(directions[i] + vector.directions[i]);
	}

	if (isThisBigger) {
		for (int j = smaller; j < bigger; j++) {
			result.add_dimension(this->directions[j]);
		}
	}
	else {
		for (int j = smaller; j < bigger; j++) {
			result.add_dimension(vector.directions[j]);
		}
	}
	return result;
}
Vector Vector::operator -(Vector vector) {
	Vector result;
	int smaller = 0, bigger = 0;
	bool isThisBigger;
	if (n < vector.n) {
		smaller = n;
		bigger = vector.n;
		isThisBigger = false;
	}
	else {
		smaller = vector.n;
		bigger = n;
		isThisBigger = true;
	}

	for (int i = 0; i < smaller; i++) {
		result.add_dimension(directions[i] - vector.directions[i]);
	}

	if (isThisBigger) {
		for (int j = smaller; j < bigger; j++) {
			result.add_dimension(this->directions[j]);
		}
	}
	else {
		for (int j = smaller; j < bigger; j++) {
			result.add_dimension(vector.directions[j]);
		}
	}
	return result;
}

//vector * scalar
Vector Vector::operator *(double scalar) {
	Vector result;
	for (int i = 0; i < n; i++) {
		result.add_dimension(scalar * directions[i]);
	}
	return result;
}

Vector Vector::operator +=(Vector vector) {
	int smaller = (n < vector.n ? n : vector.n);
	for (int i = 0; i < smaller; i++) {
		this->directions[i] = this->directions[i] + vector.directions[i];
	}
	if (smaller == n) { //'this' is smaller, hence we need to add new dimensions to 'this'
		for (int i = smaller; i < vector.n; i++) {
			this->add_dimension(vector.directions[i]);
		}
	}
	return *this;
}
Vector Vector::operator -=(Vector vector) {
	int smaller = (n < vector.n ? n : vector.n);
	for (int i = 0; i < smaller; i++) {
		this->directions[i] = this->directions[i] - vector.directions[i];
	}
	if (smaller == n) { //'this' is smaller, hence we need to add new dimensions to 'this'
		for (int i = smaller; i < vector.n; i++) {
			this->add_dimension(-1 * vector.directions[i]);
		}
	}
	return *this;
}

//vector * vector
Vector Vector::operator *(Vector vector) {
	Vector result;
	int max = (vector.n > n ? vector.n : n);

	for (int i = 0; i < max; i++) {
		if (i < n && i < vector.n) {
			result.add_dimension(directions[i] * vector.directions[i]);
		}
		else {
			result.add_dimension(0);
		}
	}
	return result;
}

//This function is not part of the class
//since it's set to 'friend' in the header file, it has access to private members of class Vector
//'friend' is uni-directional unless you make it bi-directional
// scalar * vector
Vector operator *(double scalar, Vector vector) {
	return vector * scalar;
}

ostream& operator <<(ostream& out, Vector vector) {
	out << "(";
	for (int i = 0; i < vector.n - 1; i++) {

		out << vector.directions[i] << ",";
	}
	out << vector.directions[vector.n - 1] << ")";
	return out;
}

//Vector parameter has to be a reference otherwise the new value won't take effect
//istream& operator >>(istream& in, Vector& vector) {
//	cout << "Enter the dimension";
//	in >> vector.dimension;
//	return in;
//}