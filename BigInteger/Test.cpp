/*
*  Author: Doga Uras
*  This class design is for the concept of an integer number in a particular base.
*  The number could contain any number of digits in a particular base.
* 
*  This test file can be used to run tests on all the functions mentioned in the Assignment 1 document
*/

#include <iostream>
#include "BigInteger.h"

using namespace std;

int main()
{
	BigInteger intZero;
	BigInteger int1(18729573, 2); //1000111011100101001100101
	BigInteger int2(756, 3); //1001000
	BigInteger int3(-93250, 7); //535603
	BigInteger int4(-93254, 8); //266106
	BigInteger int5(9876543, 10);
	BigInteger int6(-756, 16); //2F4
	BigInteger int7(7568, 26); //B52
	BigInteger int8(1024,36); //SG
	BigInteger int9(int1);
	BigInteger int10(int6);

	
	//print initial numbers
	cout << intZero << endl;
	cout << int1 << endl << int2 << endl;
	cout << int3 << endl << int4 << endl;
	cout << int5 << endl << int6 << endl;
	cout << int7 << endl << int8 << endl;
	cout << int9 << endl << int10 << endl;

	//testing num_digits()
	if (int1.num_digits() == 25) cout << "Test 1 - num_digits - Passed" << endl;
	else cout << "Test 1 - num_digits - Failed" << endl;

	if (int3.num_digits() == 6) cout << "Test 2 - num_digits - Passed" << endl;
	else cout << "Test 2 - num_digits - Failed" << endl;

	if (int5.num_digits() == 7) cout << "Test 3 - num_digits - Passed" << endl;
	else cout << "Test 3 - num_digits - Failed" << endl;

	if (int8.num_digits() == 2) cout << "Test 4 - num_digits - Passed" << endl;
	else cout << "Test 4 - num_digits - Failed" << endl;

	//testing add_digit
	int8.add_digit(9);
	if (int8.num_digits() == 3 && int8[2] == 9) cout << "Test 1 - add_digit - Passed" << endl;
	else cout << "Test 1 - add_digit - Failed" << endl;

	int6.add_digit(12);
	if (int6.num_digits() == 4 && int6[3] == 12) cout << "Test 2 - add_digit - Passed" << endl;
	else cout << "Test 2 - add_digit - Failed" << endl;

	int1.add_digit(0);
	if (int1.num_digits() == 26 && int1[25] == 0) cout << "Test 3 - add_digit - Passed" << endl;
	else cout << "Test 3 - add_digit - Failed" << endl;


	//testing remove_digit
	int8.remove_digit();
	if (int8.num_digits() == 2 && int8[1] == 16) cout << "Test 1 - remove_digit - Passed" << endl;
	else cout << "Test 1 - remove_digit - Failed" << endl;

	int6.remove_digit();
	if (int6.num_digits() == 3 && int6[2] == 4) cout << "Test 2 - remove_digit - Passed" << endl;
	else cout << "Test 2 - remove_digit - Failed" << endl;

	int1.remove_digit();
	if (int1.num_digits() == 25 && int1[24] == 1) cout << "Test 3 - remove_digit - Passed" << endl;
	else cout << "Test 3 - remove_digit - Failed" << endl;


	//testing insert_digit
	int4.insert_digit(7,2);
	if (int4.num_digits() == 7 && int4[2] == 7) cout << "Test 1 - insert_digit - Passed" << endl;
	else cout << "Test 1 - insert_digit - Failed" << endl;

	int7.insert_digit(10,1);
	if (int7.num_digits() == 4 && int7[1] == 10) cout << "Test 2 - insert_digit - Passed" << endl;
	else cout << "Test 2 - insert_digit - Failed" << endl;

	int1.insert_digit(0,int1.num_digits()-1);
	if (int1.num_digits() == 26 && int1[24] == 0) cout << "Test 3 - insert_digit - Passed" << endl;
	else cout << "Test 3 - insert_digit - Failed" << endl;

	//meant to fail as 9 is not in base 8
	if (int4.insert_digit(9, 1)) cout << "Test 4 - insert_digit - Failed" << endl;
	else cout << "Test 4 - insert_digit - Passed" << endl;


	//testing operator []
	if (int4[2] == 7 && int5[1] == 8) cout << "Test 1 - indexing - Passed" << endl;
	else cout << "Test 1 - indexing - Failed" << endl;

	if (int7[2] == 5 && int10[2] == 4) cout << "Test 2 - indexing - Passed" << endl;
	else cout << "Test 2 - indexing - Failed" << endl;

	if (int3[2] == 5 && int3[3] == 6 && int3[4] == 0) cout << "Test 3 - indexing - Passed" << endl;
	else cout << "Test 3 - indexing - Failed" << endl;

	
	//testing operator ==
	BigInteger a(512, 7);
	BigInteger b(512, 12);
	BigInteger c(512, 34);
	if (a == b && b == c) cout << "Test 1 - equal - Passed" << endl;
	else cout << "Test 1 - equal - Failed" << endl;

	BigInteger d(9876031, 10);
	BigInteger e = int8 - c;
	if (a == e && b == e && c == e) cout << "Test 2 - equal - Passed" << endl;
	else cout << "Test 2 - equal - Failed" << endl;

	e = int8 - a;
	if (a == e && b == e && c == e) cout << "Test 3 - equal - Passed" << endl;
	else cout << "Test 3 - equal - Failed" << endl;


	//testing operator >
	e++;
	if (e > a && e > c) cout << "Test 1 - > - Passed" << endl;
	else cout << "Test 1 - > - Failed" << endl;

	if (int7 > int6 && int7 > int8) cout << "Test 2 - > - Passed" << endl;
	else cout << "Test 2 - > - Failed" << endl;


	//tesitng operator <
	b--;
	if (b < a && b < c) cout << "Test 1 - < - Passed" << endl;
	else cout << "Test 1 - < - Failed" << endl;

	if (int4 < int3 && int6 < int2) cout << "Test 2 - < - Passed" << endl;
	else cout << "Test 2 - < - Failed" << endl;


	//testing operator >=
	b++;
	if (e >= a && b >= c && e >= c) cout << "Test 1 - >= - Passed" << endl;
	else cout << "Test 1 - >= - Failed" << endl;

	if (int3 >= int4 && int6 >= int3 && int2 >= int6) cout << "Test 2 - >= - Passed" << endl;
	else cout << "Test 2 - >= - Failed" << endl;

	if (int1 >= int9 && int6 >= int10) cout << "Test 3 - >= - Passed" << endl;
	else cout << "Test 3 - >= - Failed" << endl;


	//testing operator <=
	if (a <= e && c <= b && c <= e) cout << "Test 1 - <= - Passed" << endl;
	else cout << "Test 1 - <= - Failed" << endl;

	if (int4 <= int3&& int3 <= int6 && int6 <= int2) cout << "Test 2 - <= - Passed" << endl;
	else cout << "Test 2 - <= - Failed" << endl;

	if (int9 <= int1 && int10 <= int6) cout << "Test 3 - <= - Passed" << endl;
	else cout << "Test 3 - <= - Failed" << endl;


	//testing operator !=
	if (int1 != int2 && int2 != int3) cout << "Test 1 - != - Passed" << endl;
	else cout << "Test 1 - != - Failed" << endl;

	b++;
	if (a != b && c != b) cout << "Test 2 - != - Passed" << endl;
	else cout << "Test 2 - != - Failed" << endl;

	b--;
	if (!(a != b) && int7 != int8 && int5 != int4) cout << "Test 3 - != - Passed" << endl;
	else cout << "Test 3 - != - Failed" << endl;
	

	
	//test operator =
	a = int8;
	if (a == int8) cout << "Test 1 - = - Passed" << endl;
	else cout << "Test 1 - = - Failed" << endl;

	b = int9;
	if(b == int9) cout << "Test 2 - = - Passed" << endl;
	else cout << "Test 2 - = - Failed" << endl;

	c = int10;
	if (c == int10) cout << "Test 3 - = - Passed" << endl;
	else cout << "Test 3 - = - Failed" << endl;


	//test operator +
	BigInteger int11(-93254, 8);
	BigInteger int12(93254, 8);
	if ((int11 + int12) == intZero) cout << "Test 1 - + - Passed" << endl;
	else cout << "Test 1 - + - Failed" << endl;

	if ((int10 + int9) == BigInteger(18728817,10)) cout << "Test 2 - + - Passed" << endl;
	else cout << "Test 2 - + - Failed" << endl;

	if ((int5 + int8) == BigInteger(9877567, 10)) cout << "Test 3 - + - Passed" << endl;
	else cout << "Test 3 - + - Failed" << endl;

	if ((int11 + int11) == BigInteger((-93254*2),10)) cout << "Test 4 - + - Passed" << endl;
	else cout << "Test 4 - + - Failed" << endl;


	//test operator -
	if ((int11 - int12) == BigInteger((-93254*2),10)) cout << "Test 1 - - - Passed" << endl;
	else cout << "Test 1 - - - Failed" << endl;

	if ((int10 - int9) == BigInteger(-18730329, 10)) cout << "Test 2 - - - Passed" << endl;
	else cout << "Test 2 - - - Failed" << endl;

	if ((int5 - int8) == BigInteger(9875519, 10)) cout << "Test 3 - - - Passed" << endl;
	else cout << "Test 3 - - - Failed" << endl;

	if ((int11 - int11) == intZero) cout << "Test 4 - - - Passed" << endl;
	else cout << "Test 4 - - - Failed" << endl;


	//test operator *
	if ((intZero * int12) == intZero) cout << "Test 1 - * - Passed" << endl;
	else cout << "Test 1 - * - Failed" << endl;

	if ((int11 * int12) == BigInteger(-8696308516,10)) cout << "Test 2 - * - Passed" << endl;
	else cout << "Test 2 - * - Failed" << endl;

	if ((int9 * int10) == BigInteger(-14159557188, 10)) cout << "Test 3 - * - Passed" << endl;
	else cout << "Test 3 - * - Failed" << endl;

	if ((int5 * int8) == BigInteger(10113580032, 10)) cout << "Test 4 - * - Passed" << endl;
	else cout << "Test 4 - * - Failed" << endl;
	
	//test operator ++
	if ((++int5) == (int5 + BigInteger(1,10))) cout << "Test 1 - prefix ++ - Passed" << endl;
	else cout << "Test 1 - prefix ++ - Failed" << endl;

	if ((++int5) == (int5 + BigInteger(1, 10))) cout << "Test 2 - prefix ++ - Passed" << endl;
	else cout << "Test 2 - prefix ++ - Failed" << endl;

	BigInteger old(int5);
	int5++;
	if (int5 == (old + BigInteger(1, 10))) cout << "Test 1 - postfix ++ - Passed" << endl;
	else cout << "Test 1 - postfix ++ - Failed" << endl;

	//test operator --
	if ((--int5) == (int5 - BigInteger(1, 10))) cout << "Test 1 - prefix -- - Passed" << endl;
	else cout << "Test 1 - prefix -- - Failed" << endl;

	if ((--int5) == (int5 - BigInteger(1, 10))) cout << "Test 2 - prefix -- - Passed" << endl;
	else cout << "Test 2 - prefix -- - Failed" << endl;

	old = int5;
	int5--;
	if (int5 == (old - BigInteger(1, 10))) cout << "Test 1 - postfix -- - Passed" << endl;
	else cout << "Test 1 - postfix - - Failed" << endl;


	//test operator /
	if ((int11 / int11) == BigInteger(1,10)) cout << "Test 1 - / - Passed" << endl;
	else cout << "Test 1 - / - Failed" << endl;

	if ((int10 / int9) == intZero) cout << "Test 2 - / - Passed" << endl;
	else cout << "Test 2 - / - Failed" << endl;

	if ((int5 / int8) == BigInteger(9645, 10)) cout << "Test 3 - / - Passed" << endl;
	else cout << "Test 3 - / - Failed" << endl;

	if ((int11 / int12) == BigInteger(-1, 10)) cout << "Test 4 - / - Passed" << endl;
	else cout << "Test 4 - / - Failed" << endl;

	//test operator %
	if ((int11 % int11) == intZero) cout << "Test 1 - % - Passed" << endl;
	else cout << "Test 1 - % - Failed" << endl;

	if ((int10 % int9) == int10) cout << "Test 2 - % - Passed" << endl;
	else cout << "Test 2 - % - Failed" << endl;

	if ((int5 % int8) == BigInteger(63, 10)) cout << "Test 3 - % - Passed" << endl;
	else cout << "Test 3 - % - Failed" << endl;

	if ((int11 % int12) == intZero) cout << "Test 4 - % - Passed" << endl;
	else cout << "Test 4 - % - Failed" << endl;


	//test operator <<
	cout << int1 << endl << int2 << endl;
	cout << int3 << endl << int4 << endl;
	//The following should be printed
	/*
	(1,0,0,0,1,1,1,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1) base=2
	(1,0,0,1) base=3
	(-5,3,5,6,0,3) base=7
	(-2,6,7,6,1,0,6) base=8
	*/

	cout << endl;

	//test operator >>
	// 
	// Ex1:
	//Enter a number: SG
	//Enter the base(between 2 and 36 inclusively) of the above number : 36
	//(28, 16) base=36

	// Ex2:
	//Enter a number: B52
	//Enter the base(between 2 and 36 inclusively) of the above number : 26
	//(11,5,2) base=26

	//Enter a number : 7Z9F
	//Enter the base(between 2 and 36 inclusively) of the above number : 22
	//Base entered does not match with the number, using the least possible base...
	//(7, 35, 9, 15) base = 36
	BigInteger temp;
	cin >> temp;
	cout << temp << endl;

	return 0;
}