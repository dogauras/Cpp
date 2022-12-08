//
// Created by dogau on 2022-11-29.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

const vector<string> suits = {"D","C","S","H"};
const vector<string> ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
const map<string,int> rank_values = {{"2",2}, {"3",3}, {"4",4}, {"5",5}, {"6",6}, {"7",7}, {"8",8}, {"9",9}, {"T",10}, {"J",11}, {"Q",12}, {"K",13}, {"A",14}}; //used for sorting purposes only

class Poker{
protected:
    int num_player; //the number of players
    vector<vector<string>> cards_hand; //The list of cards in the hand of each player
    vector<string> cards_table; //The list of cards on the table.
    vector<string> deck; //You also need to hold the deck of cards.
    vector<string> insertionSort(vector<string>); //helper to sort cards by rank
public:
    Poker();
    Poker(int);
    bool add_card(int);
    bool add_to_table();
    bool IsStraightFlush(vector<string>); // returns true if all cards are from the same suit and their ranks is in order
    bool IsFourofaKind(vector<string>); // returns true if there are four cards of the same rank
    bool IsFullHouse(vector<string>); // returns true if there are three cards of the same rank and two cards of another rank
    bool IsFlush(vector<string>); // returns true if all five cards have the same suit
    bool IsStraight(vector<string>); // returns true if the five cards are in the order of their rank, suits are not important
    bool IsThreeofaKind(vector<string>); // returns true if there are three cards of the same rank
    bool IsTwoPairs(vector<string>); //returns true if there are two pairs of cards of the same rank
    bool IsOnePair(vector<string>); //returns true if there is a pair of cards of the same rank
    void print_cards(vector<string>);
};
