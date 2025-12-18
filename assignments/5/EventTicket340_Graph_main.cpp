#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Event.h"

using namespace std;
int main() {
	// Create a list of Events
	// Add 10 distinct events to the vector
	// TO DO 

	// Initialize a graph with n vertices (where n is the number of events) 
	//	 Indicate whether it is directed or undirected 
	// TO DO 


	// Add 15-20 edges (eventA, eventB, weight)
	// TO DO 

	// Print the adjacency list
	eventGraph.printGraph();

	// Depth First traversal should print event information not just indices
	int start = 0;
	// Call DFT 
	// eventGraph.DFT(0, ...);


	bool found = false;
	// Depth First search
	string eventName1 = ""; //replace with an event name that exists 
	// Call DFS 
	// TO DO:  
	// found = eventGraph.DFS(eventName1, ...);
	if(found){
		cout << eventName1 << " has been found in the graph!" << endl;
	}else{
		cout << eventName1 << " has not been found in the graph!" << endl;
	}

	string eventName2 = ""; //replace with an event name that DOES NOT exist 
	// Call DFS 
	// TO DO:
	// found = eventGraph.DFS(eventName2, ...);
	if(found){
		cout << eventName2 << " has been found in the graph!" << endl;
	}else{
		cout << eventName2 << " has not been found in the graph!" << endl;
	}

	return 0;
}
