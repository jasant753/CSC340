#include <iostream>
#include <string>
#include <limits>
#include "VirtualEvent.h"
#include "VenueEvent.h"
#include "EventTicket340.h"
#include <memory>
using namespace std;

void displayOrganizerMenu(Organizer &currentOrganizer) {
    int organizerChoice = 0;
    do {
        cout << "\n Hi, " << currentOrganizer.getUsername() << ", what would you like to do:\n"
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
        cout << endl;

        switch (organizerChoice) {
            case 1: {
                cout << currentOrganizer;
                break;
            }
            case 2: {
                string newPassword;
                cout << "Enter new password: ";
                getline(cin >> ws, newPassword);
                if (currentOrganizer.modifyPassword(newPassword))
                    cout << "Password updated successfully.\n";
                else
                    cout << "Password update failed. Try again.\n";
                break;
            }
            case 3: {
                cout << "\n=== Create Event ===\n"
                        "[1] Virtual\n[2] Venue\nEnter 1 or 2: ";
                int eventType = 0;
                if (!(cin >> eventType)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (eventType == 1) {
                    auto e = make_shared<VirtualEvent>();
                    cin >> *e;
                    currentOrganizer.createEvent(e);
                    cout << "\nCreated:\n" << *e << '\n';
                } else if (eventType == 2) {
                    auto e = make_shared<VenueEvent>();
                    cin >> *e;
                    currentOrganizer.createEvent(e);
                    cout << "\nCreated:\n" << *e << '\n';
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 4: currentOrganizer.displayAllEvents();
                break;
            case 5: {
                cout << "\nEnter K: ";
                int k = 0;
                if (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                currentOrganizer.displayEventK(k);
                break;
            }
            case 6: {
                cout << "\nEnter Event ID: ";
                int k = 0;
                if (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                currentOrganizer.modifyEvent(k);
                break;
            }
            case 7: {
                cout << "\nEnter event ID: ";
                int k = 0, qty = 0;
                if (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice.\n";
                    break;
                }
                cout << "Quantity of tickets to sell: ";
                if (!(cin >> qty)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                currentOrganizer.sellTicket(k, qty);
                break;
            }
            case 8: {
                cout << "\nEnter K: ";
                int k = 0;
                if (!(cin >> k)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (currentOrganizer.deleteEvent(k))
                    cout << "Event deleted successfully.\n";
                break;
            }
            case 0: cout << "Logging you out.\n";
                break;
            default: cout << "Invalid choice.\n";
                break;
        }
    } while (organizerChoice != 0);
}

int main() {
    // Instantiating the program using the default constructor
    // With this implementation, the application will only have one organizer
    EventTicket340 eventTicket340;

    EventTicket340 app;
    cout << app;
    Organizer newOrganizer;
    cin >> newOrganizer;
    app.getOrganizer() = newOrganizer;

    Organizer &currentOrganizer = app.getOrganizer();

    // Display the main menu
    displayOrganizerMenu(currentOrganizer);

    return 0;
}
