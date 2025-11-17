#ifndef VIRTUALEVENT_H
#define VIRTUALEVENT_H

#include "Event.h"
#include <string>
using namespace std;

class VirtualEvent : public Event {
private:
    string streamLink;
    string audience;

    // Assignment 3 functions -------------------------------------------
    void stream_out(ostream& outS) const override;

    friend istream& operator>>(istream& inS, VirtualEvent& inObj) {
        Event& base = static_cast<Event&>(inObj);
        operator>>(inS, base);

        cout << "Stream link: ";
        getline(inS, inObj.streamLink);

        cout << "Audience: ";
        getline(inS, inObj.audience);

        return inS;
    }
// ------------------------------------------------------------------

public:
    // Default constructor
    VirtualEvent() = default;

    VirtualEvent(const string &name, const string &description, int rating,
                 const string &streamLink, const string &audience)
        : Event(name, description, rating),
          streamLink(streamLink), audience(audience) {
    }

    // Big 3 Implementation -------------------------------------------

    // Copy Constructor
    VirtualEvent(const VirtualEvent& other)
            : Event(other),
              streamLink(other.streamLink),
              audience(other.audience) {
    }

    // Copy Assignment Operator
    VirtualEvent& operator=(const VirtualEvent& other) {
        if (this != &other) {
            Event::operator=(other); // reuse base assignment
            streamLink = other.streamLink;
            audience = other.audience;
        }
        return *this;
    }

// Destructor
    ~VirtualEvent() override {
    }

    // ------------------------------------------------------------------

    bool sell(int quantity) override;
};

#endif
