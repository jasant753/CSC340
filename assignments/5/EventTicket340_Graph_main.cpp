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


	// Create list of University campus events
	vector<Event> events;
	events.reserve(10);

	events.emplace_back(
		"New Student Orientation",
		"Welcome sessions for incoming students",
		4.6,   // Average student rating based on past year's events
		1200   // Tickets available
	);

	events.emplace_back(
		"Fall Career Fair",
		"Employers recruiting interns and graduates",
		4.3,
		950
	);

	events.emplace_back(
		"Homecoming Game",
		"Annual homecoming football game",
		4.7,
		1800
	);

	events.emplace_back(
		"Research Symposium",
		"Student and faculty research presentations",
		4.1,
		420
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
		1100
	);

	events.emplace_back(
		"Hackathon",
		"24-hour coding and innovation competition",
		5.0,
		300
	);

	events.emplace_back(
		"Spring Concert",
		"Live concert featuring popular artists",
		4.9,
		2000
	);

	events.emplace_back(
		"Graduate School Info Session",
		"Information session for prospective grad students",
		4.0,
		350
	);

	events.emplace_back(
		"Commencement Ceremony",
		"University graduation ceremony",
		4.7,
		2500
	);


	// Directed graph was chosen to represent a flow between campus events.
	// Based on student timelines, shared interests, and academic progression data from past students
	// Event weight represents how strongly attending one event leads to attending the next based on student survey

	int n = static_cast<int>(events.size());
	bool directed = false;

	Graph<int> eventGraph(n, directed);

	// Add 15-20 edges (eventA, eventB, weight)
	// TO DO

	// Orientation
	eventGraph.addEdge(0, 5, 8);  // Orientation -> Cultural Festival (campus community)
	eventGraph.addEdge(0, 4, 7);  // Orientation -> Guest Speaker (academic engagement)
	eventGraph.addEdge(0, 1, 6);  // Orientation -> Career Fair (early career planning)
	eventGraph.addEdge(0, 6, 5);  // Orientation -> Hackathon (clubs/activities)

	// Fall momentum
	eventGraph.addEdge(5, 2, 7);  // Cultural Festival -> Homecoming (school spirit)
	eventGraph.addEdge(4, 3, 6);  // Guest Speaker -> Research Symposium (academic pathway)
	eventGraph.addEdge(6, 3, 8);  // Hackathon -> Research Symposium (projects -> research posters)
	eventGraph.addEdge(1, 4, 5);  // Career Fair -> Guest Speaker (industry talk)

	// Community Events
	eventGraph.addEdge(2, 5, 6);  // Homecoming -> Cultural Festival
	eventGraph.addEdge(2, 7, 7);  // Homecoming -> Spring Concert (students who go to big events)

	// Academia and career
	eventGraph.addEdge(3, 8, 9);  // Research Symposium -> Grad Info Session
	eventGraph.addEdge(4, 8, 6);  // Guest Speaker -> Grad Info Session
	eventGraph.addEdge(6, 1, 6);  // Hackathon -> Career Fair (recruiting pipeline)

	// Spring vibes
	eventGraph.addEdge(8, 9, 10); // Grad Info Session -> Commencement (end goal)
	eventGraph.addEdge(7, 9, 7);  // Spring Concert -> Commencement (end-of-year flow)

	// Misc.
	eventGraph.addEdge(5, 6, 6);  // Cultural Festival -> Hackathon (student org involvement)
	eventGraph.addEdge(1, 3, 5);  // Career Fair -> Research Symposium (professional development)
	eventGraph.addEdge(3, 9, 8);  // Research Symposium -> Commencement (capstone/end-of-program)


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
