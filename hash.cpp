#include <iostream>
#include <string>
#include "hash.h"

using namespace std;


Hash::Hash() {
    // initializing the hashmap
    for (int i = 0; i < tableSize; ++i) {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->car = "empty";
        HashTable[i]->next = nullptr;
    }
}

void Hash::addItem(string name, string car) {
    int index = makeHash(name);
    if (HashTable[index]->name == "empty") {
        HashTable[index]->name = name;
        HashTable[index]->car = car;
    } else {
        item *ptr = HashTable[index];
        item *newItem = new item;
        newItem->name = name;
        newItem->car = car;
        newItem->next = nullptr;

        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newItem;
    }
}


int Hash::numberOfItemsInIndex(int index) {
    item *ptr = HashTable[index];
    int count = 0;
    if (ptr->name == "empty") {
        return count;
    }
    while (ptr != nullptr) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void Hash::printTable() {
    int number;
    for (int i = 0; i < tableSize; ++i) {
        number = numberOfItemsInIndex(i);
        cout << "------------------------" << endl;
        cout << "index = " << i << endl;
        item *curItem = HashTable[i];
        for (int j = 0; j < number; ++j) {
            cout << curItem->name << " " << curItem->car << endl;
            curItem = curItem->next;
        }
        cout << "total number of items: " << number << endl;
    }
}

int Hash::makeHash(string key) {
    unsigned long hash = 5381;
    for (int i = 0; i < key.length(); ++i) {
        hash = ((hash << 5) + hash) + key[i];
    }
    int index = hash % tableSize;
    return index;
}

string Hash::findCar(string name) {
    int index = makeHash(name);
    string car;

    item *cur = HashTable[index];
    while (cur != nullptr) {
        if (cur->name == name) {
            return cur->car;
        }
        cur = cur->next;
    }
    return "The car with associate name: " + name + " is not found";
}

void Hash::removeItem(string name) {
    int index = makeHash(name);

    item *prev = nullptr;
    item *toRemove;
    item *cur = HashTable[index];

    // index is empty
    if (cur->name == "empty") {
        cout << "No such item in HashMap";
    }

        // only 1 item and matched
    else if (cur->name == name && cur->next == nullptr) {
        cur->name = "empty";
        cur->car = "empty";
        cout << name << "was removed" << endl;
    }

        // item to be removed is the first in the list
    else if (cur->name == name) {
        toRemove = cur;
        HashTable[index] = HashTable[index]->next;
        delete toRemove;
        cout << name << "was removed" << endl;

    }
        // other cases
    else {
        prev = cur;
        cur = cur->next;
        while (cur != nullptr && cur->name != name) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "No such item in HashMap";
        } else {
            prev->next = cur->next;
            delete cur;
            cout << name << "was removed" << endl;
        }
    }

}
