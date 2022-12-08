//
// Created by dogau on 2022-11-30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "TexasHoldem.h"

using namespace std;

TexasHoldem::TexasHoldem() : Poker(){

}

TexasHoldem::TexasHoldem(int num_player) : Poker(num_player){
    cout << "Shuffled Deck: ";
    print_cards(deck); //to make sure cards are shuffled
}

void TexasHoldem::deal(){
    for (int i = 0; i < num_player; ++i) {
        //deal two cards to each player
        add_card(i);
        add_card(i);
    }
    //deal 5 cards to the table
    for (int i = 0; i < 5; ++i) {
        add_to_table();
    }

    cout << "Cards on Table: ";
    print_cards(cards_table);
}

vector<string> TexasHoldem::hands(){
    vector<string> ret;
    for (int i = 0; i < num_player; ++i) {
        vector <string> cards; //place all cards on the table and in the hand of the player into this vector
        cards.insert(cards.end(), cards_table.begin(), cards_table.end());
        cards.insert(cards.end(),cards_hand[i].begin(),cards_hand[i].end());

        vector <int> select(7);
        select[0] = select[1] = 0;
        select[2] = select[3] = select[4] = select[5] = select[6] = 1;
        int best = 8;
        do
        {
            vector <string> pick;
            for(int i = 0; i < 7; ++i)
                if (select[i] == 1) pick.push_back(cards[i]);

            //pick is one possible selection, you can check it here
            int outcome = best_outcome(pick);
            if(outcome < best) best = outcome; //update outcome if found something better
        }
        while(next_permutation(select.begin(), select.end()));

        ret.push_back(int_to_outcome(best));
    }
    return ret;
}

int TexasHoldem::best_outcome(vector<string> cards){
    if(IsStraightFlush(cards)){
        return 0;
    }else if(IsFourofaKind(cards)){
        return 1;
    }else if(IsFullHouse(cards)){
        return 2;
    }else if(IsFlush(cards)){
        return 3;
    }else if(IsStraight(cards)){
        return 4;
    }else if(IsThreeofaKind(cards)){
        return 5;
    }else if(IsTwoPairs(cards)){
        return 6;
    }else if(IsOnePair(cards)){
        return 7;
    }else{
        return 8; //high card
    }
}

string TexasHoldem::int_to_outcome(int n){
    switch(n){
        case 0:
            return "Straight Flush";
        case 1:
            return "Four of a Kind";
        case 2:
            return "Full House";
        case 3:
            return "Flush";
        case 4:
            return "Straight";
        case 5:
            return "Three of a Kind";
        case 6:
            return "Two Pairs";
        case 7:
            return "One Pair";
        case 8:
            return "High Card";
    }
}

void TexasHoldem::print_hands(){
    for (int i = 0; i < num_player; ++i) {
        cout << "Player " << i << " = ";
        print_cards(cards_hand[i]);
    }
}