/**
 * Run BFS algorithm.
 */

#ifndef BFS_H
#include "breadth-first-search.hpp"
#endif


/**
 * BFS algorithm
 *
 * @param graph reference to object of class type Graph
 * @param source_vertex index of vertex at which to start BFS
 * @return STL vector of distance between each vertex and source_vertex
 * @throws OutOfRange() exception thrown if source vertex is not in the range of vertex indices with which the Graph has been initialised
 */
std::vector<int> dsa::bfs(dsa::Graph& graph, unsigned int source_vertex){
    unsigned int n_vertices = graph.get_n_vertices();
    std::vector<std::vector<unsigned int>> adj_list = graph.get_adj_list();
    
    if (source_vertex < 1 || source_vertex > n_vertices) throw OutOfRange();
    
    // if vertex has not been visited, then let the distance to source vertex be -1.
    std::vector<int> dist_from_source(n_vertices, -1);
    
    // the source vertex itself has a distance of 0
    dist_from_source[source_vertex-1] = 0;
    
    // initialise queue and enqueue source vertex
    dsa::Queue<unsigned int> queue;
    queue.enqueue(source_vertex);
    
    // queue is not empty as long as all vertices that can be reached from source are discovered
    while (!queue.isEmpty()){
        // dequeue the vertex at the front of the queue
        unsigned int discovered_vertex = queue.peek();
        queue.dequeue();
        
        /*
         for all neighbours of dequeued/discovered vertex that are directly
         connected by an edge, check if neighbour has already been
         discovered/visited before.

         if not already discovered, then update its distance accordingly. Enqueue.
         */
        for (auto vertex_it = adj_list[discovered_vertex-1].begin(); vertex_it != adj_list[discovered_vertex-1].end(); ++vertex_it){
            if (dist_from_source[*vertex_it-1] == -1){
                dist_from_source[*vertex_it-1] = dist_from_source[discovered_vertex-1] + 1;
                queue.enqueue(*vertex_it);
                
            }  // end of IF statement for checking if directly connected vertex has already been discovered before
            
        }  // end of FOR loop for iterating through all directly connected vertices in the adjacency list
        
    }  // end of WHILE loop for checking whether all vertices that can be reached from source have been discovered
    
    // return output of BFS (distance from source vertex from all other vertices)
    // if a given vertex is not connected to source vertex, its distance remains -1.
    return dist_from_source;
}
