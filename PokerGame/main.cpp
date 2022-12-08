#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "TexasHoldem.h"


using namespace std;

int main() {
    Poker p;
    Poker(3);

    //Testing IsStraightFlush
    vector<string> cards {"AH", "2H", "3H", "4H", "5H"};
    vector<string> cards1 {"TS", "JS", "QS", "KS", "AS"};
    vector<string> cards2 {"7D", "9D", "JD", "TD", "8D"};
    vector<string> cards3 {"8C", "9C", "TC", "2C", "3C"};

    if (p.IsStraightFlush(cards) == 1) cout << "IsStraightFlush - Test 1 - Passed." << endl;
    else cout << "IsStraightFlush - Test 1 - Failed!" << endl;

    if (p.IsStraightFlush(cards1) == 1) cout << "IsStraightFlush - Test 2 - Passed." << endl;
    else cout << "IsStraightFlush - Test 2 - Failed!" << endl;

    if (p.IsStraightFlush(cards2) == 1) cout << "IsStraightFlush - Test 3 - Passed." << endl;
    else cout << "IsStraightFlush - Test 3 - Failed!" << endl;

    if (p.IsStraightFlush(cards3) == 0) cout << "IsStraightFlush - Test 4 - Passed." << endl;
    else cout << "IsStraightFlush - Test 4 - Failed!" << endl;

    //Testing IsFourofaKind
    vector<string> c1 = {"9H", "9S", "9D", "9C", "9S"};
    vector<string> c2 = {"2H", "6S", "5H", "8C", "9S"};

    if (p.IsFourofaKind(c1) == 1) cout << "IsFourofaKind - Test 1 - Passed." << endl;
    else cout << "IsFourofaKind - Test 1 - Failed!" << endl;

    if (p.IsFourofaKind(c2) == 0) cout << "IsFourofaKind - Test 2 - Passed." << endl;
    else cout << "IsFourofaKind - Test 2 - Failed!" << endl;

    //Testing IsFullHouse
    vector<string> c3 = {"JH", "7S", "7D", "JD", "JC"};
    vector<string> c4 = {"2H", "6D", "5D", "8C", "8S"};

    if (p.IsFullHouse(c3) == 1) cout << "IsFullHouse - Test 1 - Passed." << endl;
    else cout << "IsFullHouse - Test 1 - Failed!" << endl;

    if (p.IsFullHouse(c4) == 0) cout << "IsFullHouse - Test 2 - Passed." << endl;
    else cout << "IsFullHouse - Test 2 - Failed!" << endl;

    //Testing IsFlush
    vector<string> c5 = {"JH", "7H", "8H", "2H", "5H"};
    vector<string> c6 = {"3D", "6D", "3H", "8C", "8S"};

    if (p.IsFlush(c5) == 1) cout << "IsFlush - Test 1 - Passed." << endl;
    else cout << "IsFlush - Test 1 - Failed!" << endl;

    if (p.IsFlush(c6) == 0) cout << "IsFlush - Test 2 - Passed." << endl;
    else cout << "IsFlush - Test 2 - Failed!" << endl;

    //Testing IsStraight
    vector<string> c7 = {"AD", "2S", "3D", "4C", "5H"};
    vector<string> c8 = {"TS", "JS", "QH", "KH", "AC"};
    vector<string> c9 = {"7S", "9D", "JD", "TH", "8H"};
    vector<string> c10 = {"8C", "9D", "TC", "2D", "3H"};

    if (p.IsStraight(c7) == 1) cout << "IsStraight - Test 1 - Passed." << endl;
    else cout << "IsStraight - Test 1 - Failed!" << endl;

    if (p.IsStraight(c8) == 1) cout << "IsStraight - Test 2 - Passed." << endl;
    else cout << "IsStraight - Test 2 - Failed!" << endl;

    if (p.IsStraight(c9) == 1) cout << "IsStraight - Test 3 - Passed." << endl;
    else cout << "IsStraight - Test 3 - Failed!" << endl;

    if (p.IsStraight(c10) == 0) cout << "IsStraight - Test 4 - Passed." << endl;
    else cout << "IsStraight - Test 4 - Failed!" << endl;


    //Testing IsThreeofaKind
    vector<string> c11 = {"TH", "6S", "TD", "TC", "QS"};
    vector<string> c12 = {"2H", "6S", "KH", "8C", "QS"};

    if (p.IsThreeofaKind(c11) == 1) cout << "IsThreeofaKind - Test 1 - Passed." << endl;
    else cout << "IsThreeofaKind - Test 1 - Failed!" << endl;

    if (p.IsThreeofaKind(c12) == 0) cout << "IsThreeofaKind - Test 2 - Passed." << endl;
    else cout << "IsThreeofaKind - Test 2 - Failed!" << endl;

    //Testing IsOnePair
    vector<string> c13 = {"TH", "6S", "AS", "KC", "KD"};
    vector<string> c14 = {"2H", "6S", "9H", "8C", "QS"};

    if (p.IsOnePair(c13) == 1) cout << "IsOnePair - Test 1 - Passed." << endl;
    else cout << "IsOnePair - Test 1 - Failed!" << endl;

    if (p.IsOnePair(c14) == 0) cout << "IsOnePair - Test 2 - Passed." << endl;
    else cout << "IsOnePair - Test 2 - Failed!" << endl;

    cout << endl;

    TexasHoldem texas;
    TexasHoldem texas1(3);
    texas1.deal();
    //texas1.deal();
    texas1.print_hands();

    vector<string> outcome = texas1.hands();
    cout << "[";
    for (int i=0; i<outcome.size();++i){
        if(i == outcome.size() - 1)
            cout << outcome[i] << "]";
        else
            cout << outcome[i] << ", ";
    }

    return 0;
}
