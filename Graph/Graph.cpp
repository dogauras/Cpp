/*
*  Author: Doga Uras
*  This class design is for the concept of directed graphs
*/

#include <iostream>
#include <list> //used for bonus BFS and DFS
#include "Graph.h"

using namespace std;

//default constructor
Graph::Graph() {
    n = INITIAL_CAP; //for n=10, vertices array [1,2,3,4,5,6,7,8,9,10]
    vertices = new LinkedList[INITIAL_CAP]; //no edges
    capacity = INITIAL_CAP;
}

//user constructor
Graph::Graph(int num) {
    n = num;  //num number of nodes in vertices array
    vertices = new LinkedList[num]; //no edges
    capacity = num;
    if (vertices == NULL) {
        cout << "Not enough memory" << endl;
    }
}

//copy constructor
Graph::Graph(const Graph& graph) {
    vertices = new LinkedList[graph.capacity];
    if (vertices == NULL) {
        cout << "Not enough memory" << endl;
    }
    n = graph.n;
    for (int i = 0; i < graph.n; i++)
    {
        vertices[i] = graph.vertices[i];
    }
    capacity = graph.capacity;
}

//destructor
Graph::~Graph() {
    delete[] vertices;
}

//Add an edge between two given vertices
bool Graph::add_edge(int v1, int v2) {

    //vertices must be from 1 to n
    if (v1 < 1 || v1 > n || v2 < 1 || v2 > n) {
        return false;
    }

    // v2 is already in the edges list of v1
    if (vertices[v1 - 1].search(v2))
        return false;

    return vertices[v1 - 1].add_to_back(v2);
}

void Graph::remove_edge(int v1, int v2) {
    //it will remove v2 from the list if it exists,
    //otherwise it does nothing
    vertices[v1 - 1].remove_item(v2);
}

// this will check if there is an edge from v1->v2
// since it is a directed graph, it must be v1->v2
bool Graph::edge_exist(int v1, int v2) {
    if (v1 < 1 || v1 > n) {
        return false;
    }
    return vertices[v1 - 1].search(v2);
}

//returns the number of adjacent(connected) vertices of the given vertex
//returns -1 if the vertex does not belong to the graph
int Graph::get_degree(int v) {
    // vertex is out of range (1 to n)
    if (v < 1 || v > n)
        return -1;
    return vertices[v - 1].count_nodes();
}

// adds n+1 to the vertices array
bool Graph::add_vertex() {
    if (n == capacity) {
        int new_cap = capacity + INITIAL_CAP / 2;
        LinkedList* temp = new LinkedList[new_cap]; //re-allocate memory
        capacity = new_cap;
        if (temp == NULL) {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            temp[i] = vertices[i];
        }
        delete[] vertices; //free the memory directions used to point at
        vertices = temp;
    }
    n++;
    return true;
}

//removes the last vertex, if there is at least one vertex, does nothing otherwise
void Graph::remove_vertex() {
    if (n > 0) {

        //need to remove the vertex from the LinkedLists as well
        for (int i = 0; i < n - 1; i++)
        {
            vertices[i].remove_item(n); //does nothing if n is not in the list
        }
        n--;
    }
    else {
        cout << "Graph does not contain any vertex!" << endl;
    }
}

//prefix increment
Graph Graph::operator ++() {
    this->add_vertex();
    return *this;
}
//postfix increment
Graph Graph::operator ++(int) {
    Graph old = *this;
    ++(*this); //use prefix implementation
    return old;
}

//prefix decrement
Graph Graph::operator --() {
    this->remove_vertex();
    return *this;
}

//postfix decrement
Graph Graph::operator --(int) {
    Graph old = *this;
    --(*this); //use prefix implementation
    return old;
}


//checks if a path exists between two given vertices
//uses BFS algorithm
bool Graph::path_exist(int v1, int v2) {
    if (v1 == v2)
        return true;

    bool* visited = new bool[n];
    //initially, all vertices are not-visited
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    //BFS queue
    list<int> queue;

    //mark current node as visited and enqueue it
    visited[v1 - 1] = true;
    queue.push_back(v1);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue
        v1 = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex v1
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        LinkedList edges = vertices[v1 - 1];
        for (int i = 0; i < edges.count_nodes(); i++)
        {
            // If the current adjacent node is the destination node(v2), return true
            if (edges[i] == v2)
                return true;

            // continue with BFS
            if (!visited[edges[i] - 1])
            {
                visited[edges[i] - 1] = true;
                queue.push_back(edges[i]);
            }
        }
    }
    //if BFS is done without having visited v2, return false
    return false;
}

