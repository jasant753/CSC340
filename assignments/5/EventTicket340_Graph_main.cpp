#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Event.h"

using namespace std;
int main() {
	vector<Event> events;
	events.reserve(10);

	// Create list of University campus events
	events.emplace_back(
		"New Student Orientation",
		"Welcome sessions for incoming students",
		4.6,   // Average student rating based on past year's events
		500   // Tickets sold
	);

	events.emplace_back(
		"Fall Career Fair",
		"Employers recruiting interns and graduates",
		4.3,
		200
	);

	events.emplace_back(
		"Homecoming Game",
		"Annual homecoming football game",
		4.7,
		600
	);

	events.emplace_back(
		"Research Symposium",
		"Student and faculty research presentations",
		4.1,
		60
	);

	events.emplace_back(
		"Guest Speaker Lecture",
		"Industry leader guest lecture",
		4.4,
		600
	);

	events.emplace_back(
		"Cultural Festival",
		"Celebration of cultural diversity on campus",
		4.8,
		350
	);

	events.emplace_back(
		"Hackathon",
		"24-hour coding and innovation competition",
		5.0,
		100
	);

	events.emplace_back(
		"Spring Concert",
		"Live concert featuring popular artists",
		4.9,
		500
	);

	events.emplace_back(
		"Graduate School Info Session",
		"Information session for prospective grad students",
		4.0,
		230
	);

	events.emplace_back(
		"Commencement Ceremony",
		"University graduation ceremony",
		4.7,
		150
	);

	// We chose undirected here because two event tickets being purchased together is inherently symmetric
	// i.e. You don't have to buy a ticket to Orientation in order to buy a ticket to the Career Fair
	int n = static_cast<int>(events.size());
	bool directed = false;

	Graph<int> eventGraph(n, directed);

	// Add edges (eventA, eventB, weight)
	// Edges created if two events have been purchased together at least once
	// Weight represents number of times both event tickets were purchesed by a unique student

	eventGraph.addEdge(0, 1, 3);  // Orientation + Career Fair
	eventGraph.addEdge(0, 5, 5);  // Orientation + Cultural Festival
	eventGraph.addEdge(0, 4, 2);  // Orientation + Guest Speaker
	eventGraph.addEdge(1, 4, 4);  // Career Fair + Guest Speaker
	eventGraph.addEdge(1, 6, 6);  // Career Fair + Hackathon
	eventGraph.addEdge(1, 3, 2);  // Career Fair + Research Symposium
	eventGraph.addEdge(2, 5, 3);  // Homecoming + Cultural Festival
	eventGraph.addEdge(2, 7, 7);  // Homecoming + Spring Concert
	eventGraph.addEdge(3, 4, 3);  // Research + Guest Speaker
	eventGraph.addEdge(3, 6, 4);  // Research + Hackathon
	eventGraph.addEdge(3, 8, 5);  // Research + Grad Info
	eventGraph.addEdge(4, 5, 2);  // Guest Speaker + Cultural Festival
	eventGraph.addEdge(4, 8, 4);  // Guest Speaker + Grad Info
	eventGraph.addEdge(5, 7, 6);  // Cultural Festival + Spring Concert
	eventGraph.addEdge(5, 6, 2);  // Cultural Festival + Hackathon
	eventGraph.addEdge(6, 7, 3);  // Hackathon + Spring Concert
	eventGraph.addEdge(7, 9, 5);  // Spring Concert + Commencement
	eventGraph.addEdge(8, 9, 8);  // Grad Info + Commencement

	// Print the adjacency list
	eventGraph.printGraph();

	// Depth First traversal should print event information not just indices
	int start = 0;

	// Call DFT
	eventGraph.DFT(start, events);

	bool found = false;
	// Depth First search
	string eventName1 = "Hackathon"; // Exists
	// Call DFS
	found = eventGraph.DFS(eventName1, start, events);

	if(found){
		cout << eventName1 << " has been found in the graph!" << endl;
	}else{
		cout << eventName1 << " has not been found in the graph!" << endl;
	}

	string eventName2 = "Gloving meetup"; // DOES NOT exist
	// Call DFS
	found = eventGraph.DFS(eventName2, start, events);

	if(found){
		cout << eventName2 << " has been found in the graph!" << endl;
	}else{
		cout << eventName2 << " has not been found in the graph!" << endl;
	}
	return 0;
}
