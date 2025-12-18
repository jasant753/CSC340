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

	vector<Event> events;
	events.reserve(10);

	events.emplace_back("event1",  "desc1",  5.0, 67);
	events.emplace_back("event2",  "desc2",  5.0, 67);
	events.emplace_back("event3",  "desc3",  5.0, 67);
	events.emplace_back("event4",  "desc4",  5.0, 67);
	events.emplace_back("event5",  "desc5",  5.0, 67);
	events.emplace_back("event6",  "desc6",  5.0, 67);
	events.emplace_back("event7",  "desc7",  5.0, 67);
	events.emplace_back("event8",  "desc8",  5.0, 67);
	events.emplace_back("event9",  "desc9",  5.0, 67);
	events.emplace_back("event10", "desc10", 5.0, 67);

	// Initialize a graph with n vertices (where n is the number of events) 
	//	 Indicate whether it is directed or undirected 
	// TO DO 

	int n = static_cast<int>(events.size());
	bool directed = false;

	Graph<int> eventGraph(n, directed);


	// Add 15-20 edges (eventA, eventB, weight)
	// TO DO

	eventGraph.addEdge(0, 1, 3);
	eventGraph.addEdge(0, 4, 7);
	eventGraph.addEdge(1, 2, 2);
	eventGraph.addEdge(1, 5, 6);
	eventGraph.addEdge(2, 3, 4);
	eventGraph.addEdge(2, 6, 1);
	eventGraph.addEdge(3, 7, 5);
	eventGraph.addEdge(4, 5, 2);
	eventGraph.addEdge(4, 8, 9);
	eventGraph.addEdge(5, 6, 3);
	eventGraph.addEdge(6, 9, 4);
	eventGraph.addEdge(7, 8, 6);
	eventGraph.addEdge(8, 9, 2);
	eventGraph.addEdge(9, 0, 8);
	eventGraph.addEdge(3, 1, 7);


	// Print the adjacency list
	eventGraph.printGraph();

	// Depth First traversal should print event information not just indices
	//int start = 0;
	// Call DFT 
	// eventGraph.DFT(0, ...);


	bool found = false;
	// Depth First search
	string eventName1 = "event6"; //replace with an event name that exists
	// Call DFS 
	// TO DO:  
	// found = eventGraph.DFS(eventName1, ...);
	if(found){
		cout << eventName1 << " has been found in the graph!" << endl;
	}else{
		cout << eventName1 << " has not been found in the graph!" << endl;
	}

	string eventName2 = "event11"; //replace with an event name that DOES NOT exist
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
