#include "Event.h"
#include <iostream>
using namespace std;

void Event::stream_out(ostream &outS) const {
    outS << "\n=== Event ===\n";
    outS << "Name: " << name << '\n';
    outS << "Description: " << description << '\n';
    outS << "Rating: " << rating << '\n';
    outS << "Sold Tickets: " << soldTicketsCount << '\n';
}

bool Event::modify(const string &newName, const string &newDesc) {
    if (newName.empty()) return false;
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

bool Event::operator==(const Event &otherEvent) const {
    return this->name == otherEvent.name;
}
