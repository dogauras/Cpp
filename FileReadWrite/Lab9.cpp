// Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


struct student {
    string firstname;
    string lastname;
    int studentNo;
    double lab;
    double a1, a2, a3, a4, a5;
    double test;
    double midterm;
    double final;
    double grade;
    string letterGrade;
};

string letter_grade(double final_mark) {
    if (final_mark >= 90) {
        return "A+";
    }
    else if (85 <= final_mark && final_mark < 90) {
        return "A ";
    }
    else if (80 <= final_mark && final_mark < 85) {
        return "A-";
    }
    else if (75 <= final_mark && final_mark < 80) {
        return "B+";
    }
    else if (70 <= final_mark && final_mark < 75) {
        return "B ";
    }
    else if (65 <= final_mark && final_mark < 70) {
        return "C+";
    }
    else if (60 <= final_mark && final_mark < 65) {
        return "C ";
    }
    else if (55 <= final_mark && final_mark < 60) {
        return "D+";
    }
    else if (50 <= final_mark && final_mark < 55) {
        return "D ";
    }
    else if (40 <= final_mark && final_mark < 50) {
        return "E ";
    }
    else {
        return "F ";
    }
}

void print_student(student st) {
    cout << "{ " << st.firstname << " " << st.lastname << ", " << st.studentNo << endl << "Labs= " << st.lab << "\nA1= " << st.a1 << "\nA2= " << st.a2 << "\nA3= " << st.a3
        << "\nA4= " << st.a4 << "\nA5= " << st.a5 << "\nTerm Test= " << st.test
        << "\nMidterm= " << st.midterm << "\nFinal=  " << st.final;
    if (st.letterGrade != "")
        cout << "\nFinal Grade= " << st.grade << "\nFinal Letter Grade= " << st.letterGrade;
    cout << " }" << endl;
    cout << endl;
}

int main()
{
    //Read file
    ifstream fin;
    fin.open("CSI2372.info", ios::binary | ios::in);
    if (!fin.is_open())
    {
        cout << "File not found!" << endl;
        return 0;
    }

    student s1;
    string s;
    vector<student> all;
    while (!fin.eof())
    {
        //Read first name and last name
        student s1;
        for (int i = 0; i < 2; i++)
        {
            getline(fin, s, ';');
            if (i == 0) {
                s1.firstname = s.c_str();
            }
            else if (i == 1) {
                s1.lastname = s.c_str();
            }
        }

        /*if (fin.eof())
            break;*/

        
        //Read grades
        fin.read((char*)&s1.studentNo, sizeof(int));
        fin.read((char*)&s1.lab, sizeof(double));
        fin.read((char*)&s1.a1, sizeof(double));
        fin.read((char*)&s1.a2, sizeof(double));
        fin.read((char*)&s1.a3, sizeof(double));
        fin.read((char*)&s1.a4, sizeof(double));
        fin.read((char*)&s1.a5, sizeof(double));
        fin.read((char*)&s1.test, sizeof(double));
        fin.read((char*)&s1.midterm, sizeof(double));
        fin.read((char*)&s1.final, sizeof(double));

        all.push_back(s1);
    }

    //Print read data
    cout << "#### Reading CSI2372.info ####" << endl;
    for (int i = 0; i < all.size(); i++)
    {
        print_student(all[i]);
    }
   
    fin.close();
    cout << endl;
    

    //Creating CSI2372_final.info
    cout << "#### Writing to CSI2372_final.info ####" << endl;
    fstream frw("CSI2372_final.info", ios::binary | ios::out); //opening a file for reading and writing

    if (!frw.is_open())
    {
        cout << "File not found!" << endl;
        frw.close();
        return 0;
    }

    vector<student> toWrite;
    for (int i = 0; i < all.size(); i++)
    {

        student st;
        st.firstname = all[i].firstname;
        st.lastname = all[i].lastname;
        st.studentNo = all[i].studentNo;
        st.lab = all[i].lab;
        st.a1 = (all[i].a1 * 5) / 30;
        st.a2 = (all[i].a2 * 5) / 30;
        st.a3 = (all[i].a3 * 5) / 30;
        st.a4 = (all[i].a4 * 5) / 30;
        st.a5 = (all[i].a5 * 5) / 30;
        st.test = all[i].test;
        st.midterm = all[i].midterm;
        st.final = all[i].final;
        st.grade = st.lab + st.a1 + st.a2 + st.a3 + st.a4 + st.a5 + st.test + st.midterm + st.final;
        st.letterGrade = letter_grade(st.grade);

        //write len of first name followed by first name
        int len = st.firstname.size();
        frw.write((char*)&len, sizeof(int));
        frw.write(st.firstname.c_str(), len);

        //write len of last name followed by last name
        len = st.lastname.size();
        frw.write((char*)&len, sizeof(int));
        frw.write(st.lastname.c_str(), len);

        //write marks
        frw.write((char*)&st.studentNo, sizeof(int));
        frw.write((char*)&st.lab, sizeof(double));
        frw.write((char*)&st.a1, sizeof(double));
        frw.write((char*)&st.a2, sizeof(double));
        frw.write((char*)&st.a3, sizeof(double));
        frw.write((char*)&st.a4, sizeof(double));
        frw.write((char*)&st.a5, sizeof(double));
        frw.write((char*)&st.test, sizeof(double));
        frw.write((char*)&st.midterm, sizeof(double));
        frw.write((char*)&st.final, sizeof(double));
        frw.write((char*)&st.grade, sizeof(double));
        frw.write(st.letterGrade.c_str(), st.letterGrade.size()); //exactly 2 characters

        toWrite.push_back(st);
    }


    for (int i = 0; i < toWrite.size(); i++)
    {
        print_student(toWrite[i]);
    }

    frw.close();
    cout << endl;
    


    //Rread CSI2372_final.info to make sure the file is written as expected
    cout << "#### Reading CSI2372_final.info ####" << endl;
    fstream frr("CSI2372_final.info", ios::binary | ios::in); //opening a file for reading and writing

    if (!frr.is_open())
    {
        cout << "File not found!" << endl;
        return 0;
    }

    vector<student> readAll;
    char buffer[100]; // temp buffer for strings
    int len = 0;

    student strec;

    while (!frr.eof()) {

        frr.read((char*)&len, sizeof(int));

        if (frr.eof()) break; 

        frr.read(buffer, len);
        buffer[len] = 0;
        strec.firstname = buffer;
        frr.read((char*)&len, sizeof(int));
        frr.read(buffer, len);
        buffer[len] = 0;
        strec.lastname = buffer;

        frr.read((char*)&(strec.studentNo), sizeof(int));
        frr.read((char*)&(strec.lab), sizeof(double));
        frr.read((char*)&(strec.a1), sizeof(double));
        frr.read((char*)&(strec.a2), sizeof(double));
        frr.read((char*)&(strec.a3), sizeof(double));
        frr.read((char*)&(strec.a4), sizeof(double));
        frr.read((char*)&(strec.a5), sizeof(double));
        frr.read((char*)&(strec.test), sizeof(double));
        frr.read((char*)&(strec.midterm), sizeof(double));
        frr.read((char*)&(strec.final), sizeof(double));
        frr.read((char*)&(strec.grade), sizeof(double));
        frr.read(buffer, 2);
        buffer[2] = 0;
        strec.letterGrade = buffer;


        readAll.push_back(strec);
    }

    frr.close();

    for (int i = 0; i < readAll.size(); i++)
    {
        print_student(readAll[i]);
    }
  

    return 0;
}


