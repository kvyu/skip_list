#ifndef _ENTRY_H
#define _ENTRY_H
#include <stdlib.h>
#include <string>

using namespace std;

class Entry {
friend class SkipList;
private:
    int key;
    string data;
public:
    Entry() {};
    Entry(int k, string d);
    void random();
    int getKey();
    string getData();
    string toString();
};

Entry::Entry(int k, string d) {
    key = k;
    data = d;
}

void Entry::random() {
    key = rand() % 100;
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 3; i++) {
        data += alphabet[rand() % 26];
    }
    
}

int Entry::getKey() {
    return key;
}

string Entry::getData() {
    return data;
}

string Entry::toString() {
    return "(" + std::to_string(key) + ", " + data + ")";
}

#endif