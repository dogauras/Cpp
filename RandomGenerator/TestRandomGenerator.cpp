#include <iostream>
#include <ctime>
#include <cstdlib>
#include "RandomGenerator.h"

using namespace std;

//There is typo in the + operator definition, check the
//PDF again

int main()
{
	RandomGenerator R1(2, 7821, 2453);
	RandomGenerator R2(2, 2025, 1973);
	RandomGenerator R3(4, 90123525, 41050089);
	RandomGenerator R4(4, 67128722, 55441122);
	RandomGenerator R5;

	int i;
	for (i = 0; i < 10; ++i)
		++R1;

	for (i = 0; i < 5; ++i)
		++R2;

	for (i = 0; i < 20; ++i)
		++R3;

	for (i = 0; i < 15; ++i)
		++R4;

	cout << R1 << endl;
	cout << R2 << endl;
	cout << R3 << endl;
	cout << R4 << endl;

	//Testing operator []
	if (R1[2] == 1849 && R1[3] == 5355) cout << "Test 1 - indexing - Passed" << endl;
	else cout << "Test 1 - indexing - Failed" << endl;

	if (R3[15] == 70837525 && R3[10] == 13410354) cout << "Test 2 - indexing - Passed" << endl;
	else cout << "Test 2 - indexing - Failed" << endl;

	if (R2[4] == 4205 && R2[6] == 3961) cout << "Test 3 - indexing - Passed" << endl;
	else cout << "Test 3 - indexing - Failed" << endl;

	//Testing operator ==
	RandomGenerator R6(R1);
	if (R1 == R6) cout << "Test 1 - equal - Passed" << endl;
	else cout << "Test 1 - equal - Failed" << endl;

	R5 = R2;
	if (R5 == R2) cout << "Test 2 - equal - Passed" << endl;
	else cout << "Test 2 - equal - Failed" << endl;

	R5 = R3;
	if (R5 == R3) cout << "Test 3 - equal - Passed" << endl;
	else cout << "Test 3 - equal - Failed" << endl;


	//Testing operator !=
	--R6;
	if (R1 != R6) cout << "Test 1 - not equal - Passed" << endl;
	else cout << "Test 1 - not equal - Failed" << endl;

	if (R6 != R2) cout << "Test 2 - not equal - Passed" << endl;
	else cout << "Test 2 - not equal - Failed" << endl;

	if (R4 != R3) cout << "Test 3 - not equal - Passed" << endl;
	else cout << "Test 3 - not equal - Failed" << endl;


	//Testing operator +
	//There is typo in the + operator definition, check the
	//PDF again

	R5 = R1 + R2;
	cout << R5 << endl;
	//9846, 4426, 1802, 1727, 3218, 588, 2444, 9042, 9834, 417, 3033, 6701
	//Should be printed

	if (R5[2] == 1802 && R5[5] == 588) cout << "Test 1 - addition - Passed" << endl;
	else cout << "Test 1 - addition - Failed" << endl;

	R5 = R3 + R4;
	cout << R5 << endl;
	//57252247, 96491211, 27038834, 33440915, 28744283, 93346003, 43322856, 8026055, 16220562, 91689169, 43075243, 22914074, 91421122, 68941054, 81671454, 20947916, 93104178, 17989838, 24137165, 86119832, 80271305, 96244934
	//Should be printed

	if (R5[2] == 27038834 && R5[10] == 43075243) cout << "Test 2 - addition - Passed" << endl;
	else cout << "Test 2 - addition - Failed" << endl;

	//Testing operator -
	R5 = R1 - R2;
	cout << R5 << endl;
	//5796, 480, 8104, 1017, 4808, 5296, 4522, 122, 6848, 6401, 1941, 6025
	//Should be printed
	if (R5[7] == 122 && R5[8] == 6848) cout << "Test 1 - subtraction - Passed" << endl;
	else cout << "Test 1 - subtraction - Failed" << endl;

	R5 = R3 - R4;
	cout << R5 << endl;
	//22994803, 14391033, 11294386, 1451751, 21902175, 54163455, 20459276, 84639985, 64449622, 33410673, 16254535, 40402582, 78004018, 7113130, 81432866, 20727134, 2469618, 9948852, 20354237, 1617198, 3097705, 61972014
	//Should be printed
	if (R5[4] == 21902175 && R5[21] == 61972014) cout << "Test 2 - subtraction - Passed" << endl;
	else cout << "Test 2 - subtraction - Failed" << endl;

	//Testing *
	R5 = R1 * R2;
	cout << R5 << endl;
	//8375, 8397, 4030, 1220, 8996, 145, 6011, 4357, 4531, 8852, 5229, 1506
	//Should be printed
	if (R5[10] == 5229 && R5[5] == 145) cout << "Test 1 - multiplication - Passed" << endl;
	else cout << "Test 1 - multiplication - Failed" << endl;

	R5 = R3 * R4;
	//87705538, 86299235, 82554724, 9255376, 63213386, 94910463, 57196938, 42537451, 36631391, 65766039, 81666286, 87523875, 29868089, 62077705, 72868337, 69607522, 78113699, 16365378, 7694259, 50253358, 3690753, 63920036
	//Should be printed
	cout << R5 << endl;
	if (R5[21] == 63920036 && R5[3] == 9255376) cout << "Test 2 - multiplication - Passed" << endl;
	else cout << "Test 2 - multiplication - Failed" << endl;


	//Testing +=
	RandomGenerator R8(R1);
	R5 = R8 + R2;
	R8 += R2;
	if (R8 == R5) cout << "Test 1 - += - Passed" << endl;
	else cout << "Test 1 - += - Failed" << endl;

	RandomGenerator R9 = R3;
	R5 = R3 + R4;
	R9 += R4;
	if (R9 == R5) cout << "Test 2 - += - Passed" << endl;
	else cout << "Test 2 - += - Failed" << endl;

	//Testing -=
	RandomGenerator R10(R1);
	R5 = R1 - R2;
	R10 -= R2;
	if (R5 == R10) cout << "Test 1 - -= - Passed" << endl;
	else cout << "Test 1 - -= - Failed" << endl;

	RandomGenerator R11(R3);
	R5 = R3 - R4;
	R11 -= R4;
	if (R5 == R11) cout << "Test 2 - -= - Passed" << endl;
	else cout << "Test 2 - -= - Failed" << endl;

	//Testing *=
	RandomGenerator R12(R1);
	R5 = R1 * R2;
	R12 *= R2;
	if (R5 == R12) cout << "Test 1 - *= - Passed" << endl;
	else cout << "Test 1 - *= - Failed" << endl;

	RandomGenerator R13(R1);
	R5 = R1 * R2;
	R13 *= R2;
	if (R13 == R5) cout << "Test 2 - *= - Passed" << endl;
	else cout << "Test 2 - *= - Failed" << endl;

	//Testing --
	--R5;
	if (R13 != R5) cout << "Test 1 - -- - Passed" << endl;
	else cout << "Test 1 - -- - Failed" << endl;

	--R13;
	if (R13 == R5) cout << "Test 2 - -- - Passed" << endl;
	else cout << "Test 2 - -- - Failed" << endl;

	//Testing <<
	cout << R10 << endl << R11 << endl;
	cout << R12 << endl << R13 << endl;

	//Should be printed
	//5796, 480, 8104, 1017, 4808, 5296, 4522, 122, 6848, 6401, 1941, 6025
	//22994803, 14391033, 11294386, 1451751, 21902175, 54163455, 20459276, 84639985, 64449622, 33410673, 16254535, 40402582, 78004018, 7113130, 81432866, 20727134, 2469618, 9948852, 20354237, 1617198, 3097705, 61972014
	//8375, 8397, 4030, 1220, 8996, 145, 6011, 4357, 4531, 8852, 5229, 1506
	//8375, 8397, 4030, 1220, 8996, 145, 6011, 4357, 4531, 8852, 5229
	return 0;
}