#include <iostream>
#include <string>
#include <cstdlib>
#include "Entry.h"
#include "QuadNode.h"
#include "EmptySkipListException.h"

using namespace std;

class SkipList {

public:
    SkipList();
    ~SkipList();
    Entry& find(int k); //done
    Entry& greaterEntry(int k);
    Entry& lessEntry(int k);
    void put(int k, string v); //done
    void erase(int k); //done
    int size() const; //done
    bool empty() const; //done
    void print() const; //done

private:
    int list_size;
    QuadNode* header;
    QuadNode* end;
};

SkipList::SkipList() {
    header = new QuadNode();
    end = new QuadNode(-1, "end");
}

SkipList::~SkipList() {
    QuadNode* current = header;
    QuadNode* next;
    while(current != nullptr) {
        next = current->next[0];
        delete current;
        current = next;
    }
    delete end;
}

Entry& SkipList::find(int k) {
    if (empty()) {
        return *(end->value);
    }

    QuadNode* current = header;
    for(int i = 3; i >= 0; i--) {
        while (current->next[i] != nullptr && current->next[i]->value->getKey() < k) {
            current = current->next[i];
        }    
    }
    current = current->next[0];
    if(current != nullptr) {
        if(current->value->getKey() == k) {
            return *(current->value);
        }
    }

    return *(end->value);
}

Entry& SkipList::greaterEntry(int k) {
     if (empty()) {
        return *(end->value);
    }

    QuadNode* current = header;
    for(int i = 3; i >= 0; i--) {
        while (current->next[i] != nullptr && current->next[i]->value->getKey() < k) {
            current = current->next[i];
        }    
    }
    current = current->next[0];
    if(current != nullptr) {
        if(current->value->getKey() == k) {
            return *(current->next[0]->value);
        }
    }

    return *(end->value);
}

Entry& SkipList::lessEntry(int k) {
     if (empty()) {
        return *(end->value);
    }

    QuadNode* current = header;
    for(int i = 3; i >= 0; i--) {
        while (current->next[i] != nullptr && current->next[i]->value->getKey() < k-1) {
            current = current->next[i];
        }    
    }
    current = current->next[0];
    if(current != nullptr) {
        if(current->value->getKey() == k-1) {
            return *(current->value);
        }
    }

    return *(end->value);
}

void SkipList::put(int k, string v) {
    Entry* temp = &find(k);

    if(temp->getKey() == -1 && temp->getData().compare("end") == 0) {
        QuadNode* current = header;
        QuadNode* lastUpperNode[4];
        for(int i = 3; i >= 0; i--) {
            while (current->next[i] != nullptr && current->next[i]->value->getKey() < k) {
                current = current->next[i];
            }   
            lastUpperNode[i] = current; 
        }
        current = current->next[0];
        int nodeHeight = rand() % 4;
        QuadNode* newNode = new QuadNode(k, v);
        for(int i = nodeHeight; i >= 0; i--) {
            newNode->next[i] = lastUpperNode[i]->next[i];
            lastUpperNode[i]->next[i] = newNode;
            
        }
    
    }else {
        temp->data = v;
    }
}

void SkipList::erase(int key) {
    QuadNode *curr = header;
    QuadNode *traversedUpperNodes[4];

    for (int i = 3; i >= 0; i--) {
        while (curr->next[i] != nullptr && curr->next[i]->value->getKey() < key) {
            curr = curr->next[i];
        }

        traversedUpperNodes[i] = curr;
    }

    curr = curr->next[0];
    if (curr != nullptr) {
        if (curr->value->getKey() == key) {
            for (int i = 0; i < 4; i++) {
                if (traversedUpperNodes[i]->next[i] != curr) {
                    break;
                }else {
                    traversedUpperNodes[i]->next[i] = curr->next[i];
                }
            }
            delete curr;
        }
    }else {
        throw EmptySkipListException ("erase failed");
    }
}

void SkipList::print() const {
    QuadNode* lowerCurrent = header->next[0];
    QuadNode* current;
    string output[4];
    for (int i = 0; i < 4; i++) {
        current = header->next[i];
        output[i] = "-inf--";
        while(lowerCurrent != nullptr) {
            if(current != nullptr && current == lowerCurrent) {
                int key = current->value->getKey();
                if(key < 10){
                    output[i] += "0" + to_string(current->value->getKey()) + "--";
                } else {
                    output[i] += to_string(current->value->getKey()) + "--";
                }
                current = current->next[i];
            }else {
                output[i] += "----";
            }
            lowerCurrent = lowerCurrent->next[0];
        }
        output[i] += "inf";
        lowerCurrent = header->next[0];
    }
    for(int i = 3; i >= 0; i--) {
        cout << output[i] << endl;
    }
}

int SkipList::size() const {
    return list_size;
}

bool SkipList::empty() const {
    return header->next[0] == nullptr;
}
 

