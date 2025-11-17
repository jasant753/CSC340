#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <string>
#include <memory>
#include <ostream>
#include <istream>
#include "Event.h"
#include "LinkedBagDS/LinkedBag.h"
using namespace std;

class Organizer {
private:
    string username;
    string email;
    string password;
    string bio;
    string profilePicture;

    LinkedBag<shared_ptr<Event> > events; // Updated to smart pointer


public:
    Organizer() = default;

    Organizer(const string &username,
              const string &email,
              const string &password,
              const string &bio,
              const string &profilePicture);

    // Big 3 Implementation -------------------------------------------

    // Copy Constructor
    Organizer(const Organizer &other)
        : username(other.username),
          email(other.email),
          password(other.password),
          bio(other.bio),
          profilePicture(other.profilePicture) {
        // copy events
        int total = other.events.getCurrentSize();
        for (int i = 0; i < total; ++i) {
            auto node = other.events.findKthItem(i);
            if (node && node->getItem()) {
                events.reverseAppendK(node->getItem(), 0);
            }
        }
    }

    // Copy Assignment Operator
    Organizer &operator=(const Organizer &other) {
        if (this != &other) {
            username = other.username;
            email = other.email;
            password = other.password;
            bio = other.bio;
            profilePicture = other.profilePicture;

            while (!events.isEmpty()) {
                auto node = events.findKthItem(0);
                if (!node) break;
                events.remove(node->getItem());
            }

            int total = other.events.getCurrentSize();
            for (int i = 0; i < total; ++i) {
                auto node = other.events.findKthItem(i);
                if (node && node->getItem()) {
                    events.reverseAppendK(node->getItem(), 0);
                }
            }
        }
        return *this;
    }

    // Destructor
    ~Organizer() {}

    // ------------------------------------------------------------------

    const string &getUsername() const { return username; }
    const string &getEmail() const { return email; }
    const string &getBio() const { return bio; }
    const string &getProfilePicture() const { return profilePicture; }

    bool modifyPassword(const string &newPassword);

    bool createEvent(shared_ptr<Event> e);

    void displayEventK(int k) const;

    void displayAllEvents() const;

    bool modifyEvent(int k);

    bool sellTicket(int k, int quantity);

    bool deleteEvent(int k);

    int getEventCount() const { return events.getCurrentSize(); }

    bool operator==(const Organizer &otherOrganizer) const;

    // Friend functions for operator override
    friend ostream &operator<<(ostream &outS, const Organizer &outObj);
    friend istream &operator>>(istream &inS, Organizer &inObj);

};


#endif
