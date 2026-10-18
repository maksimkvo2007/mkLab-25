#ifndef GOAT_H
#define GOAT_H
#include <iostream>
#include <string>

using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;

public:
    // Default constructor
    Goat() {
        name = "";
        age = 0;
        color = "";
    }

    Goat(string n) {
        name = n;
        age = 0;
        color = "";
    }

    Goat(string n, int a) {
        name = n;
        age = a;
        color = "";
    }

    Goat(string n, int a, string c) {
        name = n;
        age = a;
        color = c;
    }
void setName(string n) { name = n; }
    string getName() const { return name; }

    void setAge(int a) { age = a; }
    int getAge() const { return age; }

    void setColor(string c) { color = c; }
    string getColor() const { return color; }

    // Print helper
    void print() const {
        cout << name << " (" << age << ", " << color << ")";
    }
};

#endif
