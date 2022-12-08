//
// Created by dogau on 2022-11-29.
//

#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include "Poker.h"

using namespace std;

Poker::Poker(){
    //cout << "default constructor of Poker!" << endl;
    num_player = 2;
    vector<string> empty = {};
    for (int i = 0; i < ranks.size(); ++i) {
        for (int j = 0; j < suits.size(); ++j) {
            deck.push_back(ranks[i]+suits[j]);
        }
    }
    //randomize the deck
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(),default_random_engine(seed));
    for (int i = 0; i < num_player; ++i) {
        cards_hand.push_back(empty);
    }
    cards_table = empty;
}

Poker::Poker(int num){
    //cout << "user constructor of Poker!" << endl;
    num_player = num;
    vector<string> empty = {};
    for (int i = 0; i < ranks.size(); ++i) {
        for (int j = 0; j < suits.size(); ++j) {
            deck.push_back(ranks[i]+suits[j]);
        }
    }
    //randomize the deck
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(),default_random_engine(seed));
    for (int i = 0; i < num_player; ++i) {
        cards_hand.push_back(empty);
    }
    cards_table = empty;
}

//receives the index of a player and adds the top card on the deck to the hand of that playe
bool Poker::add_card(int player){
    if(player >= num_player){
        cout << "Player doesn't exist!" << endl;
        return false;
    }
    if(deck.size() > 0){
        cards_hand[player].push_back(deck.back());
        deck.pop_back();
        return true;
    }
    return false;
}

bool Poker::add_to_table(){
    if(deck.size() > 0){
        cards_table.push_back(deck.back());
        deck.pop_back();
        return true;
    }
    return false;
}

// returns true if all cards are from the same suit and their ranks is in order
bool Poker::IsStraightFlush(vector<string> cards){
    if(!IsFlush(cards))
        return false;

    //we know the cards are of same suit
    vector<string> sorted = insertionSort(cards);
    //print_cards(sorted);
    for (int i = 0; i < cards.size() - 2; ++i) {
        if(rank_values.find(string{sorted[i][0]})->second + 1 != rank_values.find(string{sorted[i+1][0]})->second)
            return false;
    }
    if(sorted[cards.size()-1][0] == 'A'){
        if(sorted[0][0] != '2' && sorted[cards.size()-2][0] != 'K') return false;
    }
    return true;
}

// returns true if there are four cards of the same rank
bool Poker::IsFourofaKind(vector<string> cards){
    for (int i = 0; i < cards.size() - 1; ++i) {
        if(cards[i][0] != cards[i+1][0]) return false;
    }
    return true;
}

// returns true if there are three cards of the same rank and two cards of another rank
bool Poker::IsFullHouse(vector<string> cards){
    set<char> unique_rank;
    for (int i = 0; i < cards.size(); ++i) {
        unique_rank.insert(cards[i][0]);
    }
    return (unique_rank.size() == 2);
}

// returns true if all five cards have the same suit
bool Poker::IsFlush(vector<string> cards){
    for (int i = 0; i < cards.size() - 1; ++i) {
        if(cards[i][1] != cards[i+1][1])
            return false;
    }
    return true;
}

// returns true if the five cards are in the order of their rank, suits are not important
bool Poker::IsStraight(vector<string> cards){
    vector<string> sorted = insertionSort(cards); //sorts by rank
    for (int i = 0; i < cards.size() - 2; ++i) {
        if(rank_values.find(string{sorted[i][0]})->second + 1 != rank_values.find(string{sorted[i+1][0]})->second)
            return false;
    }
    if(sorted[cards.size()-1][0] == 'A'){
        if(sorted[0][0] != '2' && sorted[cards.size()-2][0] != 'K') return false;
    }else{
        if(rank_values.find(string{sorted[cards.size()-2][0]})->second + 1 != rank_values.find(string{sorted[cards.size()-1][0]})->second)
            return false;
    }
    return true;
}

// returns true if there are three cards of the same rank
bool Poker::IsThreeofaKind(vector<string> cards){
    map<char,int> unique_rank;
    for (int i = 0; i < cards.size(); ++i) {
        ++unique_rank[cards[i][0]];
    }
    for (auto c:unique_rank) {
        if(c.second == 3) return true;
    }
    return false;
}

//returns true if there are two pairs of cards of the same rank
bool Poker::IsTwoPairs(vector<string> cards){
    map<char,int> unique_rank;
    for (int i = 0; i < cards.size(); ++i) {
        ++unique_rank[cards[i][0]];
    }
    if(unique_rank.size() != 3) return false;
    for (auto c:unique_rank) {
        if(c.second != 2 && c.second != 1) return false;
    }
    return true;
}

//returns true if there is a pair of cards of the same rank
bool Poker::IsOnePair(vector<string> cards){
    map<char,int> unique_rank;
    for (int i = 0; i < cards.size(); ++i) {
        ++unique_rank[cards[i][0]];
    }
    for (auto c:unique_rank) {
        if(c.second == 2) return true;
    }
    return false;
}

void Poker::print_cards(vector<string> cards){
    cout << "{";
    for (int i = 0; i < cards.size(); ++i) {
        if(i == cards.size()-1){
            cout << cards[i] << "}" << endl;
            return;
        }
        cout << cards[i] << ",";
    }
}

//sorts cards by rank
vector<string> Poker::insertionSort(vector<string> cards)
{
    int i, j;
    string key;
    int n = cards.size();
    for (i = 1; i < n; i++)
    {
        key = cards[i];
        j = i - 1;
        while (j >= 0 && rank_values.find(string{cards[j][0]})->second > rank_values.find(string{key[0]})->second)
        {
            cards[j + 1] = cards[j];
            j = j - 1;
        }
        cards[j + 1] = key;
    }
    return cards;
}

