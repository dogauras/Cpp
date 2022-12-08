#pragma once
#include <iostream>
using namespace std;

class Node
{
	friend class DoubleLinkedList;

	int data;
	Node* next;
	Node* previous;
	//void* operator new[](size_t);
};

class DoubleLinkedList
{
private:
	int size;
	Node* head;
	Node* tail;
	int dummy;
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList&);
	~DoubleLinkedList();
	int  count_nodes();
	bool add_to_front(int);
	bool add_to_back(int);
	bool insert_item(int, int);
	void remove_item(int);
	void remove_from_front();
	void remove_from_back();
	int& operator[](int);
	friend ostream& operator <<(ostream& out, DoubleLinkedList list);
};