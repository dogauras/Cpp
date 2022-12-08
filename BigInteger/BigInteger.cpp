/*
*  Author: Doga Uras
*  This class design is for the concept of an integer number in a particular base.
*  The number could contain any number of digits in a particular base.
*/

#include <iostream>
#include <cmath>
#include <string>
#include "BigInteger.h"

using namespace std;

/* ************* HELPER FUNCTIONS ********************* */

//counts number of digits in a given integer
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

//converts Biginteger to base 10
long long int convert_to_base_ten(BigInteger bigInteger) {
	long long int result = 0;
	int power = bigInteger.size - 1;
	bool positive = bigInteger.digits[0] > 0 ? true : false;
	for (int i = 0; i < bigInteger.size; i++) {
		result += (abs(bigInteger.digits[i]) * pow(bigInteger.base, power));
		power--;
	}
	if (!positive) result = result * -1;
	return result;
}

//Converts bigInteger to another BigInteger object in base 10
BigInteger convert_to_base_ten_v2(BigInteger bigInteger) {
	int cap = bigInteger.size;
	BigInteger* result = new BigInteger[cap];
	int power = bigInteger.size - 1;
	bool positive = bigInteger.digits[0] > 0 ? true : false;
	for (int i = 0; i < bigInteger.size; i++) {
		BigInteger temp(abs(bigInteger.digits[i]) * pow(bigInteger.base, power), 10);
		result[i] = temp;
		power--;
	}
	BigInteger accumulator;
	for (int i = 0; i < cap; i++) {
		accumulator = accumulator + result[i]; //BigInteger = BigInteger + BigInteger
	}
	if (!positive) accumulator.digits[0] = accumulator.digits[0] * -1;
	delete[] result;
	return accumulator;
}

//Converts an integer from base 10 to given base
BigInteger convert_from_base_ten(long long int num, int baseGiven) {
	BigInteger result;
	if (baseGiven < MIN_BASE || baseGiven > MAX_BASE) {
		cout << "This base is not supported by BigInteger class!" << endl;
		return result; //returns number 0
	}

	bool first = true;
	bool positive = (num > 0 ? true : false);
	result.base = baseGiven;
	while (abs(num) > 0) {
		if (first) {
			result.add_digit(abs(num) % baseGiven);
		}
		else {
			result.insert_digit(abs(num) % baseGiven, 0);
		}
		first = false;
		num /= baseGiven;
	}
	if (!positive) {
		result.digits[0] = result.digits[0] * (-1);
	}

	return result;

}

/**
 * Compares two BigInteger objects that are in the same base
 * Precondition: bigInteger1 and bigInteger2 are in the same base
 *
 * @param bigInteger1 BigInteger object to compare
 * @param bigInteger2 BigInteger object in the same base as bigInteger1
 *
 * @return returns -1 if bigInteger1 < bigInteger2, 0 if bigInteger1 == bigInteger2, 1 if bigInteger1 > bigInteger2
 */
int sameBaseCompare(BigInteger bigInteger1, BigInteger bigInteger2) {

	long long int bigIntegerTen1 = 0, bigIntegerTen2 = 0;
	if (bigInteger1.digits[0] < 0 && bigInteger2.digits[0] >= 0) { //1st BigInteger is negative and 2nd is 0 or positive
		return -1;
	}
	else if (bigInteger2.digits[0] < 0 && bigInteger1.digits[0] >= 0) { //2nd BigInteger is negative and 1st is 0 or positive
		return 1;
	}
	else if (bigInteger1.digits[0] == 0 && bigInteger2.digits[0] > 0) { //1st BigInteger is 0 and 2nd is positive
		return -1;
	}
	else if (bigInteger2.digits[0] == 0 && bigInteger1.digits[0] > 0) { //2nd BigInteger is 0 and 1st is positive
		return 1;
	}
	else { //both negative or both positive
		if (bigInteger1.digits[0] < 0 && bigInteger2.digits[0] < 0) { //both negative
			if (bigInteger1.size > bigInteger2.size) {
				return -1;
			}
			else if (bigInteger2.size > bigInteger1.size) {
				return 1;
			}
			else {
				//compare two base 10 numbers
				bigIntegerTen1 = convert_to_base_ten(bigInteger1);
				bigIntegerTen2 = convert_to_base_ten(bigInteger2);
				if (bigIntegerTen1 == bigIntegerTen2) return 0;
				else if (bigIntegerTen1 > bigIntegerTen2) return 1;
				else return -1;
			}
		}
		else { //both positive
			if (bigInteger1.size < bigInteger2.size) {
				return -1;
			}
			else if (bigInteger2.size < bigInteger1.size) {
				return 1;
			}
			else {
				//compare two base 10 numbers
				bigIntegerTen1 = convert_to_base_ten(bigInteger1);
				bigIntegerTen2 = convert_to_base_ten(bigInteger2);
				if (bigIntegerTen1 == bigIntegerTen2) return 0;
				else if (bigIntegerTen1 > bigIntegerTen2) return 1;
				else return -1;
			}
		}
	}
}

