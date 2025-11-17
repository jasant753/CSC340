#ifndef VENUEEVENT_H
#define VENUEEVENT_H

#include "Event.h"
#include <string>
#include <limits>
using namespace std;

class VenueEvent : public Event {
private:
    string venue;
    string dateTime;
    int capacity = 0;

    // Assignment 3 functions -------------------------------------------

    void stream_out(ostream &outS) const override;

    friend istream &operator>>(istream &inS, VenueEvent &inObj) {
        // Read base Event part
        Event &base = static_cast<Event &>(inObj);
        operator>>(inS, base);

        cout << "Venue: ";
        getline(inS, inObj.venue);

        cout << "Date/Time: ";
        getline(inS, inObj.dateTime);

        cout << "Capacity (integer): ";
        while (!(inS >> inObj.capacity)) {
            inS.clear();
            inS.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid capacity. Enter an integer: ";
        }
        inS.ignore(numeric_limits<streamsize>::max(), '\n');
        return inS;
    }

    // ------------------------------------------------------------------


public:
    // Default constructor
    VenueEvent() = default;

    VenueEvent(const string &name, const string &description, int rating,
               const string &venue, const string &dateTime, int capacity)
        : Event(name, description, rating),
          venue(venue), dateTime(dateTime), capacity(capacity) {
    }

    bool sell(int quantity) override;

    // Big 3 Implementation -------------------------------------------

    // Copy Constructor
    VenueEvent(const VenueEvent &other)
        : Event(other),
          venue(other.venue),
          dateTime(other.dateTime),
          capacity(other.capacity) {
    }

    // Copy Assignment Operator
    VenueEvent &operator=(const VenueEvent &other) {
        if (this != &other) {
            Event::operator=(other);
            venue = other.venue;
            dateTime = other.dateTime;
            capacity = other.capacity;
        }
        return *this;
    }

    // Destructor
    ~VenueEvent() override {
    }

    // ------------------------------------------------------------------
};

#endif
