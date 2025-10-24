#ifndef EVENTTICKET340_H
#define EVENTTICKET340_H

#include <string>
#include "Organizer.h"
using namespace std;

class EventTicket340 {
private:
    Organizer organizer;

public:
    EventTicket340();

    ~EventTicket340();

    void createOrganizer(const string &username,
                         const string &email,
                         const string &password,
                         const string &bio,
                         const string &profilePicture);

    Organizer &getOrganizer();

    const Organizer &getOrganizer() const;
};

#endif
