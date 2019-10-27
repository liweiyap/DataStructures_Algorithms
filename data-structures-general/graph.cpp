/**
 * Definition of Graph object.
 */

#ifndef GRAPH_H
#include "graph.hpp"
#endif


/**
 * Constructor for base class Graph, given the number of vertices
 *
 * @param n number of vertices
 */
dsa::Graph::Graph(unsigned int n): n_vertices(n){
    // initialise adjacency list as a vector of vectors
    adj_list.resize(n_vertices, std::vector<unsigned int>(0));
}  // end of constructor of base class Graph


/**
 * Print adjacency list to standard output
 */
void dsa::Graph::print_adj_list(){
    for (unsigned int adj_list_it = 1; adj_list_it <= n_vertices; ++adj_list_it){
        // first, print index of vertex for easier visualisation in standard output
        std::cout << adj_list_it << ": ";
        for (auto vertex_it = adj_list[adj_list_it-1].begin(); vertex_it != adj_list[adj_list_it-1].end(); ++vertex_it){
            std::cout << *vertex_it << " ";
        }
        std::cout << "\n";
        
    }  // end of FOR loop for iterating through all vertices in graph
    
}  // end of print_adj_list function


/**
 * Access protected class variable n_vertices
 *
 * @return number of vertices in graph
 */
unsigned int dsa::Graph::get_n_vertices(){
    return n_vertices;
}  // end of get_n_vertices function


/**
 * Access protected class variable adj_list
 *
 * @return adjacency list for visualising vertices in graph
 */
std::vector<std::vector<unsigned int>> dsa::Graph::get_adj_list(){
    return adj_list;
}  // end of get_adj_list function


/**
 * Constructor for derived class Graph_Undirected, given the number of vertices
 *
 * @param n number of vertices
 */
dsa::Graph_Undirected::Graph_Undirected(unsigned int n): Graph(n){}


/**
 * Add edge between two vertices by updating adjacency list
 *
 * @param v1 first vertex connected to edge
 * @param v2 second vertex connected to edge
 * @throws OutOfRange() exception thrown if either vertex is not in the range of vertex indices with which the Graph has been initialised
 */
void dsa::Graph_Undirected::add_edge(unsigned int v1, unsigned int v2){
    if (v1 < 1 || v1 > n_vertices) throw OutOfRange();
    if (v2 < 1 || v2 > n_vertices) throw OutOfRange();
    
    assert ( std::none_of(adj_list[v1-1].begin(), adj_list[v1-1].end(), [v2](unsigned int i){ return i == v2; }) && "Edge already exists. No self-loops allowed.");
    assert ( std::none_of(adj_list[v2-1].begin(), adj_list[v2-1].end(), [v1](unsigned int i){ return i == v1; }) && "Edge already exists. No self-loops allowed.");
    
    adj_list[v1-1].push_back(v2);
    adj_list[v2-1].push_back(v1);
    
}  // end of add_edge function in undirected graph


/**
 * Constructor for derived class Graph_Directed, given the number of vertices
 *
 * @param n number of vertices
 */
dsa::Graph_Directed::Graph_Directed(unsigned int n): Graph(n){}


/**
 * Add edge between two vertices by updating adjacency list
 *
 * @param v1 first vertex connected to edge
 * @param v2 second vertex connected to edge
 * @throws OutOfRange() exception thrown if either vertex is not in the range of vertex indices with which the Graph has been initialised
*/
void dsa::Graph_Directed::add_edge(unsigned int v1, unsigned int v2){
    if (v1 < 1 || v1 > n_vertices) throw OutOfRange();
    if (v2 < 1 || v2 > n_vertices) throw OutOfRange();
    
    assert ( std::none_of(adj_list[v1-1].begin(), adj_list[v1-1].end(), [v2](unsigned int i){ return i == v2; }) && "Edge already exists. No self-loops allowed.");
    
    adj_list[v1-1].push_back(v2);
    
}  // end of add_edge function in undirected graph
