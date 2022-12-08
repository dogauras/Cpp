#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	DoubleLinkedList mylist;

	//The single linked list file in class is updated
	//on BrightSpace, if you need it, download the new version.

	mylist.add_to_back(10);
	mylist.add_to_back(6);
	mylist.add_to_back(7);
	mylist.add_to_back(15);
	mylist.add_to_back(25);
	mylist.add_to_back(12);
	mylist.add_to_back(9);
	mylist.add_to_back(35);
	mylist.add_to_back(21);
	mylist.add_to_back(17);

	cout << mylist << endl;
	//Should be printed
	//10, 6, 7, 15, 25, 12, 9, 35, 21, 17

	//Testing add_to_front
	mylist.add_to_front(44);
	mylist.add_to_front(30);
	if (mylist[0] == 30 && mylist[1] == 44) cout << "Test 1 - add_to_front - Passed" << endl;
	else cout << "Test 1 - add_to_front - Failed" << endl;

	mylist.add_to_front(19);
	if (mylist[0] == 19) cout << "Test 2 - add_to_front - Passed" << endl;
	else cout << "Test 2 - add_to_front - Failed" << endl;

	//Testing count_nodes	
	if (mylist.count_nodes() == 13) cout << "Test 1 - count_nodes - Passed" << endl;
	else cout << "Test 1 - count_nodes - Failed" << endl;

	mylist.remove_from_front();
	if (mylist.count_nodes() == 12) cout << "Test 2 - count_nodes - Passed" << endl;
	else cout << "Test 2 - count_nodes - Failed" << endl;

	mylist.remove_from_back();
	if (mylist.count_nodes() == 11) cout << "Test 3 - count_nodes - Passed" << endl;
	else cout << "Test 3 - count_nodes - Failed" << endl;

	//Testing add_to_back
	mylist.add_to_back(18);
	mylist.add_to_back(28);
	int ind = mylist.count_nodes();
	if (mylist[ind - 1] == 28 && mylist[ind - 2] == 18) cout << "Test 1 - add_to_back - Passed" << endl;
	else cout << "Test 1 - add_to_back - Failed" << endl;

	DoubleLinkedList mylist2;
	mylist2.add_to_back(37);
	if (mylist2[0] == 37) cout << "Test 2 - add_to_back - Passed" << endl;
	else cout << "Test 2 - add_to_back - Failed" << endl;


	//Testing insert_iterm
	mylist.insert_item(5, 2);
	ind = mylist.count_nodes();
	if (mylist[5] == 2 && ind == 14) cout << "Test 1 - insert_item - Passed" << endl;
	else cout << "Test 1 - insert_item - Failed" << endl;

	mylist2.insert_item(0, 1);
	if (mylist2[0] == 1) cout << "Test 2 - insert_item - Passed" << endl;
	else cout << "Test 2 - insert_item - Failed" << endl;

	mylist2.insert_item(0, 11);
	if (mylist2[0] == 11) cout << "Test 3 - insert_item - Passed" << endl;
	else cout << "Test 3 - insert_item - Failed" << endl;

	//Testing remove_item
	mylist.remove_item(10);
	ind = mylist.count_nodes();
	if (mylist[2] != 10 && ind == 13) cout << "Test 1 - remove_item - Passed" << endl;
	else cout << "Test 1 - remove_item - Failed" << endl;

	mylist2.remove_item(1);
	if (mylist2[1] != 1) cout << "Test 2 - remove_item - Passed" << endl;
	else cout << "Test 2 - remove_item - Failed" << endl;

	mylist2.remove_item(19);
	if (mylist2[0] == 11 && mylist2[1] == 37) cout << "Test 3 - remove_item - Passed" << endl;
	else cout << "Test 3 - remove_item - Failed" << endl;

	//Testing remove_from_front
	mylist.remove_from_front();
	ind = mylist.count_nodes();
	if (mylist[0] == 44 && ind == 12) cout << "Test 1 - remove_from_front - Passed" << endl;
	else cout << "Test 1 - remove_from_front - Failed" << endl;

	mylist2.remove_from_front();
	if (mylist2[0] == 37) cout << "Test 2 - remove_from_front - Passed" << endl;
	else cout << "Test 2 - remove_from_front - Failed" << endl;

	//Testing remove_from_back
	mylist.remove_from_back();
	ind = mylist.count_nodes();
	if (mylist[ind - 1] == 18 && ind == 11) cout << "Test 1 - remove_from_back - Passed" << endl;
	else cout << "Test 1 - remove_from_back - Failed" << endl;

	mylist2.remove_from_back();
	if (mylist2.count_nodes() == 0) cout << "Test 2 - remove_from_back - Passed" << endl;
	else cout << "Test 2 - remove_from_back - Failed" << endl;

	//Testing operator []
	mylist[5] = 33;
	ind = mylist.count_nodes();
	if (mylist[5] == 33 && ind == 11) cout << "Test 1 - operator [] - Passed" << endl;
	else cout << "Test 1 - operator [] - Failed" << endl;

	mylist2[2] = 5;
	if (mylist2.count_nodes() == 0) cout << "Test 2 - operator [] - Passed" << endl;
	else cout << "Test 2 - operator [] - Failed" << endl;

	mylist2.add_to_back(9);
	if (mylist2[0] == 9) cout << "Test 3 - operator [] - Passed" << endl;
	else cout << "Test 3 - operator [] - Failed" << endl;

	//Testing operator <<
	cout << mylist << endl;
	cout << mylist2 << endl;

	//Should be printed
	//44, 6, 7, 2, 15, 33, 12, 9, 35, 21, 18
	//9

	return 0;
}
