/*
*  Author: Doga Uras
*  This class design is for the concept of directed graphs
*/

#include <iostream>
#include <list> //used for return type for bonus BFS and DFS, I could have also returned void and print in the function
#include "LinkedList.h"

#define INITIAL_CAP 10 //initial capacity

using namespace std;

class Graph {
private:
    int capacity; //capacity of the 'dynamic' array
    int n; //current length of the vertices array
    LinkedList* vertices; //dynamic array of linked lists, each index represents a vertex

    bool add_vertex(); //helper
    void remove_vertex(); //helper
    void DFS_recursive(int, bool[], list<int>&); //helper function for DFS()
    int** create_path_matrix(); //helper function for connectivity_type()

public:
    Graph();
    Graph(int);
    Graph(const Graph&);
    ~Graph();
    bool add_edge(int, int);
    void remove_edge(int, int);
    bool edge_exist(int, int);
    int get_degree(int);
    Graph operator ++(); //prefix increment
    Graph operator ++(int); //postfix increment
    Graph operator --(); //prefix decrement
    Graph operator --(int); //postfix decrement
    bool path_exist(int, int);
    int connectivity_type();
    list<int> BFS(int); // returns a list containing the traversal nodes, I could have just printed in the function as well
    list<int> DFS(int); // returns a list containing the traversal nodes, I could have just printed in the function as well
    friend ostream& operator <<(ostream&, Graph);

};

