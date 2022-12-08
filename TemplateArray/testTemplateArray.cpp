
#include <iostream>
#include "Array.cpp"

using namespace std;

int main()
{
	int i;
	Array <int> nums(10, 50);

	for (i = 10; i <= 50; ++i)
		nums[i] = i;

	//Testing add_item
	nums.add_item(94);
	nums.add_item(86);
	if (nums[51] == 94 && nums[52] == 86) cout << "Test 1 - add_item - Passed" << endl;
	else cout << "Test 1 - add_item - Failed" << endl;

	nums.add_item(22);
	if (nums[53] == 22) cout << "Test 2 - add_item - Passed" << endl;
	else cout << "Test 2 - add_item - Failed" << endl;


	//Testing insert_item
	nums.insert_item(15, 29);
	if (nums[15] == 29) cout << "Test 1 - insert_item - Passed" << endl;
	else cout << "Test 1 - insert_item - Failed" << endl;

	nums.insert_item(60, 20);
	nums.insert_item(10, 15);
	if (nums[10] == 15) cout << "Test 2 - insert_item - Passed" << endl;
	else cout << "Test 2 - insert_item - Failed" << endl;

	//Testing remove_item()
	for (i = 10; i <= 55; ++i)
		cout << nums[i] << " ";
	cout << endl;
	nums.remove_item();
	if (nums[54] == 86) cout << "Test 1 - remove_item - Passed" << endl;
	else cout << "Test 1 - remove_item - Failed" << endl;

	nums.remove_item();
	if (nums[53] == 94) cout << "Test 2 - remove_item - Passed" << endl;
	else cout << "Test 2 - remove_item - Failed" << endl;

	//Testing remove_item(x)
	nums.remove_item(13);
	if (nums[14] == 14 && nums[13] == 12) cout << "Test 1 - remove_item(x) - Passed" << endl;
	else cout << "Test 1 - remove_item(x) - Failed" << endl;

	nums.remove_item(20);
	if (nums[20] == 19 && nums[21] == 21) cout << "Test 2 - remove_item(x) - Passed" << endl;
	else cout << "Test 2 - remove_item(x) - Failed" << endl;

	//Testing erase_item
	cout << nums << endl;
	nums.erase_item(15);
	if (nums[15] == 15) cout << "Test 1 - erase_item - Passed" << endl;
	else cout << "Test 1 - erase_item - Failed" << endl;

	nums.erase_item(10);
	if (nums[10] == 10) cout << "Test 2 - erase_item - Passed" << endl;
	else cout << "Test 2 - erase_item - Failed" << endl;


	//Testing find_item
	int x;
	nums.find_item(94, x);
	cout << nums << endl;
	if (x == 49) cout << "Test 1 - find_item - Passed" << endl;
	else cout << "Test 1 - find_item - Failed" << endl;

	nums.find_item(11, x);
	if (x == 11) cout << "Test 2 - find_item - Passed" << endl;
	else cout << "Test 2 - find_item - Failed" << endl;


	//Testing =
	Array <int> nums2 = nums;
	if (nums[10] == nums2[10]) cout << "Test 1 - = - Passed" << endl;
	else cout << "Test 1 - = - Failed" << endl;

	bool check = true;
	for (i = 10; i <= 49; ++i)
	{
		if (nums[i] != nums2[i])
		{
			check = false;
			break;
		}
	}
	if (check) cout << "Test 2 - = - Passed" << endl;
	else cout << "Test 2 - = - Failed" << endl;

	cout << nums << endl;

	//10, 11, 12, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 94
	//Should be printed


	return 0;
}