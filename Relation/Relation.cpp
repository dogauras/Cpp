#include <iostream>
#include "Relation.h"
#include "Set.h"

using namespace std;

//Default Constructor
Relation::Relation() {
	size = 0;
	pairs = new Pair[INITIAL_CAP];
	capacity = INITIAL_CAP;
	set = Set();
}

//Copy constructor
Relation::Relation(const Relation& rel) {
	pairs = new Pair[capacity];
	if (pairs == NULL) {
		cout << "Not enough memory" << endl;
	}
	size = rel.size;
	for (int i = 0; i < rel.size; i++)
	{
		pairs[i] = rel.pairs[i];
	}
	capacity = rel.capacity;
	set = rel.set;
}

//Destructor
Relation::~Relation() {
	delete[] pairs;
}

int Relation::cardinality() {
	return size;
}
void Relation::add_element(Pair a) {
	if (size == capacity) {
		int new_cap = capacity + INITIAL_CAP / 2;
		Pair* temp = new Pair[new_cap]; //re-allocate memory
		for (int i = 0; i < size; i++)
		{
			temp[i] = pairs[i];
		}
		delete[] pairs; //free the memory pairs used to point at
		pairs = temp;
	}
	pairs[size++] = a;
}
void Relation::remove_element(Pair a) {
	if (is_member(a)) {
		// check if element is in set
		int i = 0;
		for (i = 0; i < size; ++i) {
			if (pairs[i].first == a.first && pairs[i].second == a.second) {
				//copy values to the left
				for (int j = i; j < size-1; ++j) {
					pairs[j] = pairs[j + 1];
				}
				break;
			}
		}
		size--; //decrement size
	}
}

bool Relation::is_member(Pair a) {
	for (int i = 0; i < size; i++)
	{
		if (pairs[i].first == a.first && pairs[i].second == a.second) {
			return true;
		}
	}
	return false;
}

bool Relation::equal(Relation par) {
	for (int i = 0; i < par.size; i++) {
		if (!is_member(par.pairs[i])) {
			return false;
		}
	}

	for (int i = 0; i < size; i++) {
		if (!par.is_member(pairs[i])) {
			return false;
		}
	}
	return true;
}
bool Relation::reflexive() {
	Set temp = Set();
	for (int i = 0; i < size; i++) {
		if (pairs[i].first == pairs[i].second) {
			temp.add_element(pairs[i].first);
		}
	}
	//temp should be equal to set if it contains all elems
	if (temp.equal(set))
	{
		return true;
	}
	return false;

}
bool Relation::irreflexive() {
	for (int i = 0; i < size - 1; i++) {
		if (pairs[i].first == pairs[i].second) {
			return false;
		}
	}
	return true;
}
bool Relation::symmetric() {
	for (int i = 0; i < size; i++) {
		if (is_member(Pair{ pairs[i].second ,pairs[i].first }) != true) {
			return false;
		}
	}
	return true;
}
bool Relation::asymmetric() {
	for (int i = 0; i < size; i++) {
		if (pairs[i].first != pairs[i].second) {
			if (is_member(Pair{ pairs[i].second , pairs[i].first }) != true) {
				return true;
			}
		}
	}
	return false;
}
bool Relation::transitive() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size - 2; j++) {
			if (pairs[i].second == pairs[j].first) {
				if (is_member(Pair{ pairs[i].first , pairs[j].second }) == true) {
					return true;
				}
			}
		}
	}
	return false;
}
bool Relation::is_function() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (pairs[i].first == pairs[j].first && pairs[i].second != pairs[j].second) {
				return false;
			}
		}
	}
	return true;
}

Relation Relation::inverse() {
	Relation a;
	Pair* temp = new Pair[capacity];
	if (temp == NULL) {
		cout << "Not enough memory" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		temp[i].first = pairs[i].second;
		temp[i].second = pairs[i].first;
	}
	a.pairs = temp;
	a.size = size;
	a.capacity = capacity;
	a.set = set;
	return a;
}

Relation Relation::combination(Relation a) {

	Pair* temp = new Pair[size + a.size];
	Relation emptyRelation, retRelation;

	if (temp == NULL) {
		cout << "Not enough memory" << endl;
	}

	if (a.set.equal(a.set)) {
		return emptyRelation;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < a.size; j++)
		{
			if (pairs[i].second == a.pairs[i].first) {
				retRelation.add_element(Pair{ pairs[i].first , a.pairs[i].second });
			}
			else {
				return emptyRelation;
			}
		}
	}
	return retRelation;
}

bool Relation::add_to_set(int x)
{
	if (set.add_element(x))
		return true;
	return false;
}
