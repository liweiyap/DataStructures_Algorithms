#include <vector>
#include "queue.hpp"
#include "std-input-parser.hpp"
#include <string>  // getline
#include <sstream>

// TODO: assert m <= n(n-1)
// TODO: throw exception if vertex indices for any edge is out of range
// TODO: assert vector not empty when printing?
// TODO: check if edge already exists, otherwise no need to push back

class Graph{
public:
    Graph(unsigned int n): n_vertices(n){
        // initialise adjacency list as a vector of vectors
        adj_list.resize(n_vertices, std::vector<unsigned int>(0));
    }
    
    // add an edge into adjacency list of graph
    virtual void add_edge(unsigned int v1, unsigned int v2) = 0;
    
    // print adjacency list to standard output
    void print_adj_list(){
        for (unsigned int adj_list_it = 1; adj_list_it <= n_vertices; ++adj_list_it){
            // first, print index of vertex for easier visualisation in standard output
            std::cout << adj_list_it << ": ";
            for (auto vertex_it = adj_list[adj_list_it-1].begin(); vertex_it != adj_list[adj_list_it-1].end(); ++vertex_it){
                std::cout << *vertex_it << " ";
            }
            std::cout << "\n";
            
        }  // end of FOR loop for printing adjacency list
    }
    
    unsigned int get_n_vertices(){
        return n_vertices;
    }
    
    std::vector<std::vector<unsigned int>> get_adj_list(){
        return adj_list;
    }
    
protected:
    unsigned int n_vertices;
    std::vector<std::vector<unsigned int>> adj_list;
};

class Graph_Undirected : public Graph{
public:
    Graph_Undirected(unsigned int n): Graph(n){}
    
    // add an edge into adjacency list of graph
    void add_edge(unsigned int v1, unsigned int v2){
        adj_list[v1-1].push_back(v2);
        adj_list[v2-1].push_back(v1);
    }
};

class Graph_Directed : public Graph{
public:
    Graph_Directed(unsigned int n): Graph(n){}
    
    // add an edge into adjacency list of graph
    void add_edge(unsigned int v1, unsigned int v2){
        adj_list[v1-1].push_back(v2);
    }
};

// run BFS algorithm
template<class G>
std::vector<int> bfs(G& graph, unsigned int source_vertex){
    unsigned int n_vertices = graph.get_n_vertices();
    std::vector<std::vector<unsigned int>> adj_list = graph.get_adj_list();
    
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
         
         initialise vertex iterator as begin()+1, as the first entry is just
         the index of the corresponding vertex number itself
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

int parseDigits(){
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int value;
    if ( !(iss >> value) || !(iss.eof()) ) throw InvalidInput();
    return value;
}

unsigned int parseDigitsUnsigned(){
    int value;
    value = parseDigits();
    if (value < 0) throw Underflow();
    return static_cast<unsigned int>(value);
}

int main(){
    
    try {
        // /////////////////////////////////////////////////////////////////////////////
        // input total number of graphs on which we want to run BFS algorithm
        // /////////////////////////////////////////////////////////////////////////////
        
        std::cout << "Input number of queries:\n";
        unsigned int n_queries = parseDigitsUnsigned();
        
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
            unsigned int n_vertices = parseDigitsUnsigned();
            
            std::cout << "\nNow, input the number of edges:\n";
            unsigned int n_edges = parseDigitsUnsigned();
            std::cout << "\nFor query " << idx_queries
                      << ", you have input " << n_vertices
                      << " vertices and " << n_edges << " edges.\n\n";
            
            // /////////////////////////////////////////////////////////////////////////
            // initialise graph
            // /////////////////////////////////////////////////////////////////////////
            
            Graph_Undirected graph(n_vertices);
            
            // input all edges into adjacency list of graph
            for (unsigned int idx_edges = 1; idx_edges <= n_edges; ++idx_edges){
                std::cout << "For edge " << idx_edges << ", input both vertices on separate lines:\n";
                unsigned int v1 = parseDigitsUnsigned();
                unsigned int v2 = parseDigitsUnsigned();
                std::cout << "You have input vertices " << v1 << " and " << v2 << " for edge " << idx_edges << "...\n\n";
                
                graph.add_edge(v1, v2);
            } // end of FOR loop for input edges and filling adjacency list
            
            // print adjacency list
            std::cout << "For query " << idx_queries << ", here is your adjacency list:\n";
            graph.print_adj_list();
            
            // /////////////////////////////////////////////////////////////////////////
            // initialise index of vertex to be used as the source for BFS
            // /////////////////////////////////////////////////////////////////////////
            
            std::cout << "\nFinally, input the source vertex:\n";
            unsigned int source_vertex = parseDigitsUnsigned();
            std::cout << "You have chosen vertex " << source_vertex << " as your source.\n\n";
            
            // /////////////////////////////////////////////////////////////////////////
            // run BFS
            // /////////////////////////////////////////////////////////////////////////
            
            std::cout << "Starting BFS algorithm:\n";
            
            std::vector<int> dist_from_source = bfs(graph, source_vertex);
            
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
    } catch(Underflow& error){
        std::cerr << "Error: input must be positive.\n";
        return 1;
    }
    
    return 0;
}
