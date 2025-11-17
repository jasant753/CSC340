#ifndef EVENT_H
#define EVENT_H
#include <string>
using namespace std;

class Event {
protected:
    string name;
    string description;
    int    rating = 0;
    int    soldTicketsCount = 0;

public:
    Event() = default;
    Event(const string& name, const string& description, int rating)
        : name(name), description(description), rating(rating) {}

    virtual ~Event();

    virtual void display() const;
    virtual bool modify(const string& newName, const string& newDesc);
    virtual bool sell(int quantity);

    const string& getName() const { return name; }
    const string& getDescription() const { return description; }
    int getRating() const { return rating; }
    int getSoldTicketsCount() const { return soldTicketsCount; }

    bool operator==(const Event& otherEvent) const;
};

#endif
