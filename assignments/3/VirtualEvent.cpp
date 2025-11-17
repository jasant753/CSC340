#include "VirtualEvent.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void VirtualEvent::stream_out(ostream& outS) const {
    outS << "\n=== Virtual Event ===\n";
    outS << "Name: " << name << '\n';
    outS << "Description: " << description << '\n';
    outS << "Rating: " << rating << '\n';
    outS << "Sold Tickets: " << soldTicketsCount << '\n';
    outS << "Stream link: " << streamLink << '\n';
    outS << "Audience: " << audience << '\n';
}

bool VirtualEvent::sell(int quantity) {
    if (quantity <= 0) return false;
    soldTicketsCount += quantity;

    const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string code = "CODE-";
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 5; ++i) code += charset[rand() % charset.size()];

    cout << "Sold " << quantity << " virtual ticket(s). Access code: " << code << '\n';
    return true;
}
