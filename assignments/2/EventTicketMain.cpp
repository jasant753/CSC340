#include <iostream>
#include <string>
#include <limits>
#include "VirtualEvent.h"
#include "VenueEvent.h"
#include "EventTicket340.h"
using namespace std;

void displayOrganizerMenu(Organizer &organizer) {
    int organizerChoice = 0;
    do {
        cout << "\n Hi, " << organizer.getUsername() << ", what would you like to do:\n"
                << "1. Display Profile\n"
                << "2. Modify Password\n"
                << "3. Create Event\n"
                << "4. Display All Events\n"
                << "5. Display Kth Event\n"
                << "6. Modify Event\n"
                << "7. Sell Tickets\n"
                << "8. Delete Event\n"
                << "0. Logout\n"
                << "Choice: ";
        cin >> organizerChoice;

        switch (organizerChoice) {
            case 1: {
                organizer.displayProfile();
                break;
            }
            case 2: {
                string newPassword;
                cout << "Enter new password: ";
                getline(cin >> ws, newPassword);
                if (organizer.modifyPassword(newPassword))
                    cout << "Password updated successfully.\n";
                else
                    cout << "Password update failed. Try again.\n";
                break;
            }
            case 3: {
                int eventType = 0, rating = 0;
                string name, description;

                cout << "\n=== Create Event ===\n";
                cout << "\nChoose type: \n[1] Virtual \n[2] Venue\nEnter 1 or 2: ";
                if (!(cin >> eventType)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (eventType != 1 && eventType != 2) {
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }

                cout << "Name: ";
                getline(cin >> ws, name);
                cout << "Description: ";
                getline(cin, description);
                cout << "Rating: ";
                if (!(cin >> rating)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (eventType == 1) {
                    string link, audience;
                    cout << "Stream link: ";
                    getline(cin, link);
                    cout << "Audience: ";
                    getline(cin, audience);
                    Event *e = new VirtualEvent(name, description, rating, link, audience);
                    organizer.createEvent(e);
                    cout << "Virtual Event created.\n";
                } else {
                    string venue, dt;
                    int capacity = 0;
                    cout << "Venue: ";
                    getline(cin, venue);
                    cout << "Date/Time: ";
                    getline(cin, dt);
                    cout << "Capacity: ";
                    if (!(cin >> capacity)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    Event *e = new VenueEvent(name, description, rating, venue, dt, capacity);
                    organizer.createEvent(e);
                    cout << "Venue Event created.\n";
                }
                break;
            }
            case 4: {
                organizer.displayAllEvents();
                break;
            }
            case 5: {
                cout << "\n=== Display K-th Event ===\n";
                int k = 0;
                cout << "Enter K: ";
                if (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                organizer.displayEventK(k);
                break;
            }
            case 6: {
                cout << "\n=== Modify Event ===\n";
                int k = 0;
                cout << "Enter Event ID: ";
                if (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                organizer.modifyEvent(k);
                break;
            }
            case 7: {
                cout << "\n=== Sell Tickets ===\n";
                int k = 0, qty = 0;
                cout << "Enter event ID: ";
                if (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                cout << "Quantity of tickets to sell: ";
                if (!(cin >> qty)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                organizer.sellTicket(k, qty);
                break;
            }
            case 8: {
                cout << "\n=== Delete Event ===\n";
                int k = 0;
                cout << "Enter K: ";
                if (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (organizer.deleteEvent(k)) {
                    cout << "Event deleted successfully.\n";
                } else {
                    cout << "";
                }
                break;
            }

            case 0: {
                cout << "Logging you out.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (organizerChoice != 0);
}

int main() {
    // Instantiating the program using the default constructor
    // With this implementation, the application will only have one organizer
    EventTicket340 eventTicket340;

    cout << "\nWelcome to EventTicket340:" << endl;

    string username, email, password, bio, picturePath;

    cout << "Username: ";
    getline(cin >> ws, username);

    cout << "Email: ";
    getline(cin >> ws, email);

    cout << "Password: ";
    getline(cin >> ws, password);

    cout << "Short bio: ";
    getline(cin >> ws, bio);

    cout << "Profile picture path: ";
    getline(cin >> ws, picturePath);

    eventTicket340.createOrganizer(username, email, password, bio, picturePath);

    // Retrieve the organizer
    Organizer currentOrganizer = eventTicket340.getOrganizer();

    // Display the main menu
    displayOrganizerMenu(currentOrganizer);

    return 0;
}
