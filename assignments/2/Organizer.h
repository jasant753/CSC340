#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <string>
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
    LinkedBag<Event *> events;

public:
    Organizer() = default;

    Organizer(const string &username,
              const string &email,
              const string &password,
              const string &bio,
              const string &profilePicture);

    const string &getUsername() const { return username; }
    const string &getEmail() const { return email; }
    const string &getBio() const { return bio; }
    const string &getProfilePicture() const { return profilePicture; }


    void displayProfile() const;

    bool modifyPassword(const string &newPassword);

    bool createEvent(Event *e);

    void displayEventK(int k) const;

    void displayAllEvents() const;

    bool modifyEvent(int k);

    bool sellTicket(int k, int quantity);

    bool deleteEvent(int k);

    int getEventCount() const { return events.getCurrentSize(); }

    bool operator==(const Organizer &otherOrganizer) const;

    ~Organizer();
};

#endif
