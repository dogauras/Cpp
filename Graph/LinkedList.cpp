/*
 * This class is taken from CSI2372 Lectures
 * */
#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    dummy = 0;
}

LinkedList::LinkedList(const LinkedList& list) {
    head = list.head;
    dummy = list.dummy;
}

LinkedList::~LinkedList()
{
    if (head == NULL)
        return;

    Node* current = head;

    while (current != NULL)
    {
        Node* temp = current;
        current = current->next;
        temp = NULL;
    }
    head = NULL;
}

bool LinkedList::add_to_front(int x)
{
    //Allocating memory for one node using a pointer to a node
    Node* new_node = new Node;

    if (new_node == NULL)
        return false;

    new_node->data = x;
    new_node->next = head;
    head = new_node;

    return true;
}

bool LinkedList::add_to_back(int x)
{
    //Allocating memory for one node using a pointer to a node
    int n;

    n = count_nodes();
    if (n == 0)
        return add_to_front(x);

    return insert_item(n, x);
}

bool LinkedList::search(int x)
{
    Node* current;

    for (current = head; current != NULL; current = current->next)
        if (current->data == x) return true;

    return false;
}

bool LinkedList::insert_item(int pos, int x)
{
    int i;
    Node* current;
    Node* new_node;
    if (pos == 0)
        return add_to_front(x);

    //Allocating memory for one node to be added
    //to the linked list
    new_node = new Node;

    if (new_node == NULL)
        return false;

    new_node->data = x;
    new_node->next = NULL;

    current = head;
    for (i = 0; i < pos - 1; ++i)
        current = current->next;

    new_node->next = current->next;
    current->next = new_node;

    return true;
}

int LinkedList::count_nodes()
{
    int c = 0;
    Node* current;

    for (current = head; current != NULL; current = current->next) {
        ++c;
    }
    return c;
}

void LinkedList::remove_from_front()
{
    if (head == NULL)
        return;

    Node* temp = head;

    //If we do not check head is NULL
    //NULL pointer exception
    head = head->next;
    delete temp;
}

void LinkedList::remove_item(int x)
{
    if (head == NULL)
        return;

    if (head->data == x)
    {
        remove_from_front();
        return;
    }

    Node* current;
    for (current = head; current->next != NULL; current = current->next)
    {
        if (current->next->data == x)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            break;
        }
    }
}

void LinkedList::remove_from_back()
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        remove_from_front();
        return;
    }

    Node* current;
    for (current = head; current->next->next != NULL; current = current->next);

    Node* temp = current->next;
    current->next = NULL;
    delete temp;
}

int& LinkedList::operator[](int index)
{
    int i, n = count_nodes();

    if (index < 0 || index >= n)
    {
        cout << "Index out of range!" << endl;
        return dummy;
    }

    Node* current = head;
    for (i = 0; i < index; ++i)
        current = current->next;

    return current->data;
}

LinkedList& LinkedList::operator=(const LinkedList list) {
    head = list.head;
    dummy = list.dummy;
    return *this;
}

ostream& operator<<(ostream& out, LinkedList& list)
{
    int n = list.count_nodes();
    for (int i = 0; i < n; ++i)
    {
        if (i != 0) out << ",";
        out << list[i];
    }
    return out;
}

