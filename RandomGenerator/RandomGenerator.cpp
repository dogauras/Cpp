#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "RandomGenerator.h"

using namespace std;

int count_digit(long long int num)
{
	if (num == 0) return 1;

	int count = 0;
	while (num != 0) {
		num = num / 10;
		count++;
	}
	return count;
}

int RandomGenerator::generate_random(RandomGenerator gen,int size, int s) {
	long long int mult = gen.digits[size - 1] * gen.digits[size - 2];
	string strMult = to_string(mult);
	long long zeros = 2 * s - count_digit(mult);
	if (zeros != 0) {
		strMult = string(zeros, '0').append(strMult);
	}

	//extract s number of digits from the middle
	string sub = strMult.substr(gen.s / 2, gen.s);
	return stoi(sub);
}

RandomGenerator::RandomGenerator() {
	s = 4;
	digits = new long long int[INITIAL_CAP];
	capacity = INITIAL_CAP;
	size = 2;
	digits[0] = (rand() % (9999 - 1000)) + 1000;
	digits[1] = (rand() % (9999 - 1000)) + 1000;
}

RandomGenerator::RandomGenerator(int halfS, int seed1, int seed2) {
	s = 2*halfS;
	size = 2;
	capacity = INITIAL_CAP;
	digits = new long long int[INITIAL_CAP];

	if (digits == NULL) {
		cout << "Not enough memory!" << endl;
	}

	// need to comment this out because after subtraction, we may end up with numbers with less than s digits
	/*if (count_digit(seed1) != s) {
		seed1 = (int)(rand() % (int)(pow(10, s + 1) - 1 - pow(10, s))) + (int)pow(10, s);
	}
	if (count_digit(seed2) != s) {
		seed2 = (int)(rand() % (int)(pow(10, s + 1) - 1 - pow(10, s))) + (int)pow(10, s);
	}*/

	digits[0] = seed1;
	digits[1] = seed2;
}

RandomGenerator::RandomGenerator(const RandomGenerator& random) {

	digits = new long long int[random.capacity];
	if (digits == NULL) {
		cout << "Not enough memory" << endl;
	}
	s = random.s;
	size = random.size;
	for (int i = 0; i < random.size; i++)
	{
		digits[i] = random.digits[i];
	}
	capacity = random.capacity;
}

RandomGenerator::~RandomGenerator() {
	delete[] digits;
}

bool RandomGenerator::add_random(RandomGenerator& gen, int random) {
	if (gen.size == gen.capacity) {
		int new_cap = gen.capacity + INITIAL_CAP / 2;
		long long int* temp = new long long int[new_cap]; //re-allocate memory
		gen.capacity = new_cap;
		if (temp == NULL) {
			return false;
		}
		for (int i = 0; i < gen.size; i++)
		{
			temp[i] = gen.digits[i];
		}
		delete[] gen.digits; //free the memory directions used to point at
		gen.digits = temp;
	}
	gen.digits[gen.size++] = random;
	return true;
}

bool RandomGenerator::remove_last() {
	if (size > 2) {
		digits[size - 1] = 0;
		size--;
		return true;
	}
	return false;
}

long long int RandomGenerator::operator [](int index) {
	return digits[index];
}
bool RandomGenerator::operator ==(RandomGenerator random) const{
	if (size != random.size || s != random.s) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (random.digits[i] != digits[i])
			return false;
	}
	return true;
}
bool RandomGenerator::operator !=(RandomGenerator random) const{
	return !((*this) == random);
}
RandomGenerator& RandomGenerator::operator =(const RandomGenerator random) {
	delete[] digits;

	s = random.s;
	size = random.size;
	capacity = random.capacity;
	digits = new long long int[capacity];
	for (int i = 0; i < random.size; i++) {
		digits[i] = random.digits[i];
	}
	return *this;
}

RandomGenerator RandomGenerator::operator +(RandomGenerator random) {
	if (size != random.size) {
		if (size > random.size) {
			int diff = size - random.size;
			while (diff > 0) {
				random.add_random(random,generate_random(random,random.size, random.s));
				diff--;
			}
		}
		else {
			int diff = random.size - size;
			while (diff > 0) {
				this->add_random(*this,generate_random(*this,size, s));
				diff--;
			}
		}
	}
	
	int first = 0, second = 0;
	for (int i = 0; i < 2; i++) {
		long long int addition = digits[i] + random.digits[i];
		string strAdd = to_string(addition);
		long long int zeros = 2 * s - count_digit(addition);
		if (zeros != 0) {
			strAdd = string(zeros, '0').append(strAdd);
		}
		//extract s number of digits from the middle
		string sub = strAdd.substr(strAdd.size() - s);
		if (i == 0) first = stoi(sub);
		else if (i == 1) second = stoi(sub);
	}

	RandomGenerator result(s/2,first,second);
	for (int i = 2; i < size; i++) {
		long long int addition = digits[i] + random.digits[i];
		string strAdd = to_string(addition);
		long long int zeros = 2 * s - count_digit(addition);
		if (zeros != 0) {
			strAdd = string(zeros, '0').append(strAdd);
		}

		//extract s number of digits from the middle
		string sub = strAdd.substr(strAdd.size() - s);
		result.add_random(result, stoi(sub));
	}
	return result;
}

