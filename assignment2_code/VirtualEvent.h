#ifndef VIRTUALEVENT_H
#define VIRTUALEVENT_H

#include "Event.h"
#include <string>
using namespace std;

class VirtualEvent : public Event {
private:
    string streamLink;
    string audience;

public:
    VirtualEvent() = default;

    VirtualEvent(const string &name, const string &description, int rating,
                 const string &streamLink, const string &audience)
        : Event(name, description, rating),
          streamLink(streamLink), audience(audience) {
    }

    void display() const override;

    bool sell(int quantity) override;
};

#endif
