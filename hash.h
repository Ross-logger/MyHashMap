//
// Created by admin on 20/11/2023.
//
#include <iostream>
#include <string>


using namespace std;

#ifndef MYHASHMAP_HASH_H
#define MYHASHMAP_HASH_H

#endif //MYHASHMAP_HASH_H

int const TABLESIZE = 20;


class Hash {
private:
    static const int tableSize = TABLESIZE;

    struct item {
        string name;
        string car;
        item *next;
    };

    item *HashTable[tableSize];
public:
    Hash();

    int makeHash(string key);

    void addItem(string name, string car);

    int numberOfItemsInIndex(int index);

    void printTable();

    string findCar(string name);

    void removeItem(string name);
};