//determines if a string consisting of digits is in a particular base
//return true if it is in base, false otherwise
bool isInBase(string strNum, int base) {

	// base can be in the range of [2,36]
	if (base < MIN_BASE || base > MAX_BASE) {
		return false;
	}
	else if (base <= 10) { // If base <= 10, then all digits should be from 0 to 9
		for (int i = 0; i < strNum.size(); i++)
			if (!(strNum[i] >= '0' && strNum[i] < ('0' + base)))
				return false;
	}
	// If base <= 36, then all digits should be from 0 to 9 or from 'A' to ('A' + base - 10)
	else {
		for (int i = 0; i < strNum.size(); i++) {
			if (!((strNum[i] >= '0' && strNum[i] < ('0' + base)) || (strNum[i] >= 'A' && strNum[i] < ('A' + base - 10)))) {
				return false;
			}
		}
	}
	return true;
}

// Returns the least possible base given a number as string
// may contain characters for bases > 10
int findSmallestBase(string num) {
	char max = '0';
	int base = 0;
	for (int i = 0; i < num.size(); i++) {
		if (char(num[i]) > max) {
			max = num[i];
		}
	}
	//it is an ascii char
	if (int(max) > '0' + 9) {
		base = max - 'A' + 10 + 1;
	}
	else { //it is a number between 0 and 9
		base = max - '0' + 1;
	}
	return base;
}
/* ************* HELPER FUNCTIONS ********************* */

/**
 * Default constructor
 */
BigInteger::BigInteger() {
	digits = new int[INITIAL_CAP];
	capacity = INITIAL_CAP;
	size = 1;
	digits[0] = 0; //initialize the number to 0
	base = 10;
}

/**
 * Constructor
 *
 * @param num is a number in base 10
 * @param base is the base num will be converted to, the digits of the converted num are stored in a dynamic array
 * 
 */
BigInteger::BigInteger(long long int num, int base) {

	BigInteger temp = convert_from_base_ten(num, base);

	this->base = base;
	size = temp.size;
	capacity = temp.size;
	digits = new int[size];

	if (digits == NULL) {
		cout << "Not enough memory" << endl;
	}

	for (int i = 0; i < temp.size; i++) {
		digits[i] = temp[i];
	}
}

/**
 * Copy Constructor
 */
BigInteger::BigInteger(const BigInteger& bigInteger) {
	digits = new int[bigInteger.capacity];
	if (digits == NULL) {
		cout << "Not enough memory" << endl;
	}
	for (int i = 0; i < bigInteger.size; i++)
	{
		digits[i] = bigInteger.digits[i];
	}

	base = bigInteger.base;
	size = bigInteger.size;
	capacity = bigInteger.capacity;
}

/**
 * Destructor
 */
BigInteger::~BigInteger() {
	delete[] digits;
}

/**
 * Returns the number of digits in the number in the given base
 *
 * @return number of digits in the number stored
 */
int BigInteger::num_digits() {
	return size;
}

/**
 * Adds a digit to the end of the number (The least significant digit)
 *
 * @param digit is the number in a specific base to be added to the BigInteger
 * If the digit does not match the base (ie. BigInteger is in base 8 and digit is 9)
 * it disregards the operation
 * @return true if the addition is successful, false otherwise
 */
bool BigInteger::add_digit(int digit) {

	//check if the digit matches the base
	if (digit >= base) {
		cout << "Digit you are trying to add does not match the base of the BigInteger!" << endl;
		return false;
	}

	//number was initially 0
	if(size == 1 && digits[0] == 0) { 
		digits[0] = digit;
		return true;
	}

	//allocate more memory
	if (size == capacity) {
		int new_cap = capacity + INITIAL_CAP / 2;
		int* temp = new int[new_cap]; //re-allocate memory
		capacity = new_cap;
		if (temp == NULL) {
			cout << "Not enough memory" << endl;
			return false;
		}
		for (int i = 0; i < size; i++)
		{
			temp[i] = digits[i];
		}
		delete[] digits; //free the memory directions used to point at
		digits = temp;
	}

	digits[size++] = digit;
	
	return true;
}

/**
 * Removes a digit from the end of the number (The least significant digit)
 *
 * @return void
 */
void BigInteger::remove_digit() {
	if (size != 0) {
		digits[--size] = 0;
	}
	else {
		cout << "BigInteger has no digits to remove!" << endl;
	}
}

