#include "Organizer.h"
#include <iostream>
#include <memory>
using namespace std;

Organizer::Organizer(const string &username,
                     const string &email,
                     const string &password,
                     const string &bio,
                     const string &profilePicture)
    : username(username),
      email(email),
      password(password),
      bio(bio),
      profilePicture(profilePicture) {
}

// Assignment 3 functions -------------------------------------------

ostream& operator<<(ostream& outS, const Organizer& outObj) {
    outS << "\n=== Organizer Profile ===\n";
    outS << "Username: " << outObj.username << '\n';
    outS << "Email: " << outObj.email << '\n';
    outS << "Bio: " << outObj.bio << '\n';
    outS << "Profile Picture (path): " << outObj.profilePicture << '\n';
    return outS;
}

istream& operator>>(istream& inS, Organizer& inObj) {
    cout << "Username: ";
    getline(inS >> ws, inObj.username);

    cout << "Email: ";
    getline(inS, inObj.email);

    cout << "Password: ";
    getline(inS, inObj.password);

    cout << "Short bio: ";
    getline(inS, inObj.bio);

    cout << "Profile picture path: ";
    getline(inS, inObj.profilePicture);

    return inS;
}

// ------------------------------------------------------------------

bool Organizer::modifyPassword(const string &newPassword) {
    if (newPassword.empty()) return false;
    password = newPassword;
    return true;
}

bool Organizer::createEvent(std::shared_ptr<Event> e) {
    return events.reverseAppendK(e, 0);
}

void Organizer::displayAllEvents() const {
    cout << "\n=== All Events ===\n";
    int total = events.getCurrentSize();
    if (total == 0) {
        cout << "(No events yet)\n";
        return;
    }
    for (int i = 0; i < total; ++i) {
        auto node = events.findKthItem(i);
        if (!node) continue;
        shared_ptr<Event> e = node->getItem();
        if (!e) continue;
        cout << "[" << (i + 1) << "]\n";
        // e->display();
        cout << *node->getItem() << '\n'; // Display function changed to implement operator overload requirement for Assignment 3
        cout << "-------------------------\n";
    }
}

void Organizer::displayEventK(int k) const {
    int total = events.getCurrentSize();
    if (k < 1 || k > total) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return;
    }
    auto node = events.findKthItem(k - 1);
    if (!node || !node->getItem()) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return;
    }
    cout << "\n--- Event [" << k << "] ---\n";
    // e->display();
    cout << *node->getItem() << '\n'; // Display function changed to implement operator overload requirement for Assignment 3
    cout << "-------------------------\n";
}

bool Organizer::modifyEvent(int k) {
    int total = events.getCurrentSize();
    if (k < 1 || k > total) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }
    auto node = events.findKthItem(k - 1);
    if (!node) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }
    shared_ptr<Event> e = node->getItem();
    if (!e) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }

    string newName, newDesc;
    cout << "New name: ";
    getline(cin >> ws, newName);
    cout << "New description: ";
    getline(cin, newDesc);

    if (e->modify(newName, newDesc)) {
        cout << "Event updated.\n";
        return true;
    } else {
        cout << "Invalid choice. Please try again.\n";
        return false;
    }
}

bool Organizer::sellTicket(int k, int quantity) {
    int total = events.getCurrentSize();
    if (k < 1 || k > total) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }
    auto node = events.findKthItem(k - 1);
    if (!node) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }
    shared_ptr<Event> e = node->getItem();
    if (!e) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }
    if (quantity <= 0) {
        cout << "Invalid choice. Please try again.\n";
        return false;
    }
    if (e->sell(quantity)) {
        cout << "Sale completed\n";
        return true;
        return true;
    } else {
        cout << "Sale failed.\n";
        return false;
    }
}

bool Organizer::deleteEvent(int k) {
    int total = events.getCurrentSize();
    if (k < 1 || k > total) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }
    auto node = events.findKthItem(k - 1);
    if (!node) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }
    shared_ptr<Event> e = node->getItem();
    if (!e) {
        cout << "Event " << k << " doesn't exist. There are only " << total << " event(s).\n";
        return false;
    }
    cout << "Deleting event: " << e->getName() << '\n';
    events.remove(e);
    return true;
}

bool Organizer::operator==(const Organizer &otherOrganizer) const {
    return (Organizer::username == otherOrganizer.username) &&
           (Organizer::email == otherOrganizer.email);
}