//Returns a list of integers, representing the breadth first traversal of the
//graph starting from a given node
list<int> Graph::BFS(int v1) {
    list<int> res;

    bool* visited = new bool[n];
    //initially, all vertices are not-visited
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    //queue for BFS
    list<int> queue;

    //marks the current node as visited and enqueues it
    visited[v1 - 1] = true;
    queue.push_back(v1);

    while (!queue.empty())
    {
        v1 = queue.front();
        res.push_back(v1);
        queue.pop_front();

        // all edges of the dequeued vertex
        // if the edge has not been visited, mark it visited and enqueue it
        LinkedList edges = vertices[v1 - 1];
        for (int i = 0; i < vertices[v1 - 1].count_nodes(); i++)
        {
            if (!visited[edges[i] -1])
            {
                visited[edges[i]-1] = true;
                queue.push_back(edges[i]);
            }
        }
    }
    //return the list of int
    return res;
}

void Graph::DFS_recursive(int v1, bool visited[], list<int>& res)
{
    //current node is visited
    visited[v1 - 1] = true;
    res.push_back(v1);

    //recursion on all the adjacent vertices to the current vertex
    LinkedList edges = vertices[v1 - 1];
    for (int i = 0; i < edges.count_nodes(); i++) {
        if (!visited[edges[i] - 1]) {
            DFS_recursive(edges[i], visited, res);
        }
    }
}

//Returns a list of integers, representing the depth first traversal of the
//graph starting from a given node
//uses a recursive approach, can also be implemented using the same approach as BFS but with a stack instead of queue
list<int> Graph::DFS(int v1) {
    list<int> res;
    //initially, all vertices are not-visited
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    //recursive helper function to create DFS traversal list
    DFS_recursive(v1, visited, res);
    return res;
}

//helper function for connectivity_type()
//creates a 2d matrix where each cell corresponds to whether there is a path from the 'row' node to 'column' node
//0 represents no path, 1 represents an existing path
int** Graph::create_path_matrix() {
    int** path_matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        path_matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (path_exist(i + 1, j + 1)) {
                path_matrix[i][j] = 1;
            }
            else {
                path_matrix[i][j] = 0;
            }
        }
    }
    return path_matrix;
}

//Checks what type of connectivity, the graph has.
//0 for not connected
//1 for weakly connected -> there is a path between every two vertices(bidirectional path)
//2 for unilaterally connected -> it contains a path from u to v OR a path from v to u for every pair of vertices.
//3 for strongly connected -> every pair of vertices(u,v) in the graph contains a path between each other, so both u->v and v->u must exist.
int Graph::connectivity_type() {
    bool strong = true;
    int** matrix = create_path_matrix();
    // loop through the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                strong = false;
                break;
            }
        }
        if (!strong) {
            break;
        }
    }
    // strongly connected
    if (strong) {
        return 3;
    }

    // check upper triangle for unilateral connectivity
    bool upper = true;

    // loop through the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && matrix[i][j] == 0) {
                upper = false;
                break;
            }
        }
        if (!upper) {
            break;
        }
    }

    // unilaterally connected
    if (upper) {
        return 2;
    }

    // check lower triangle for unilateral connectivity
    bool lower = true;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (i < j && matrix[i][j] == 0) {
                lower = false;
                break;
            }
        }
        if (!lower) {
            break;
        }
    }
    // unilaterally connected
    if (lower) {
        return 2;
    }
    else { // weakly connected
        return 1;
    }

    // not connected
    return 0;
}

ostream& operator <<(ostream& out, Graph graph) {
    out << "V = {";
    for (int i = 0; i < graph.n - 1; i++)
    {
        out << (i + 1) << ",";
    }
    out << graph.n << "}" << endl << "E =" << endl << "{" << endl;
    for (int i = 0; i < graph.n; i++)
    {
        out << "\t" << (i + 1) << " => ";
        if (graph.vertices[i].count_nodes() == 0) {
            out << " None" << endl;
        }
        else {
            out << graph.vertices[i] << endl;
        }
    }
    out << "}" << endl;
    return out;
}

