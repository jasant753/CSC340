#include "VenueEvent.h"
#include <iostream>
using namespace std;

void VenueEvent::display() const {
    cout << "\n=== Venue Event ===\n";
    cout << "Name: " << name << '\n';
    cout << "Description: " << description << '\n';
    cout << "Rating: " << rating << '\n';
    cout << "Sold Tickets: " << soldTicketsCount << '\n';
    cout << "Venue: " << venue << '\n';
    cout << "Date/Time: " << dateTime << '\n';
    cout << "Capacity: " << capacity << '\n';
}

bool VenueEvent::sell(int quantity) {
    if (quantity <= 0) return false;
    if (capacity < quantity) {
        cout << "Sold out or not enough seats. Available: " << capacity << '\n';
        return false;
    }
    capacity -= quantity;
    soldTicketsCount += quantity;
    cout << "Sold " << quantity << " ticket(s). Remaining capacity: " << capacity << '\n';
    return true;
}
