#include "std-input-parser.hpp"
#include "graph.hpp"
#include "breadth-first-search.hpp"

int main(){
    unsigned int n_vertices;
    try {
        // /////////////////////////////////////////////////////////////////////////////
        // input total number of graphs on which we want to run BFS algorithm
        // /////////////////////////////////////////////////////////////////////////////
        
        std::cout << "Input number of queries:\n";
        unsigned int n_queries = dsa::parseDigitsUnsigned();
        
        std::cout << "\nYou have input: " << n_queries << " queries.\n";
        
        // /////////////////////////////////////////////////////////////////////////////
        // for each graph, iterate the following loop
        // /////////////////////////////////////////////////////////////////////////////
        
        for (unsigned int idx_queries = 1; idx_queries <= n_queries; ++idx_queries){
            std::cout << "\n======================================================\n";
            
            // /////////////////////////////////////////////////////////////////////////
            // input the number of vertices, followed by the number of edges
            // /////////////////////////////////////////////////////////////////////////
            
            std::cout << "For query " << idx_queries << ", input the number of vertices:\n";
            n_vertices = dsa::parseDigitsUnsigned();
            
            std::cout << "\nNow, input the number of edges:\n";
            unsigned int n_edges = dsa::parseDigitsUnsigned();
            assert(n_edges <= n_vertices*(n_vertices-1)/2 && "ERROR: maximum n_edges is n_vertices choose 2");
            std::cout << "\nFor query " << idx_queries
                      << ", you have input " << n_vertices
                      << " vertices and " << n_edges << " edges.\n\n";
            
            // /////////////////////////////////////////////////////////////////////////
            // initialise graph
            // /////////////////////////////////////////////////////////////////////////
            
            dsa::Graph_Undirected graph(n_vertices);
            
            // input all edges into adjacency list of graph
            for (unsigned int idx_edges = 1; idx_edges <= n_edges; ++idx_edges){
                std::cout << "For edge " << idx_edges << ", input both vertices on separate lines:\n";
                unsigned int v1 = dsa::parseDigitsUnsigned();
                unsigned int v2 = dsa::parseDigitsUnsigned();
                std::cout << "You have input vertices " << v1 << " and " << v2 << " for edge " << idx_edges << "...\n\n";
                
                graph.add_edge(v1, v2);
            } // end of FOR loop for input edges and filling adjacency list
            
            // print adjacency list
            if (n_vertices > 0){
                std::cout << "For query " << idx_queries << ", here is your adjacency list:\n";
                graph.print_adj_list();
            }
            
            // /////////////////////////////////////////////////////////////////////////
            // initialise index of vertex to be used as the source for BFS
            // /////////////////////////////////////////////////////////////////////////
            
            std::cout << "\nFinally, input the source vertex:\n";
            unsigned int source_vertex = dsa::parseDigitsUnsigned();
            std::cout << "You have chosen vertex " << source_vertex << " as your source.\n\n";
            
            // /////////////////////////////////////////////////////////////////////////
            // run BFS
            // /////////////////////////////////////////////////////////////////////////
            
            std::cout << "Starting BFS algorithm:\n";
            
            std::vector<int> dist_from_source = dsa::bfs(graph, source_vertex);
            
            // print output of BFS (distance from source vertex from all other vertices)
            // if distance is -1 for any vertex, that means it's not connected to source
            for (unsigned int idx_vertices = 1; idx_vertices <= n_vertices; ++idx_vertices){
                if (idx_vertices != source_vertex){
                    std::cout << dist_from_source[idx_vertices-1] << " ";
                }
            }
            std::cout << "\nEnd of BFS algorithm.\n";
            
        }  // end of FOR loop for each graph query
        
        std::cout << "\n======================================================\n";
        std::cout << "All queries have been processed.\n\n";
        
    } catch(InvalidInput& error){
        std::cerr << "ERROR: input must be an integer.\n";
        return 1;
    } catch(Overflow& error){
        std::cerr << "Error: input must be smaller than INT_MAX.\n";
        return 1;
    } catch(Underflow& error){
        std::cerr << "Error: input must be positive.\n";
        return 1;
    } catch(OutOfRange& error){
        std::cerr << "Error: vertex index is not in the range of 1 to " << n_vertices << ".\n";
        return 1;
    }
    
    return 0;
}