/**
 * Insert a digit at a particular position
 * Ignores the task if the position does not exist (ie. 0 <= pos <= size)
 * Precondition: digit must be in base
 *
 * @param digit to be inserted (must match with the base of the BigInteger the digit is being inserted into)
 * @param pos to insert digit at
 * @return true if successful, false otherwise
 */
bool BigInteger::insert_digit(int digit, int pos) {

	//Ignore the task if the position does not exist
	if (pos < 0 || pos > size) {
		cout << "Index does not exist, must be between 0 and "<< size << " inclusively" << endl;
		return false;
	}

	//check if the digit matches the base
	if (digit >= base) {
		cout << "Digit you are trying to add does not match the base of the BigInteger!" << endl;
		return false;
	}

	//allocate more memory
	if (size == capacity) {
		int new_cap = capacity + INITIAL_CAP / 2;
		int* temp = new int[new_cap];
		capacity = new_cap;
		if (temp == NULL) {
			cout << "Not enough memory" << endl;
		}
		for (int i = 0; i < size; i++)
		{
			temp[i] = digits[i];
		}
		delete[] digits;
		digits = temp;
	}

	//shift all digits after pos by one to make space for the new digit
	for (int i = size; i >= pos; --i) {
		digits[i] = digits[i - 1];
	}

	digits[pos] = digit;
	size++;

	return true;
}

/**
 * For indexing the digits operator 
 * 
 * @param index
 * @return int at the index specified
 */
int BigInteger::operator [](int index) {
	if (index >= 0 && index < size)
		return digits[index];
	else
		return -1;
}

/**
 * Checks if two numbers are mathematically equal
 *
 * @param BigInteger number
 * @return true if equal, false otherwise
 */
bool BigInteger::operator ==(BigInteger bigInteger) const {
	if (base != bigInteger.base) {
		long long int baseTen = convert_to_base_ten(bigInteger);
		bigInteger = convert_from_base_ten(baseTen, base);
	}

	return (sameBaseCompare(*this, bigInteger) == 0);
}

/**
 * Checks if the first number is greater than the second number
 *
 * @param BigInteger second number
 * @return true if greater, false otherwise
 */
bool BigInteger::operator >(BigInteger bigInteger) const {
	if (base != bigInteger.base) {
		long long int baseTen = convert_to_base_ten(bigInteger);
		bigInteger = convert_from_base_ten(baseTen, base);
	}

	return (sameBaseCompare(*this, bigInteger) > 0);
}

/**
 * Checks if the first number is smaller than the second number
 *
 * @param BigInteger second number
 * @return true if smaller, false otherwise
 */
bool BigInteger::operator <(BigInteger bigInteger) const {
	return !((* this) > bigInteger);
}

/**
 * Checks if the first number is greater than or equal to the second number
 *
 * @param BigInteger second number
 * @return true if greater or equal, false otherwise
 */
bool BigInteger::operator >=(BigInteger bigInteger) const {
	if (base != bigInteger.base) {
		long long int baseTen = convert_to_base_ten(bigInteger);
		bigInteger = convert_from_base_ten(baseTen, base);
	}

	return (sameBaseCompare(*this, bigInteger) >= 0);
}

/**
 * Checks if the first number is smaller than or equal to the second number
 *
 * @param BigInteger second number
 * @return true if smaller or equal, false otherwise
 */
bool BigInteger::operator <=(BigInteger bigInteger) const {
	if (base != bigInteger.base) {
		long long int baseTen = convert_to_base_ten(bigInteger);
		bigInteger = convert_from_base_ten(baseTen, base);
	}

	return (sameBaseCompare(*this, bigInteger) <= 0);
}

/**
 * Checks if the first number is not equal to the second number
 *
 * @param BigInteger second number
 * @return true if not equal, false otherwise
 */
bool BigInteger::operator !=(BigInteger bigInteger) const {
	return !((*this) == bigInteger);
}

/**
 * Assignment operator
 *
 * @param const BigInteger
 * @return reference to the left hand side of the assignment
 */
BigInteger& BigInteger::operator =(const BigInteger bigInteger) {
	delete[] digits;

	size = bigInteger.size;
	capacity = bigInteger.capacity;
	base = bigInteger.base;
	digits = new int[capacity];
	for (int i = 0; i < size; i++) {
		digits[i] = bigInteger.digits[i];
	}
	return *this;
}

/**
 * Adds two numbers, result is in the base of the first number
 *
 * @param BigInteger second number
 * @return BigInteger result of the addition
 */
BigInteger BigInteger::operator +(BigInteger bigInteger) {
	BigInteger result;
	
	long long int a = convert_to_base_ten(*this);
	long long int b = convert_to_base_ten(bigInteger);

	long long int res = a + b;
	result = convert_from_base_ten(res, base);

	return result;
}


/**
 * Subtracts the second number from the first number, 
 * result is in the base of the first number
 *
 * @param BigInteger second number
 * @return BigInteger result of the subtraction
 */
