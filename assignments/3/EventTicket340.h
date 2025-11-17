#ifndef EVENTTICKET340_H
#define EVENTTICKET340_H

#include <string>
#include "Organizer.h"
using namespace std;

class EventTicket340 {
private:
    Organizer organizer;

public:
    EventTicket340() = default;

    void createOrganizer(const string &username,
                         const string &email,
                         const string &password,
                         const string &bio,
                         const string &profilePicture);

    // Big 3 Implementation -------------------------------------------

    // Copy Constructor
    EventTicket340(const EventTicket340 &other)
        : organizer(other.organizer) {
    }

    // Copy Assignment Operator
    EventTicket340 &operator=(const EventTicket340 &other) {
        if (this != &other) {
            organizer = other.organizer;
        }
        return *this;
    }

    ~EventTicket340() {
    }

    // ------------------------------------------------------------------

    Organizer &getOrganizer();

    const Organizer &getOrganizer() const;

    friend ostream& operator<<(ostream& outS, const EventTicket340& outObj) {
        outS << "Welcome to EventTicket340!\n";

        if (!outObj.getOrganizer().getUsername().empty()) {
            outS << outObj.organizer;
        }

        return outS;
    }
};


#endif
