#include "VenueEvent.h"
#include <iostream>
using namespace std;

void VenueEvent::stream_out(ostream &outS) const {
    outS << "\n=== Venue Event ===\n";
    outS << "Name: " << name << '\n';
    outS << "Description: " << description << '\n';
    outS << "Rating: " << rating << '\n';
    outS << "Sold Tickets: " << soldTicketsCount << '\n';
    outS << "Venue: " << venue << '\n';
    outS << "Date/Time: " << dateTime << '\n';
    outS << "Capacity: " << capacity << '\n';
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
