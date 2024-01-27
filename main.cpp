#include <iostream>
#include <string>
#include "hash.h"


using namespace std;

int main() {
    // Testing
    Hash h;
    h.addItem("Yusuf", "Camry 3.5");
    h.addItem("Amira", "Matiz");
    h.addItem("Ansar", "Tesla Model 3 performance");
    h.addItem("Alina", "Ford Focus 3");
    h.addItem("Albert", "Land Cruiser 200");
    h.addItem("Milash", "Rav4 2024");

    h.printTable();

    string name;
    cout << endl << endl << "Input name for search: ";
    cin >> name;
    while (name != "exit") {
        cout << h.findCar(name) << endl;
        cout << "Input another name: ";
        cin >> name;
    }
    return 0;
}
