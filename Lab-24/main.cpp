#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Goat.h"
#include <set>

const int MAX_AGE = 20;

int main_menu() {
    int ch = 0;
    while (ch < 1 || ch > 4) {
        cout << "\n*** GOAT MANAGER 3001 ***\n";
        cout << "[1] Add a goat\n";
        cout << "[2] Delete a goat\n";
        cout << "[3] List goats\n";
        cout << "[4] Quit\n";
        cout << "Choice --> ";
        cin >> ch;
    }
    return ch;
}

void display_trip(const set<Goat>& trip) {
    if (trip.empty()) {
        cout << "Trip is empty.\n";
        return;
    }
    int idx = 1;
    for (set<Goat>::const_iterator it = trip.begin(); it != trip.end(); ++it) {
        cout << "[" << idx++ << "] ";
        it->print();
        cout << endl;
    }
}

void add_goat(set<Goat>& trip, string names[], int ns, string colors[], int cs) {
    string n = names[rand() % ns];
    string c = colors[rand() % cs];
    int a = rand() % (MAX_AGE + 1);

    Goat g(n, a, c);
    trip.insert(g);
    cout << "Added: ";
    g.print();
    cout << endl;
}

void delete_goat(set<Goat>& trip) {
    if (trip.empty()) {
        cout << "No goats to delete.\n";
        return;
    }

    cout << "Select a goat to delete:\n";
    display_trip(trip);

    int pick = 0;
    cout << "Choice --> ";
    cin >> pick;

    if (pick < 1 || pick > (int)trip.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    set<Goat>::iterator it = trip.begin();
    for (int i = 1; i < pick; ++i) {
        ++it;
    }
    trip.erase(it);
    cout << "Goat deleted.\n";
}




int main() {
    srand(time(0));

    string names[] = {"Vida", "Nola", "Todd", "Faye", "Lena", "Owen", "Kyle", "Vern"}; // Preset arrays for random selection
    string colors[] = {"Red", "Gold", "Green", "Silver", "Teal", "Magenta", "Olive", "Blue"};
    int name_sz = 8;
    int color_sz = 8;

    set<Goat> trip;
    int choice = 0;

    while (choice != 4) {
        choice = main_menu();

        if (choice == 1) {
            add_goat(trip, names, name_sz, colors, color_sz);
        } else if (choice == 2) {
            delete_goat(trip);
        } else if (choice == 3) {
            display_trip(trip);
        }
    }

    cout << "Goodbye!\n";
    return 0;

}