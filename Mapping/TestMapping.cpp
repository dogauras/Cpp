#include <iostream>
#include "Mapping.cpp"

using namespace std;

int main()
{
    Mapping <string, double> marks;

    marks.add_item("Albert Wesker", 15.0);
    marks.add_item("Albert Wesker", 20.0);
    marks.add_item("Albert Wesker", 30.0);

    marks.add_item("Chris Redfield", 8.72);
    marks.add_item("Chris Redfield", 16.5);
    marks.add_item("Chris Redfield", 23.5);
    marks.add_item("Chris Redfield", 32.75);


    //Testing find_item
    set <double> sd = marks.find_item("Albert Wesker");
    if (sd.size() == 3 && sd.find(15.0) != sd.end() && sd.find(20.0) != sd.end() && sd.find(30.0) != sd.end())  cout << "find_item - Test 1 - Passed." << endl;
    else cout << "find_item - Test 1 - Failed!" << endl;

    sd = marks.find_item("Jill Valentine");
    if (sd.size() == 0) cout << "find_item - Test 2 - Passed." << endl;
    else cout << "find_item - Test 2 - Failed!" << endl;

    sd = marks.find_item("Chris Redfield");
    if (sd.find(32.75) != sd.end() && sd.size() == 4) cout << "find_item - Test 3 - Passed." << endl;
    else cout << "find_item - Test 3 - Failed!" << endl;

    //Testing add_item
    marks.add_item("Jill Valentine", 14.5);
    sd = marks.find_item("Jill Valentine");
    if (sd.find(14.5) != sd.end()) cout << "add_item - Test 1 - Passed." << endl;
    else cout << "add_item - Test 1 - Failed!" << endl;

    marks.add_item("Chris Redfield", 8.72);
    sd = marks.find_item("Chris Redfield");
    if (sd.size() == 4) cout << "add_item - Test 2 - Passed." << endl;
    else cout << "add_item - Test 2 - Failed!" << endl;

    //Testing remove_item
    marks.remove_item("Albert Wesker", 30.0);
    sd = marks.find_item("Albert Wesker");
    if (sd.find(30.0) == sd.end() && sd.size() == 2) cout << "remove_iterm - Test 1 - Passed." << endl;
    else cout << "remove_item - Test 1 - Failed!" << endl;

    marks.remove_item("Chris Redfield", 9.51);
    sd = marks.find_item("Chris Redfield");
    if (sd.size() == 4) cout << "remove_item - Test 2 - Passed." << endl;
    else cout << "remove_item - Test 2 - Failed!" << endl;

    //Testing clear_item
    marks.clear_item("Jill Valentine");
    sd = marks.find_item("Jill Valentine");
    if (sd.size() == 0) cout << "clear_item - Test 1 - Passed." << endl;
    else cout << "clear_item - Test 1 - Failed!" << endl;

    marks.clear_item("Albert Wesker");
    sd = marks.find_item("Albert Wesker");
    if (sd.size() == 0) cout << "clear_item - Test 2 - Passed." << endl;
    else cout << "clear_item - Test 2 - Failed!" << endl;

    marks.add_item("Albert Wesker", 15.0);
    marks.add_item("Albert Wesker", 20.0);
    marks.add_item("Albert Wesker", 30.0);

    //Testing operator []
    sd = marks["Albert Wesker"];
    if (sd.size() == 3 && sd.find(15.0) != sd.end() && sd.find(20.0) != sd.end() && sd.find(30.0) != sd.end()) cout << "operator [] - Test 1 - Passed." << endl;
    else cout << "operator [] - Test 1 - Failed!" << endl;

    sd = marks["Leon Scott Kennedy"];
    if (sd.size() == 0) cout << "operator [] - Test 2 - Passed." << endl;
    else cout << "operator [] - Test 2 - Failed!" << endl;

    //Testing operator =
    Mapping <string, double> marks2 = marks;
    sd = marks2["Albert Wesker"];
    if (sd.size() == 3 && sd.find(15.0) != sd.end() && sd.find(20.0) != sd.end() && sd.find(30.0) != sd.end()) cout << "operator = - Test 1 - Passed." << endl;
    else cout << "operator = - Test 1 - Failed!" << endl;

    sd = marks2["Claire Redfield"];
    if (sd.size() == 0) cout << "operator = - Test 2 - Passed." << endl;
    else cout << "operator = - Test 2 - Failed!" << endl;

    //Testing operator <<
    marks2.clear_item("Albert Wesker");
    marks.add_item("Jill Valentine", 14.85);
    marks.add_item("Jill Valentine", 18.27);
    Mapping <string, double> marks3;

    cout << marks << endl;
    cout << marks2 << endl;
    cout << marks3 << endl;

    //Should print
    //[ Albert Wesker : { 15, 20, 30 }, Chris Redfield : { 8.72, 16.5, 23.5, 32.75 }, Jill Valentine : { 14.85, 18.27 } ]
    //[ Chris Redfield : { 8.72, 16.5, 23.5, 32.75 } ]
    //[  ]
    return 0;
}