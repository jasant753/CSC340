#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>  // For std::pair
#include "LinkedBagDS/LinkedBag.h"
#include <string>
#include <vector>
#include "Event.h"

using namespace std;

// Template class for a Graph
template <typename T>
class Graph {
public:
    // Constructor
    Graph(int vertices, bool directed = false);

    // Add an edge
    void addEdge(int u, int v, T weight = T());

    // Get number of nodes
    int getNumVertices() const;

    // Print the adjacency list
    void printGraph() const;

    // Get neighbors of a vertex
    const LinkedBag<std::pair<int, T>>& getNeighbors(int vertex) const;

    // Depth First Traversal
    // Updated to look up event info
    void DFT(int start, const std::vector<Event>& events) const;
    void DFTRecursive(int v, std::vector<bool>& visited, const std::vector<Event>& events) const;

    // Depth First Search
    bool DFS(const std::string& targetName,
             int start,
             const std::vector<Event>& events) const;

    bool DFSRecursive(int v,
                      const std::string& targetName,
                      const std::vector<Event>& events,
                      std::vector<bool>& visited) const;

private:
    int V; // Number of vertices
    bool directed; // Whether the graph is directed or undirected
    vector<LinkedBag<pair<int, T>>> adjList; // LinkedBag Implementation
};

// Include the implementation of template functions
#include "Graph.cpp"

#endif // GRAPH_H
