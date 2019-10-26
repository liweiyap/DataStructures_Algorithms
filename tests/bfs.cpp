#include <vector>
#include "queue.hpp"

// TODO: parse unsigned int
// TODO: assert m <= n(n-1)
// TODO: throw exception if vertex indices for any edge is out of range
// TODO: add inheritance from Graph to Graph_Directed or Graph_Undirected
// TODO: add templates for stack and queue datatype
// TODO: assert vector not empty when printing?
// TODO: check if edge already exists, otherwise no need to push back

class Graph{
public:
    Graph(int n): n_vertices(n){
        // initialise adjacency list as a vector of vectors
        adj_list.resize(n_vertices, std::vector<unsigned int>(0));
        
        for (unsigned int idx_vertices = 1; idx_vertices <= n_vertices; ++idx_vertices){
            /*
             Let the first entry in each individual vector be the index of the
             corresponding vertex number itself.
             This is just for easier visualisation for the user on the standard output.
             */
            adj_list[idx_vertices-1].push_back(idx_vertices);
            
        }  // end of FOR loop for initialising adjacency list
    }
    
    // add an edge into adjacency list of graph
    void add_edge(unsigned int v1, unsigned int v2){
        adj_list[v1-1].push_back(v2);
        adj_list[v2-1].push_back(v1);  // only if graph is undirected
    }
    
    // print adjacency list to standard output
    void print_adj_list(){
        for (auto adj_list_it = adj_list.begin(); adj_list_it != adj_list.end(); ++adj_list_it){
            for (auto vertex_it = adj_list_it->begin(); vertex_it != adj_list_it->end(); ++vertex_it){
                std::cout << *vertex_it;
                if (vertex_it == adj_list_it->begin()) std::cout << ":";
                std::cout << " ";
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
    
private:
    unsigned int n_vertices;
    std::vector<std::vector<unsigned int>> adj_list;
};

// run BFS algorithm
std::vector<int> bfs(Graph& graph, unsigned int source_vertex){
    unsigned int n_vertices = graph.get_n_vertices();
    std::vector<std::vector<unsigned int>> adj_list = graph.get_adj_list();
    
    // if vertex has not been visited, then let the distance to source vertex be -1.
    std::vector<int> dist_from_source(n_vertices, -1);
    
    // the source vertex itself has a distance of 0
    dist_from_source[source_vertex-1] = 0;
    
    // initialise queue and enqueue source vertex
    dsa::Queue queue;
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
        for (auto vertex_it = adj_list[discovered_vertex-1].begin()+1; vertex_it != adj_list[discovered_vertex-1].end(); ++vertex_it){
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

int main(){
    
    // /////////////////////////////////////////////////////////////////////////////////
    // input total number of graphs on which we want to run BFS algorithm
    // /////////////////////////////////////////////////////////////////////////////////
    
    std::cout << "Input number of queries:\n";
    unsigned int n_queries;
    std::cin >> n_queries;
    std::cout << "\nYou have input: " << n_queries << " queries.\n";
    
    // /////////////////////////////////////////////////////////////////////////////////
    // for each graph, iterate the following loop
    // /////////////////////////////////////////////////////////////////////////////////
    
    for (unsigned int idx_queries = 1; idx_queries <= n_queries; ++idx_queries){
        std::cout << "\n======================================================\n";
        
        // /////////////////////////////////////////////////////////////////////////////
        // input the number of vertices, followed by the number of edges
        // /////////////////////////////////////////////////////////////////////////////
        
        std::cout << "For query " << idx_queries << ", input the number of vertices:\n";
        unsigned int n_vertices;
        std::cin >> n_vertices;
        
        std::cout << "\nNow, input the number of edges:\n";
        unsigned int n_edges;
        std::cin >> n_edges;
        std::cout << "\nFor query " << idx_queries
                  << ", you have input " << n_vertices
                  << " vertices and " << n_edges << " edges.\n\n";
        
        // /////////////////////////////////////////////////////////////////////////////
        // initialise graph
        // /////////////////////////////////////////////////////////////////////////////
        
        Graph graph(n_vertices);
        
        // input all edges into adjacency list of graph
        for (unsigned int idx_edges = 1; idx_edges <= n_edges; ++idx_edges){
            std::cout << "For edge " << idx_edges << ", input both vertices:\n";
            unsigned int v1;
            unsigned int v2;
            std::cin >> v1;
            std::cin >> v2;
            std::cout << "You have input vertices " << v1 << " and " << v2 << " for edge " << idx_edges << "...\n\n";
            
            graph.add_edge(v1, v2);
        } // end of FOR loop for input edges and filling adjacency list
        
        // print adjacency list
        std::cout << "For query " << idx_queries << ", here is your adjacency list:\n";
        graph.print_adj_list();
        
        // /////////////////////////////////////////////////////////////////////////////
        // initialise index of vertex to be used as the source for BFS
        // /////////////////////////////////////////////////////////////////////////////
        
        unsigned int source_vertex;
        std::cout << "\nFinally, input the source vertex:\n";
        std::cin >> source_vertex;
        std::cout << "You have chosen vertex " << source_vertex << " as your source.\n\n";
        
        // /////////////////////////////////////////////////////////////////////////////
        // run BFS
        // /////////////////////////////////////////////////////////////////////////////
        
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
    
    return 0;
}
