#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

//default constructor
DoubleLinkedList::DoubleLinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
	dummy = 0;
}

//copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& list)
{
	head = list.head;
	tail = list.tail;
	size = list.size;
	dummy = list.dummy;
}

//destructor
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = head;
	while (current != NULL)
	{
		Node* temp = current;
		current = current->next;
		temp = NULL;
	}
	head = NULL;
	tail = NULL;
}

bool DoubleLinkedList::add_to_front(int x)
{
	Node* new_node = new Node;
	if (new_node == NULL)
		return false;
	
	new_node->data = x;
	new_node->previous = NULL;
	size += 1;

	//no element present in the list
	if (head == NULL && tail == NULL)
	{
		tail = new_node;
		head = new_node;
		return true;
	}

	new_node->next = head;
	head->previous = new_node;
	head = new_node;

	return true;
}

bool DoubleLinkedList::add_to_back(int x)
{
	Node* new_node = new Node;
	if (new_node == NULL)
		return false;

	new_node->data = x;
	new_node->next = NULL; 
	size += 1;

	//no elements in the list
	if (head == NULL && tail == NULL)
	{
		tail = new_node;
		head = new_node;
		return true;
	}

	new_node->previous = tail;
	tail->next = new_node;
	tail = new_node;

	return true;
}


bool DoubleLinkedList::insert_item(int pos, int x)
{
	//validate pos
	if (pos < 0 || pos > size) {
		return false;
	}

	if (pos == 0)
		return add_to_front(x);

	if (pos == size)
		return add_to_back(x);
	
	Node* new_node = new Node;
	if (new_node == NULL)
		return false;

	new_node->data = x;
	new_node->next = NULL;
	new_node->previous = NULL;

	Node* current = head;
	for (int i = 0; i < pos - 1; ++i)
		current = current->next;

	new_node->next = current->next;
	new_node->previous = current;
	current->next = new_node;
	(current->next)->previous = new_node;
	size += 1;
	return true;
}

int DoubleLinkedList::count_nodes()
{
	int c = 0;
	Node* current;

	for (current = head; current != NULL; current = current->next)
	{
		c++;
	}	
	return c;
}

void DoubleLinkedList::remove_item(int x)
{
	if (head == NULL) {
		return;
	}

	if (head->data == x)
	{
		remove_from_front();
		return;
	}

	if (tail->data == x)
	{
		remove_from_back();
		return;
	}

	Node* current;
	for (current = head; current->next != NULL; current = current->next)
	{
		if (current->data == x)
		{
			Node* temp = current;
			current->previous->next = current->next;
			current->next->previous = current->previous;
			
			delete temp;
			size -= 1;
			return;
		}
	}
}

void DoubleLinkedList::remove_from_front()
{
	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		head = NULL;
		tail = NULL;
		size -= 1;
		return;
	}

	Node* temp = head;

	//If we do not check head is NULL, NULL pointer exception
	head = head->next;
	head->previous = NULL;
	size -= 1;
	delete temp;
}



void DoubleLinkedList::remove_from_back()
{
	if (tail == NULL)
		return;

	//only one element present
	if (tail->previous == NULL)
	{
		head = NULL;
		tail = NULL;
		size -= 1;
		return;
	}

	Node* temp = tail;

	tail = tail->previous;
	tail->next = NULL; 
	size -=1;
	delete temp;
}

int& DoubleLinkedList::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		cout << "Index out of range!" << endl;
		return dummy;
	}

	Node* current = head;
	for (int i = 0; i < index; ++i)
		current = current->next;

	return current->data;
}

ostream& operator <<(ostream& out, DoubleLinkedList list) {
	if (list.size == 0) return out;
	
	for (int i = 0; i < list.size - 1; i++) {
		out << list[i] << " ,";
	}
	out << list[list.size-1];
	return out; 
}


