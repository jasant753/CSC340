#include "EventTicket340.h"
#include "Organizer.h"
#include <string>
using namespace std;

void EventTicket340::createOrganizer(const string &username,
                                     const string &email,
                                     const string &password,
                                     const string &bio,
                                     const string &profilePicture) {
    organizer.~Organizer();
    new(&organizer) Organizer(username, email, password, bio, profilePicture);
}

Organizer &EventTicket340::getOrganizer() {
    return organizer;
}

const Organizer &EventTicket340::getOrganizer() const {
    return organizer;
}
