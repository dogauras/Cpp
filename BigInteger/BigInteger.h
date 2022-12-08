/*
*  Author: Doga Uras
*  This class design is for the concept of an integer number in a particular base. 
*  The number could contain any number of digits in a particular base.
*/

#include <iostream>
using namespace std;

#define MAX_BASE 36 //max base BigInteger instance can have
#define MIN_BASE 2 //min base BigInteger instance can have
#define INITIAL_CAP 10 //initial capacity for digits array

class BigInteger {
private:
	int capacity; //capacity of the digits array
	int size; //number of elements in the digits array
	int base; //base of the integer
	int* digits; //dynamic array of integers representing BigInteger digits

	//private helper functions
	friend long long int convert_to_base_ten(BigInteger);
	friend BigInteger convert_from_base_ten(long long int, int);
	friend int sameBaseCompare(BigInteger, BigInteger);
	int count_digit(long long int);
	bool isInBase(string, int);
	int findSmallestBase(string);

public:
	BigInteger(); //default constructor
	BigInteger(long long int number, int base);
	BigInteger(const BigInteger&); //copy constructor
	~BigInteger(); //destructor

	int num_digits();
	bool add_digit(int digit);
	void remove_digit();
	bool insert_digit(int digit, int pos);
	friend BigInteger convert_to_base_ten_v2(BigInteger);
	int operator [](int);
	bool operator ==(BigInteger) const;
	bool operator >(BigInteger) const;
	bool operator <(BigInteger) const;
	bool operator >=(BigInteger) const;
	bool operator <=(BigInteger) const;
	bool operator !=(BigInteger) const;

	BigInteger& operator =(const BigInteger);
	BigInteger operator +(BigInteger);
	BigInteger operator -(BigInteger);
	BigInteger operator *(BigInteger);
	BigInteger operator ++(); //prefix
	BigInteger operator ++(int); //postfix
	BigInteger operator --();
	BigInteger operator --(int);
	BigInteger operator /(BigInteger);
	BigInteger operator %(BigInteger);

	friend ostream& operator <<(ostream&, BigInteger);
	friend istream& operator >>(istream&, BigInteger&);
};


