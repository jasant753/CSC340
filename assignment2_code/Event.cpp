#include "Event.h"
#include <iostream>
using namespace std;

Event::~Event() {}

void Event::display() const {
	cout << "\n=== Event ===\n";
	cout << "Name: " << name << '\n';
	cout << "Description: " << description << '\n';
	cout << "Rating: " << rating << '\n';
	cout << "Sold Tickets: " << soldTicketsCount << '\n';
}

bool Event::modify(const string& newName, const string& newDesc) {
	if (newName.empty()) return false;
	// simple default behavior
	name = newName;
	description = newDesc;
	return true;
}

bool Event::sell(int quantity) {
	if (quantity <= 0) return false;
	soldTicketsCount += quantity;
	cout << "Sold " << quantity << " ticket(s). Total sold: "
		 << soldTicketsCount << '\n';
	return true;
}

bool Event::operator==(const Event& otherEvent) const {
	return this->name == otherEvent.name;
}
