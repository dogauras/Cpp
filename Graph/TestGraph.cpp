/*
*  Author: Doga Uras
*  This class design is for the concept of directed graphs.
*
*  This test file can be used to run tests on all the functions mentioned in the Assignment 2 document
*/

#include <iostream>
#include <list>
#include "Graph.h"

int main() {
    Graph a(6);

    a.add_edge(1, 2);
    a.add_edge(2, 1);
    a.add_edge(2, 3);
    a.add_edge(2, 4);
    a.add_edge(3, 3);
    a.add_edge(4, 1);
    a.add_edge(4, 3);
    a.add_edge(5, 6);

    Graph copy(a);
    Graph c(3);

    //test user and copy constructors
    cout << a << endl << copy << endl;

    //test add_edge()
    if (!a.add_edge(1, 2)) cout << "Test 1 - add_edge - Passed" << endl;
    else cout << "Test 1 - add_edge - Failed" << endl;

    if (!a.add_edge(2, 1)) cout << "Test 2 - add_edge - Passed" << endl;
    else cout << "Test 2 - add_edge - Failed" << endl;

    if (!a.add_edge(4, 3)) cout << "Test 3 - add_edge - Passed" << endl;
    else cout << "Test 3 - add_edge - Failed" << endl;

    Graph b(6);
    b.add_edge(1, 2);
    b.add_edge(2, 1);
    b.add_edge(2, 3);
    b.add_edge(2, 4);
    b.add_edge(3, 3);
    b.add_edge(4, 1);
    b.add_edge(4, 3);
    b.add_edge(5, 6);

    //test remove_edge()
    b.remove_edge(1, 2);
    b.remove_edge(1, 2);
    b.remove_edge(4, 3);

    if (!b.edge_exist(1, 2)) cout << "Test 1 - remove_edge - Passed" << endl;
    else cout << "Test 1 - remove_edge - Failed" << endl;

    if (!b.edge_exist(4, 3)) cout << "Test 2 - remove_edge - Passed" << endl;
    else cout << "Test 2 - remove_edge - Failed" << endl;

    //test edge_exist()
    if (a.edge_exist(1, 2)) cout << "Test 1 - edge_exist - Passed" << endl;
    else cout << "Test 1 - edge_exist - Failed" << endl;

    if (a.edge_exist(2, 1)) cout << "Test 2 - edge_exist - Passed" << endl;
    else cout << "Test 2 - edge_exist - Failed" << endl;

    if (!a.edge_exist(4, 2)) cout << "Test 3 - edge_exist - Passed" << endl;
    else cout << "Test 3 - edge_exist - Failed" << endl;


    //test get_degree()
    if (a.get_degree(1) == 1) cout << "Test 1 - get_degree - Passed" << endl;
    else cout << "Test 1 - get_degree - Failed" << endl;

    if (a.get_degree(2) == 3) cout << "Test 2 - get_degree - Passed" << endl;
    else cout << "Test 2 - get_degree - Failed" << endl;

    if (a.get_degree(4) == 2) cout << "Test 3 - get_degree - Passed" << endl;
    else cout << "Test 3 - get_degree - Failed" << endl;


    //test operator ++
    cout << (++b) << endl;
    if (b.get_degree(7) == 0) cout << "Test 1 - prefix ++ - Passed" << endl;
    else cout << "Test 1 - prefix ++ - Failed" << endl;

    cout << (++c) << endl;
    if (c.get_degree(4) == 0) cout << "Test 2 - prefix ++ - Passed" << endl;
    else cout << "Test 2 - prefix ++ - Failed" << endl;

    if ((b++).get_degree(8) == -1) cout << "Test 1 - postfix ++ - Passed" << endl;
    else cout << "Test 1 - postfix ++ - Failed" << endl;

    if ((c++).get_degree(5) == -1) cout << "Test 2 - postfix ++ - Passed" << endl;
    else cout << "Test 2 - postfix ++ - Failed" << endl;

    //test operator --
    cout << --b << endl;
    if (b.get_degree(8) == -1) cout << "Test 1 - prefix -- - Passed" << endl;
    else cout << "Test 1 - prefix -- - Failed" << endl;

    if ((--c).get_degree(5) == -1) cout << "Test 2 - prefix -- - Passed" << endl;
    else cout << "Test 2 - prefix -- - Failed" << endl;

    if ((b--).get_degree(7) != -1) cout << "Test 1 - postfix -- - Passed" << endl;
    else cout << "Test 1 - postfix -- - Failed" << endl;
    cout << b << endl;

    if ((b--).get_degree(6) != -1) cout << "Test 2 - postfix -- - Passed" << endl;
    else cout << "Test 2 - postfix -- - Failed" << endl;
    cout << b << endl;

    if ((c--).get_degree(4) != -1) cout << "Test 3 - postfix -- - Passed" << endl;
    else cout << "Test 3 - postfix -- - Failed" << endl;

    b.add_edge(1,5);
    b.add_edge(3,5);
    b.add_edge(4,5);
    cout << "Before --:" << b << endl;
    b--;
    if (!b.edge_exist(1,5) && !b.edge_exist(3,5) && !b.edge_exist(4,5) ) cout << "Test 4 - postfix -- - Passed" << endl;
    else cout << "Test 4 - postfix -- - Failed" << endl;
    cout << "After --:" << b << endl;

    //test path_exist()
    if (a.path_exist(1, 3)) cout << "Test 1 - path_exist - Passed" << endl;
    else cout << "Test 1 - path_exist - Failed" << endl;

    if (a.path_exist(4, 2)) cout << "Test 2 - path_exist - Passed" << endl;
    else cout << "Test 2 - path_exist - Failed" << endl;

    if (a.path_exist(5, 6)) cout << "Test 3 - path_exist - Passed" << endl;
    else cout << "Test 3 - path_exist - Failed" << endl;

    if (a.path_exist(3, 3)) cout << "Test 4 - path_exist - Passed" << endl;
    else cout << "Test 4 - path_exist - Failed" << endl;

    if (a.path_exist(2, 2)) cout << "Test 5 - path_exist - Passed" << endl;
    else cout << "Test 5 - path_exist - Failed" << endl;

    if (!a.path_exist(3, 5)) cout << "Test 6 - path_exist - Passed" << endl;
    else cout << "Test 6 - path_exist - Failed" << endl;

    if (!a.path_exist(6, 5)) cout << "Test 7 - path_exist - Passed" << endl;
    else cout << "Test 7 - path_exist - Failed" << endl;


    //test BFS
    Graph g(4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.add_edge(3, 4);
    g.add_edge(4, 4);

    cout << g << endl;
    cout << "BFS Traversal of the above graph" << "(starting from vertex 3) ";
    list<int> r1 = g.BFS(3);
    for (auto v : r1)
        std::cout << v << ",";
    cout << endl;

    //test DFS
    cout << "DFS Traversal of the above graph" << "(starting from vertex 3) ";
    list<int> r3 = g.DFS(3);
    for (auto v : r3)
        cout << v << ",";
    cout << endl;

    Graph g2(9);
    g2.add_edge(1, 2);
    g2.add_edge(1, 3);
    g2.add_edge(1, 4);
    g2.add_edge(2, 4);
    g2.add_edge(3, 5);
    g2.add_edge(4, 6);
    g2.add_edge(4, 7);
    g2.add_edge(5, 8);
    g2.add_edge(5, 6);
    g2.add_edge(6, 3);
    g2.add_edge(7, 6);
    g2.add_edge(8, 6);
    g2.add_edge(8, 9);

    cout << g2 << endl;
    cout << "BFS Traversal of the above graph" << "(starting from vertex 3) ";
    list<int> r2 = g2.BFS(3);
    for (auto v : r2)
        cout << v << ",";
    cout << endl;

    cout << "DFS Traversal of the above graph" << "(starting from vertex 3) ";
    list<int> r4 = g2.DFS(3);
    for (auto v : r4)
        cout << v << ",";
    cout << endl;


    list<int> res1 = { 3,1,4,2 };
    if (r1 == res1) cout << "Test 1 - BFS - Passed" << endl;
    else cout << "Test 1 - BFS - Failed" << endl;

    list<int> res2 = { 3,5,8,6,9 };
    if (r2 == res2) cout << "Test 2 - BFS - Passed" << endl;
    else cout << "Test 2 - BFS - Failed" << endl;

    list<int> res3 = { 3,1,2,4 };
    if (r3 == res3) cout << "Test 1 - DFS - Passed" << endl;
    else cout << "Test 1 - DFS - Failed" << endl;

    if (r4 == res2) cout << "Test 2 - DFS - Passed" << endl;
    else cout << "Test 2 - DFS - Failed" << endl;

    Graph g3(5);
    g3.add_edge(1, 2);
    g3.add_edge(1, 3);
    g3.add_edge(1, 4);
    g3.add_edge(2, 3);
    g3.add_edge(3, 5);
    g3.add_edge(4, 4);
    g3.add_edge(5, 5);
    list<int> res4 = { 1,2,3,5,4 };
    list<int> r5 = g3.DFS(1);
    if (r5 == res4) cout << "Test 3 - DFS - Passed" << endl;
    else cout << "Test 3 - DFS - Failed" << endl;


    // test connectivity_type()
    Graph g4(3);
    g4.add_edge(1, 2);
    g4.add_edge(1, 3);
    g4.add_edge(2, 3);

    Graph g5(3);
    g5.add_edge(1, 2);
    g5.add_edge(1, 3);
    g5.add_edge(3, 3);

    Graph g6(3);
    g6.add_edge(2, 1);
    g6.add_edge(3, 1);
    g6.add_edge(3, 2);

    Graph g7(5);
    g7.add_edge(1, 2);
    g7.add_edge(2, 3);
    g7.add_edge(3, 4);
    g7.add_edge(4, 1);
    g7.add_edge(3, 5);
    g7.add_edge(5, 3);

    Graph g8(3);
    g8.add_edge(1, 2);
    g8.add_edge(2, 3);
    g8.add_edge(3, 1);

    if (g4.connectivity_type() == 2) cout << "Test 1 - connectivity_type - Passed" << endl;
    else cout << "Test 1 - connectivity_type - Failed" << endl;

    if (g5.connectivity_type() == 1) cout << "Test 2 - connectivity_type - Passed" << endl;
    else cout << "Test 2 - connectivity_type - Failed" << endl;

    if (g6.connectivity_type() == 2) cout << "Test 3 - connectivity_type - Passed" << endl;
    else cout << "Test 3 - connectivity_type - Failed" << endl;

    if (g7.connectivity_type() == 3) cout << "Test 4 - connectivity_type - Passed" << endl;
    else cout << "Test 4 - connectivity_type - Failed" << endl;

    if (g8.connectivity_type() == 3) cout << "Test 4 - connectivity_type - Passed" << endl;
    else cout << "Test 4 - connectivity_type - Failed" << endl;


    return 0;
}