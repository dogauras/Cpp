//
// Created by dogau on 2022-11-30.
//

#include <iostream>
#include <vector>
#include "Poker.h"

using namespace std;

class TexasHoldem : public Poker{
private:
    string int_to_outcome(int); //helper
public:
    TexasHoldem();
    TexasHoldem(int);
    void deal();
    vector<string> hands();
    int best_outcome(vector<string> cards); //helper
    void print_hands(); //helper
};
