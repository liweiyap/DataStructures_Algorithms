/**
 * Declaration of Graph base and derived classes..
 */

#ifndef BFS_H
#define BFS_H
#pragma once

#ifndef EXCEPTIONS_H
#include "exceptions.hpp"
#endif

#ifndef GRAPH_H
#include "graph.hpp"
#endif

#ifndef QUEUE_H
#include "queue.hpp"
#endif


namespace dsa{
    
    /**
     * BFS algorithm
     *
     * @param graph reference to object of class type Graph
     * @param source_vertex index of vertex at which to start BFS
     * @return STL vector of distance between each vertex and source_vertex
     * @throws OutOfRange() exception thrown if source vertex is not in the range of vertex indices with which the Graph has been initialised
     */
    std::vector<int> bfs(dsa::Graph& graph, unsigned int source_vertex);
    
}  // end of namespace dsa

#endif
