#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <ostream>
#include <istream>
#include <iostream>
#include <limits>
using namespace std;

class Event {
protected:
    string name;
    string description;
    int rating = 0;
    int soldTicketsCount = 0;

    // Assignment 3 functions -------------------------------------------
    virtual void stream_out(ostream &outS) const;

    friend ostream &operator<<(std::ostream &outS, const Event &e) {
        e.stream_out(outS);
        return outS;
    }

    friend istream &operator>>(istream &inS, Event &inObj) {
        cout << "Name: ";
        getline(inS >> ws, inObj.name);

        cout << "Description: ";
        getline(inS, inObj.description);

        cout << "Rating (integer): ";
        while (!(inS >> inObj.rating)) {
            inS.clear();
            inS.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid rating. Enter an integer: ";
        }
        inS.ignore(numeric_limits<streamsize>::max(), '\n');
        return inS;
    }

    // ------------------------------------------------------------------


public:
    // Default constructor
    Event() = default;

    Event(const string &name, const string &description, int rating)
        : name(name), description(description), rating(rating) {
    }

    // Big 3 Implementation -------------------------------------------

    // Copy Constructor
    Event(const Event &other)
        : name(other.name),
          description(other.description),
          rating(other.rating),
          soldTicketsCount(other.soldTicketsCount) {
    }

    // Copy Assignment Operator
    Event &operator=(const Event &other) {
        if (this != &other) {
            // prevent self-assignment
            name = other.name;
            description = other.description;
            rating = other.rating;
            soldTicketsCount = other.soldTicketsCount;
        }
        return *this;
    }

    virtual ~Event() {
    }

    // ------------------------------------------------------------------

    //virtual void display() const;
    virtual bool modify(const string &newName, const string &newDesc);

    virtual bool sell(int quantity);

    const string &getName() const { return name; }
    const string &getDescription() const { return description; }
    int getRating() const { return rating; }
    int getSoldTicketsCount() const { return soldTicketsCount; }

    bool operator==(const Event &otherEvent) const;
};

#endif
