#ifndef VENUEEVENT_H
#define VENUEEVENT_H

#include "Event.h"
#include <string>
using namespace std;

class VenueEvent : public Event {
private:
    string venue;
    string dateTime;
    int    capacity = 0;

public:
    VenueEvent() = default;
    VenueEvent(const string& name, const string& description, int rating,
               const string& venue, const string& dateTime, int capacity)
        : Event(name, description, rating),
          venue(venue), dateTime(dateTime), capacity(capacity) {}

    void display() const override;
    bool sell(int quantity) override;
};

#endif