RandomGenerator RandomGenerator::operator -(RandomGenerator random) {
	if (size != random.size) {
		if (size > random.size) {
			int diff = size - random.size;
			while (diff > 0) {
				random.add_random(random, generate_random(random, random.size, random.s));
				diff--;
			}
		}
		else {
			int diff = random.size - size;
			while (diff > 0) {
				this->add_random(*this, generate_random(*this, size, s));
				diff--;
			}
		}
	}

	int first = 0, second = 0;
	int count = 0;
	for (int i = 0; i < 2; i++) {
		long long int addition = abs(digits[i] - random.digits[i]);
		string strAdd = to_string(addition);
		long long int zeros = 2 * s - count_digit(addition);
		if (zeros != 0) {
			strAdd = string(zeros, '0').append(strAdd);
		}

		//extract s number of digits from the middle
		string sub = strAdd.substr(strAdd.size() - s);
		if (i == 0) first = stoi(sub);
		else if (i == 1) second = stoi(sub);
	}

	RandomGenerator result(s / 2, first, second);
	for (int i = 2; i < size; i++) {
		long long int addition = abs(digits[i] - random.digits[i]);
		string strAdd = to_string(addition);
		long long int zeros = 2 * s - count_digit(addition);
		if (zeros != 0) {
			strAdd = string(zeros, '0').append(strAdd);
		}
		//extract s number of digits from the middle
		string sub = strAdd.substr(strAdd.size() - s);
		result.add_random(result, stoi(sub));
	}
	return result;
}
RandomGenerator RandomGenerator::operator *(RandomGenerator random) {
	if (size != random.size) {
		if (size > random.size) {
			int diff = size - random.size;
			while (diff > 0) {
				random.add_random(random, generate_random(random, random.size, random.s));
				diff--;
			}
		}
		else {
			int diff = random.size - size;
			while (diff > 0) {
				this->add_random(*this, generate_random(*this, size, s));
				diff--;
			}
		}
	}

	int first = 0, second = 0;
	for (int i = 0; i < 2; i++) {
		long long int addition = digits[i] * random.digits[i];
		string strAdd = to_string(addition);
		long long int zeros = 2 * s - count_digit(addition);
		if (zeros != 0) {
			strAdd = string(zeros, '0').append(strAdd);
		}

		//extract s number of digits from the middle
		string sub = strAdd.substr(s / 2, s);
		if (i == 0) first = stoi(sub);
		else if (i == 1) second = stoi(sub);
	}

	RandomGenerator result(s / 2, first, second);
	for (int i = 2; i < size; i++) {
		long long int addition = digits[i] * random.digits[i];
		string strAdd = to_string(addition);
		long long int zeros = 2 * s - count_digit(addition);
		if (zeros != 0) {
			strAdd = string(zeros, '0').append(strAdd);
		}

		//extract s number of digits from the middle
		string sub = strAdd.substr(s / 2, s);
		result.add_random(result, stoi(sub));
	}
	return result;
}
RandomGenerator RandomGenerator::operator +=(RandomGenerator random) {
	*this = *this + random;
	return *this;
}
RandomGenerator RandomGenerator::operator -=(RandomGenerator random) {
	*this = *this - random;
	return *this;
}
RandomGenerator RandomGenerator::operator *=(RandomGenerator random) {
	*this = *this * random;
	return *this;
}

//prefix
RandomGenerator RandomGenerator::operator ++() {
	//assuming that there will always be at least two elements in random numbers array
	this->add_random(*this,generate_random(*this,size, s));
	return *this;
}

//postfix
RandomGenerator RandomGenerator::operator ++(int) {
	RandomGenerator old = *this;
	++(* this); //use prefix implementation
	return old;
}

//prefix
RandomGenerator RandomGenerator::operator --() {
	this->remove_last();
	return *this;
}

//postfix
RandomGenerator RandomGenerator::operator --(int) {
	RandomGenerator old = *this;
	--(*this);
	return old;
}

ostream& operator <<(ostream& out, RandomGenerator random) {
	for (int i = 0; i < random.size - 1; i++) {
		out << random.digits[i] << ",";
	}
	out << random.digits[random.size - 1];
	return out;
}


