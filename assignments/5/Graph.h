#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>  // For std::pair

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
    const list<pair<int, T>>& getNeighbors(int vertex) const;

    // Depth First Traversal
    void DFT(int start) const;
    void DFTRecursive(int v, vector<bool>& visited) const;

    // -----------------------------------------------------
    // Depth First Search (by username)
    // TO DO 
    // Add DFS prototype 
    // Add DFSRecursive prototype

private:
    int V; // Number of vertices
    bool directed; // Whether the graph is directed or undirected
    vector<list<pair<int, T>>> adjList; // Adjacency list
};

// Include the implementation of template functions
#include "Graph.cpp"

#endif // GRAPH_H
