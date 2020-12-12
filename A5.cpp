#include <iostream>
#include "SkipList.h"
#include "Entry.h"

using namespace std;

int main() {
    SkipList s;
    
    cout << "Inserting 8 entries and printing skip list:" << endl;
    for(int i = 0; i < 8; i++){
        Entry e;
        e.random();
        s.put(i, e.getData());
    }
    s.print();

    cout << endl << "Erasing entry 7 and printing skip list:" << endl; 
    s.erase(7);
    s.print();

    cout << endl << "Finding and printing element 2:" << endl;
    Entry findEntry = s.find(2);
    cout << findEntry.toString() << endl;

    cout << endl << "Finding and printing element 7 (not in skip list):" << endl;
    Entry findEntry1 = s.find(7);
    cout << findEntry1.toString() << endl;

    cout << endl << "Printing greaterEntry(2):" << endl;
    Entry findGreaterEntry = s.greaterEntry(2);
    cout << findGreaterEntry.toString() << endl;

    cout << endl << "Printing lessEntry(2):" << endl;
    Entry findLessEntry = s.lessEntry(2);
    cout << findLessEntry.toString() << endl;
    
    SkipList l;
    
    cout << endl << "Inserting 40 entries into an empty skip list and printing it:" << endl;
    for(int i = 0; i < 40; i++){
        Entry o;
        o.random();
        l.put(i, o.getData());
    }
    l.print();

   
}