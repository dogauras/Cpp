/*
 * This class is taken from CSI2372 Lectures
 * */
#pragma once
#include <iostream>
#include <list>
using namespace std;

class Node
{
    friend class LinkedList;

    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
    int dummy;
public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();
    bool add_to_front(int);
    bool add_to_back(int);
    int  count_nodes();
    bool insert_item(int, int);
    bool search(int);
    void remove_item(int);
    void remove_from_front();
    void remove_from_back();
    int& operator[](int);
    LinkedList& operator=(const LinkedList);
    friend ostream& operator<<(ostream&, LinkedList&);
};
