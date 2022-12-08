#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

int main()
{
	double da[5] = { 4.23, 5.01, 10.2, 5.51, 6.78 };
	double db[5] = { -1.32, 7.12, -5.55 };
	double dc[7] = { -1.0, 1.0, 5.0, -4.5, 3.5, 2.5, -6.0 };

	Vector v1(da, 5);
	Vector v2(db, 5);
	Vector v3(dc, 7);
	Vector v4(v3);

	//Testing dimension
	if (v1.dimension() == 5) cout << "Test 1 - dimension - Passed" << endl;
	else cout << "Test 1 - dimension - Failed" << endl;

	if (v2.dimension() == 5) cout << "Test 2 - dimension - Passed" << endl;
	else cout << "Test 2 - dimension - Failed" << endl;

	if (v3.dimension() == 7) cout << "Test 3 - dimension - Passed" << endl;
	else cout << "Test 3 - dimension - Failed" << endl;

	if (v4.dimension() == 7) cout << "Test 4 - dimension - Passed" << endl;
	else cout << "Test 4 - dimension - Failed" << endl;

	//Testing add_dimension
	v1.add_dimension(6.45);
	if (v1.dimension() == 6) cout << "Test 1 - add_dimension - Passed" << endl;
	else cout << "Test 1 - add_dimension - Failed" << endl;

	v2.add_dimension(7.81);
	if (v2[5] == 7.81) cout << "Test 2 - add_dimension - Passed" << endl;
	else cout << "Test 2 - add_dimension - Failed" << endl;

	v4.add_dimension(5.76);
	if (v4[7] == 5.76) cout << "Test 3 - add_dimension - Passed" << endl;
	else cout << "Test 3 - add_dimension - Failed" << endl;

	//Testing remove_dimension
	v1.remove_dimension(2);
	if (v1[2] == 5.51 && v1.dimension() == 5) cout << "Test 1 - remove_dimension - Passed" << endl;
	else cout << "Test 1 - remove_dimension - Failed" << endl;

	v4.remove_dimension(5);
	if (v4[5] == -6.0 && v4.dimension() == 7) cout << "Test 2 - remove_dimension - Passed" << endl;
	else cout << "Test 2 - remove_dimension - Failed" << endl;

	//Testing insert_dimension
	v1.insert_dimension(3, 5.71);
	if (v1[3] == 5.71 && v1.dimension() == 6) cout << "Test 1 - insert_dimension - Passed" << endl;
	else cout << "Test 1 - insert_dimension - Failed" << endl;

	v2.insert_dimension(5, 7.3);
	if (v2[5] == 7.3 && v2.dimension() == 7) cout << "Test 2 - insert_dimension - Passed" << endl;
	else cout << "Test 2 - insert_dimension - Failed" << endl;

	//Testing magnitude
	if (fabs(v1.magnitude() - 13.911437740219377) < 1e-9) cout << "Test 1 - magnitude - Passed" << endl;
	else cout << "Test 1 - magnitude - Failed" << endl;

	if (fabs(v2.magnitude() - 14.054372984946713) < 1e-9) cout << "Test 2 - magnitude - Passed" << endl;
	else cout << "Test 2 - magnitude - Failed" << endl;

	if (fabs(v3.magnitude() - 10.087120500916008) < 1e-9) cout << "Test 3 - magnitude - Passed" << endl;
	else cout << "Test 3 - magnitude - Failed" << endl;

	//Testing *
	v2 = v1 * 5;
	if (v2 == v1 * 5) cout << "Test 1 - * - Passed" << endl;
	else cout << "Test 1 - * - Failed" << endl;

	v4 = v1 * v2;
	if (v4 == v1 * v2) cout << "Test 2 - * - Passed" << endl;
	else cout << "Test 2 - * - Failed" << endl;

	v3 = 6.43 * v1;
	if (v3 == 6.43 * v1) cout << "Test 3 - * - Passed" << endl;
	else cout << "Test 3 - * - Failed" << endl;

	//Testing +
	v2 = v1 + v4;
	if (v2 == v1 + v4) cout << "Test 1 - Plus - Passed" << endl;
	else cout << "Test 1 - Plus - Failed" << endl;

	v3 = v1 + v2;
	if (v3 == v1 + v2) cout << "Test 2 - Plus - Passed" << endl;
	else cout << "Test 2 - Plus - Failed" << endl;

	v1 = v2 + v4;
	if (v1 == v2 + v4) cout << "Test 3 - Plus - Passed" << endl;
	else cout << "Test 3 - Plus - Failed" << endl;

	//Testing -
	v2 = v1 - v4;
	if (v2 == v1 - v4) cout << "Test 1 - Minus - Passed" << endl;
	else cout << "Test 1 - Minus - Failed" << endl;

	v3 = v1 - v2;
	if (v3 == v1 - v2) cout << "Test 2 - Minus - Passed" << endl;
	else cout << "Test 2 - Minus - Failed" << endl;

	v1 = v2 - v4;
	if (v1 == v2 - v4) cout << "Test 3 - Minus - Passed" << endl;
	else cout << "Test 3 - Minus - Failed" << endl;

	//Testing +=
	v3 = v2;
	v2 += v1;
	if (v2 == v1 + v3) cout << "Test 1 - += - Passed" << endl;
	else cout << "Test 1 - += - Failed" << endl;

	v1 = v3;
	v3 += v4;
	if (v3 == v1 + v4) cout << "Test 2 - += - Passed" << endl;
	else cout << "Test 2 - += - Failed" << endl;

	//Testing -=
	v3 = v4;
	v4 -= v1;
	if (v4 == v3 - v1) cout << "Test 1 - -= - Passed" << endl;
	else cout << "Test 1 - -= - Failed" << endl;

	v1 = v3;
	v3 -= v2;
	if (v3 == v1 - v2) cout << "Test 2 - -= - Passed" << endl;
	else cout << "Test 2 - -= - Failed" << endl;

	//Testing <<
	cout << v1 << endl << v2 << endl;
	cout << v3 << endl << v4 << endl;

	//Should be printed
	//(89.4645, 125.5, 151.8, 163.02, 229.842, 208.013)
	//(97.9245, 135.52, 162.82, 174.44, 243.402, 220.912)
	//(-8.46, -10.02, -11.02, -11.42, -13.56, -12.9)
	//(-4.23, -5.01, -5.51, -5.71, -6.78, -6.45)
	return 0;
}