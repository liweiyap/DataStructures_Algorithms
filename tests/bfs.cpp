#include <iostream>
#include <vector>
#include <string>
#include "queue.hpp"

// TODO: parse unsigned int
// TODO: assert m <= n(n-1)

struct Vertex{
    std::string colour;
    int dist_from_source;
    unsigned int idx_prev;
};

int main(){
    std::cout << "Input number of queries:\n";
    unsigned int n_queries;
    std::cin >> n_queries;
    std::cout << "\nYou have input: " << n_queries << " queries.\n";
    
    for (unsigned int idx_queries = 1; idx_queries <= n_queries; ++idx_queries){
        std::cout << "\n======================================================\n";
        std::cout << "For query " << idx_queries << ", input the number of vertices:\n";
        unsigned int n_vertices;
        std::cin >> n_vertices;
        
        std::cout << "\nNow, input the number of edges:\n";
        unsigned int n_edges;
        std::cin >> n_edges;
        std::cout << "\nFor query " << idx_queries
                  << ", you have input " << n_vertices
                  << " vertices and " << n_edges << " edges.\n\n";
        
        std::vector<std::vector<int>> adj_list(n_vertices);
        for (unsigned int idx_vertices = 1; idx_vertices <= n_vertices; ++idx_vertices){
            adj_list[idx_vertices-1].push_back(idx_vertices);
        }
        
        for (unsigned int idx_edges = 1; idx_edges <= n_edges; ++idx_edges){
            std::cout << "For edge " << idx_edges << ", input both vertices:\n";
            unsigned int v1;
            unsigned int v2;
            std::cin >> v1;
            std::cin >> v2;
            std::cout << "You have input vertices " << v1 << " and " << v2 << " for edge " << idx_edges << "...\n\n";
            
            adj_list[v1-1].push_back(v2);
            adj_list[v2-1].push_back(v1);
        }
        
        std::cout << "For query " << idx_queries << ", here is your adjacency list:\n";
        for (auto adj_list_it = adj_list.begin(); adj_list_it != adj_list.end(); ++adj_list_it){
            for (auto vertex_it = adj_list_it->begin(); vertex_it != adj_list_it->end(); ++vertex_it){
                std::cout << *vertex_it;
                if (vertex_it == adj_list_it->begin()) std::cout << ":";
                std::cout << " ";
            }
            std::cout << "\n";
        }
        
        unsigned int source_vertex;
        std::cout << "\nFinally, input the source vertex:\n";
        std::cin >> source_vertex;
        std::cout << "You have chosen vertex " << source_vertex << " as your source.\n\n";
        
        std::cout << "Starting BFS algorithm:\n";
        std::vector<Vertex> graph(n_vertices);
        for (unsigned int idx_vertices = 1; idx_vertices <= n_vertices; ++idx_vertices){
            if (idx_vertices != source_vertex){
                graph[idx_vertices-1].colour = "white";
                graph[idx_vertices-1].dist_from_source = -1;
                graph[idx_vertices-1].idx_prev = -1;
            } else{
                graph[idx_vertices-1].colour = "grey";
                graph[idx_vertices-1].dist_from_source = 0;
                graph[idx_vertices-1].idx_prev = -1;
            }
        }
        
        dsa::Queue queue;
        queue.enqueue(source_vertex);
        
        while (!queue.isEmpty()){
            unsigned int discovered_vertex = queue.peek();
            queue.dequeue();
            
            for (auto vertex_it = adj_list[discovered_vertex-1].begin()+1; vertex_it != adj_list[discovered_vertex-1].end(); ++vertex_it){
                if (graph[*vertex_it-1].colour == "white"){
                    graph[*vertex_it-1].colour = "grey";
                    graph[*vertex_it-1].dist_from_source = graph[discovered_vertex-1].dist_from_source + 6;
                    graph[*vertex_it-1].idx_prev = discovered_vertex;
                    queue.enqueue(*vertex_it);
                }
            }
            
            graph[discovered_vertex-1].colour = "black";
        }
        
        for (unsigned int idx_vertices = 1; idx_vertices <= n_vertices; ++idx_vertices){
            if (idx_vertices != source_vertex){
                std::cout << graph[idx_vertices-1].dist_from_source << " ";
            }
        }
        std::cout << "\nEnd of BFS algorithm.\n";
    }
    
    std::cout << "\n======================================================\n";
    std::cout << "All queries have been processed.\n\n";
    
    return 0;
}
