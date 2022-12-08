#include <iostream>
#include "Crossword.h"

using namespace std;

int main() {
    Crossword a; //10x10 default
    Crossword w(7,8);
    cout << "Empty board:" << endl << w << endl;

    cout << "Attempt to run function w.add_question(\"What is the capital of Canada ? \", \"Ottawa\", 3, 2, true);" << endl;
    w.add_question("What is the capital of Canada?", "Ottawa", 3, 2, true);
    cout << w << endl;

    cout << "Attempt to run function w.solve(3, 2, \"Toronto\");" << endl;
    w.solve(3,2,"Toronto");
    cout << w << endl;

    cout << "Attempt to run function w.add_question(\"The last name of the current prime minister of Canada ? \", \"Trudeau\", 1, 3, false);"<< endl;
    w.add_question("The last name of the current prime minister of Canada?", "Trudeau", 1, 3, false);
    cout << w << endl;

    cout << "Attempt to run function w.add_question(\"A farm animal covered in wool?\", \"Sheep\", 4, 8, false);" << endl;
    w.add_question("A farm animal covered in wool?", "Sheep", 4, 8, false);
    cout << w << endl;

    cout << "Attempt to run function w.add_question(\"A farm animal covered in wool?\", \"Sheep\", 3, 8, false);" << endl;
    w.add_question("A farm animal covered in wool?", "Sheep", 3, 8, false);
    cout << w << endl;

    cout << "Attempt to run function w.add_question(\"The only flying mammals ? \", \"Bats\", 1, 4, false);" << endl;
    w.add_question("The only flying mammals?", "Bats", 1, 4, false);
    cout << w << endl;

    cout << "Attempt to run function w.solve(3, 2, \"oTtawa\");" << endl;
    w.solve(3,2,"oTtawa");
    cout << w << endl;

    cout << "Attempt to run function w.solve(1, 4, \"bats\");" << endl;
    w.solve(1, 4, "bats");
    cout << w << endl;

    cout << "Attempt to run function w.solve(3, 8, \"SHEEP\");" << endl;
    w.solve(3,8, "Sheep");
    cout << w << endl;

    return 0;
}
