#include "VirtualEvent.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void VirtualEvent::display() const {
    cout << "\n=== Virtual Event ===\n";
    cout << "Name: " << name << '\n';
    cout << "Description: " << description << '\n';
    cout << "Rating: " << rating << '\n';
    cout << "Sold Tickets: " << soldTicketsCount << '\n';
    cout << "Stream link: " << streamLink << '\n';
    cout << "Audience: " << audience << '\n';
}

bool VirtualEvent::sell(int quantity) {
    if (quantity <= 0) return false;

    soldTicketsCount += quantity;

    srand(static_cast<unsigned>(time(nullptr)));

    const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string code = "CODE-";
    for (int i = 0; i < 5; ++i) {
        code += charset[rand() % charset.size()];
    }

    cout << "Sold " << quantity << " virtual ticket(s). Access code: "
            << code << '\n';
    return true;
}
