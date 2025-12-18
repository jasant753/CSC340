#include "Graph.h"


// Constructor
template <typename T>
Graph<T>::Graph(int vertices, bool directed)
    : V(vertices), directed(directed) {
    adjList.resize(V);
}

// Add an edge
template <typename T>
void Graph<T>::addEdge(int u, int v, T weight) {
    // Check bounds
    if (u < 0 || u >= V || v < 0 || v >= V) {
        return;
    }
    // Disallow self-edges
    if (u == v) {
        return;
    }
    adjList[u].add({v, weight});
    if (!directed) {
        adjList[u].add({v, weight});    }
}

// Get number of nodes
template <typename T>
int Graph<T>::getNumVertices() const{
	return V;
}

// Print the adjacency list
template <typename T>
void Graph<T>::printGraph() const {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";

        auto neighbors = adjList[i].toVector();

        for (const auto& neighbor : neighbors) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

// Get neighbors of a vertex
template <typename T>
const LinkedBag<pair<int, T>>& Graph<T>::getNeighbors(int vertex) const {
    return adjList[vertex];
}



// DFS Traversal (Recursive approach)
template <typename T>
void Graph<T>::DFT(int start) const {
    vector<bool> visited(V, false); // To keep track of visited vertices
    DFTRecursive(start, visited);
    cout << endl;
}

// Utility function for DFS (Recursive)
template <typename T>
void Graph<T>::DFTRecursive(int v, vector<bool>& visited) const {
    visited[v] = true;
    cout << v << " "; // Visit the current vertex

    // Recur for all the vertices adjacent to this vertex
    auto neighbors = adjList[v].toVector();
    for (const auto& edge : neighbors) {
        int to = edge.first;
        if (!visited[to]) DFTRecursive(to, visited);
    }

}

// -----------------------------------------------------
// Depth First Search (by username)
// TO DO 
// Add DFS implementation 
// Add DFSRecursive implementation 
