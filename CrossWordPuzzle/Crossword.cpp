//
// Created by dogau on 2022-11-08.
//
#include <iostream>
#include <string>
#include "Crossword.h"

using namespace std;

//default constructor
Crossword::Crossword(){
    n_row = n_column = INITIAL_CAP;
    string empty;
    for (int i = 0; i < n_column; ++i) {
        empty.push_back(' ');
    }
    for (int i = 0; i < n_row; ++i) {
        words.push_back(empty);
        answer_key.push_back(empty);
    }
}

//user constructor
Crossword::Crossword(int row,int column){
    string empty;
    for (int i = 0; i < column; ++i) {
        empty.push_back(' ');
    }
    for (int i = 0; i < row; ++i) {
        words.push_back(empty);
        answer_key.push_back(empty);
    }
    this->n_row = row;
    this->n_column = column;
}

string Crossword::checkMatching(int r, int c, bool isHorizontal){
    string actual_answer = "";
    for (int j = 0; j < questions.size(); j++) {
        if((questions[j].row == r && questions[j].column == c) && (questions[j].isHorizontal == isHorizontal)){
            actual_answer = questions[j].answer;
            break;
        }
    }
    return actual_answer;
}

bool Crossword::is_empty(int r, int c, int size, bool isHorizontal){
    if(isHorizontal){
        for (int i = c; i < (size + c); i++) {
            if (words[r - 1][i - 1] != ' ') {
                return false;
            }
        }
    }else{
        for (int i = r; i < (size + r); i++) {
            if (words[i - 1][c - 1] != ' ') {
                return false;
            }
        }
    }
    return true;
}


bool Crossword::add_question(string question, string answer, int r, int c, bool isHorizontal){
    if(r < 1 || r > n_row || c < 1 || c > n_column)
        return false;

    //check if there is enough space for the question at the given place
    int ans_size = answer.size();
    if(isHorizontal){
        if((n_column - c + 1) < ans_size){
            return false;
        }
    }else{
        if((n_row - r + 1) < ans_size){
            return false;
        }
    }

    //check if it does not match with what already exists in the puzzle
    if(isHorizontal){ //horizontal
        for (int i = c; i < (ans_size + c); i++) {
            if(answer_key[r-1][i-1] != ' '){
                if(tolower(answer_key[r-1][i-1]) != tolower(answer[i-c])){
                    return false;
                }
            }
        }
    } else{ //vertical
        for (int i = r; i < (ans_size + r); i++) {
            if(answer_key[i-1][c-1] != ' '){
                if(tolower(answer_key[i-1][c-1]) != tolower(answer[i-r])){
                    return false;
                }
            }
        }
    }

    Solution sol = {r,c,question,answer,isHorizontal};
    questions.push_back(sol);
    insert_to_answer_key(r,c,answer,isHorizontal);
    return true;
}

void Crossword::insert_to_board(int r, int c, string answer, bool isHorizontal){
    int ans_size = answer.size();
    if(isHorizontal){
        int colPos =  c - 1;
        for(char x:answer){
            words[r-1][colPos] = x;
            colPos++;
        }
    }else{
        int rowPos = c - 1;
        int index = 0;
        for(int i=r; i<(r+ans_size);i++){
            words[i-1][rowPos] = answer[index++];
        }
    }
}

void Crossword::insert_to_answer_key(int r, int c, string answer, bool isHorizontal){
    int ans_size = answer.size();
    if(isHorizontal){
        int colPos =  c - 1;
        for(char x:answer){
            answer_key[r-1][colPos] = x;
            colPos++;
        }
    }else{
        int rowPos = c - 1;
        int index = 0;
        for(int i=r; i<(r+ans_size);i++){
            answer_key[i-1][rowPos] = answer[index++];
        }
    }
}

string Crossword::convert_to_lower(string upper){
    string res;
    for (char c:upper){
        res.push_back(tolower(c));
    }
    return res;
}


bool Crossword::solve(int r, int c, string answer){
    //check if the position matches a question
    bool found = false;
    string actual_answer = "";
    bool horizontal;
    for (int i = 0; i < questions.size(); ++i) {
        if(questions[i].row == r && questions[i].column == c){
            found = true;
            actual_answer = questions[i].answer;
            horizontal = questions[i].isHorizontal;
            break;
        }
    }
    if(!found) //no question matched the position of the provided answer
        return false;

    if(convert_to_lower(answer) == convert_to_lower(actual_answer)){ //add to_lower here!!!!!!!!!!!!
        insert_to_board(r, c, actual_answer, horizontal);
        return true;
    }
    return false; //wrong answer
}

ostream& operator <<(ostream& out, Crossword crossword){
    out << "   ";
    for (int i = 0; i < crossword.n_column; i++) {
        out << (i+1) << "  ";
    }
    out << endl;
    for (int i = 0; i < crossword.n_row; i++) {
        out << (i+1) << "  ";
        for (int j = 0; j < crossword.n_column; ++j) {
            out << crossword.words[i][j] << "  ";
        }
        out << endl;
    }
    out << "Questions:" << endl;
    for (int i = 0; i < crossword.questions.size(); ++i) {
        out << "(" << crossword.questions[i].row << "," << crossword.questions[i].column << ")";
        out << "- " << crossword.questions[i].question;
        string hor = (crossword.questions[i].isHorizontal) ? "Horizontal" : "Vertical";
        out  << " (" << hor << ")"<< endl;
    }
    return out;
}