BigInteger BigInteger::operator -(BigInteger bigInteger) {
	BigInteger result;

	long long int a = convert_to_base_ten(*this);
	long long int b = convert_to_base_ten(bigInteger);

	long long int res = a - b;
	result = convert_from_base_ten(res, base);

	return result;
}

/**
 * Multiplies two numbers, result is in the base of the first number
 *
 * @param BigInteger second number
 * @return BigInteger result of the multiplication
 */
BigInteger BigInteger::operator *(BigInteger bigInteger) {
	BigInteger result;

	long long int a = convert_to_base_ten(*this);
	long long int b = convert_to_base_ten(bigInteger);

	long long int res = a * b;
	result = convert_from_base_ten(res, base);

	return result;
}

/**
 * Increases the number by 1, prefix format
 *
 * @return BigInteger result of the addition by 1
 */
BigInteger BigInteger::operator ++() {
	BigInteger one(1, 10);
	*this = (*this) + one;
	return *this;
}

/**
 * Increases the number by 1, postfix format
 *
 * @return BigInteger result of the addition by 1
 */
BigInteger BigInteger::operator ++(int) {
	BigInteger old = *this;
	++(*this); //use prefix implementation
	return old;
}

/**
 * Decreases the number by 1, prefix format
 *
 * @return BigInteger result of the subtraction by 1
 */
BigInteger BigInteger::operator --() {
	BigInteger one(1, 10);
	*this = (*this) - one;
	return *this;
}

/**
 * Decreases the number by 1, postfix format
 *
 * @return BigInteger result of the subtraction by 1
 */
BigInteger BigInteger::operator --(int) {
	BigInteger old = *this;
	--(*this); //use prefix implementation
	return old;
}

/**
 * Divides the first number by the second number
 * Result is in the base of the first number
 *
 * @param BigInteger second number
 * @return BigInteger result of the division
 */
BigInteger BigInteger::operator /(BigInteger bigInteger) {
	BigInteger result;

	//check division by zero
	//result is initially 0 in base 10 
	if (bigInteger == result){
		cout << "Division by zero!" << endl;
		return result;
	}

	long long int a = convert_to_base_ten(*this);
	long long int b = convert_to_base_ten(bigInteger);

	long long int res = a / b;
	result = convert_from_base_ten(res, base);

	return result;
}

/**
 * Remainder of the division of the first number by the second number
 * Result is in the base of the first number
 *
 * @param BigInteger second number
 * @return BigInteger result of the division
 */
BigInteger BigInteger::operator %(BigInteger bigInteger) {
	BigInteger result;

	//check division by zero
	//result is initially 0 in base 10 
	if (bigInteger == result) {
		cout << "Division by zero!" << endl;
		return result;
	}

	long long int a = convert_to_base_ten(*this);
	long long int b = convert_to_base_ten(bigInteger);

	long long int res = a % b;
	result = convert_from_base_ten(res, base);

	return result;
}

/**
 * Cout operator for BigInteger class
 *
 * @param ostream&
 * @param BigInteger
 *
 * @return ostream&
 */
ostream& operator <<(ostream& out, BigInteger bigInteger) {
	out << "(";
	for (int i = 0; i < bigInteger.size - 1; i++) {

		out << bigInteger.digits[i] << ",";
	}
	out << bigInteger.digits[bigInteger.size - 1] << ") base=" << bigInteger.base;
	return out;
}

/**
 * Cin operator for BigInteger class
 * First, reads the number and then the base. 
 * If base is not matched, reports an error and considers the least possible base.
 * 
 * @param istream&
 * @param BigInteger&
 * 
 * @return istream&
 */
istream& operator >>(istream& in, BigInteger& bigInteger) {
	string num;
	int base = 10;
	cout << "Enter a number: ";
	in >> num;
	bool baseBad = true;
	while (baseBad) {
		cout << "Enter the base (between 2 and 36 inclusively) of the above number: ";
		in >> base;
		if (base >= MIN_BASE && base <= MAX_BASE) {
			baseBad = false;
		}
	}
	
	//if base does not match the num
	if (!isInBase(num, base)) {
		cout << "Base entered does not match with the number, using the least possible base..." << endl;
		//consider the least possible base
		base = findSmallestBase(num);
	}
	
	BigInteger temp(0,base);
	for (int i = 0; i < num.size(); i++) {
		if (base <= 10) {
			temp.add_digit((int(num[i]) - 48));
		}
		else {
			if (((num[i] >= 'A' && num[i] < ('A' + base - 10)))) {
				temp.add_digit((int(num[i]) - 55));
			}
			else {
				temp.add_digit((int(num[i]) - 48));
			}	
		}
	}
	bigInteger = temp;
	return in;
}

