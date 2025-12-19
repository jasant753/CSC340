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
    cout << endl;
}

// Get neighbors of a vertex
template <typename T>
const LinkedBag<pair<int, T>>& Graph<T>::getNeighbors(int vertex) const {
    return adjList[vertex];
}

// DFS Traversal (Recursive approach)
template <typename T>
void Graph<T>::DFT(int start, const std::vector<Event>& events) const {
    std::vector<bool> visited(V, false);

    if (start < 0 || start >= V) return;
    if (static_cast<int>(events.size()) != V) return;

    DFTRecursive(start, visited, events);
    std::cout << std::endl;
}

// Utility function for DFS (Recursive)
template <typename T>
void Graph<T>::DFTRecursive(int v, std::vector<bool>& visited, const std::vector<Event>& events) const {
    visited[v] = true;
    cout << events[v] << "\n"; // Print full event information

    // Recur for all the vertices adjacent to this vertex
    auto neighbors = adjList[v].toVector();
    for (const auto& edge : neighbors) {
        int to = edge.first;
        if (!visited[to]) DFTRecursive(to, visited, events);
    }

}

// DFS Implementation
template <typename T>
bool Graph<T>::DFS(const std::string& targetName,
                   int start,
                   const std::vector<Event>& events) const
{
    if (start < 0 || start >= V) return false;
    if (static_cast<int>(events.size()) != V) return false;

    std::vector<bool> visited(V, false);

    return DFSRecursive(start, targetName, events, visited);
}

template <typename T>
bool Graph<T>::DFSRecursive(int v,
                            const std::string& targetName,
                            const std::vector<Event>& events,
                            std::vector<bool>& visited) const
{
    visited[v] = true;

    if (events[v].getName() == targetName) {
        return true;
    }

    auto neighbors = adjList[v].toVector();
    for (const auto& edge : neighbors) {
        int to = edge.first;
        if (!visited[to]) {
            if (DFSRecursive(to, targetName, events, visited)) {
                return true;
            }
        }
    }
    return false;
}