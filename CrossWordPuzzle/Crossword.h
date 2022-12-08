//
// Created by dogau on 2022-11-08.
//
#include <iostream>
#include <vector>
#include <string>

#define INITIAL_CAP 10

using namespace std;

struct Solution{
    int row, column;
    string question;
    string answer;
    bool isHorizontal;
};

class Crossword{
private:
    vector<string> words;
    vector<string> answer_key;
    vector<Solution> questions;
    int n_row, n_column; //number of rows and columns of the board

    string checkMatching(int,int,bool); //helper
    bool is_empty(int,int,int,bool); //helper
    string convert_to_lower(string); //helper
    void insert_to_board(int,int,string,bool); //helper
    void insert_to_answer_key(int,int,string,bool); //helper
public:
    Crossword(); //default constructor
    Crossword(int,int); //user constructor
    bool add_question(string, string, int, int, bool);
    bool solve(int, int, string);
    friend ostream& operator <<(ostream&, Crossword);
};