#include "Entry.h"

class QuadNode {
    friend class SkipList;
    private:
        QuadNode* next[4];
        Entry* value;

    public:
        QuadNode() {
            for (int i = 0; i < 4; i++) {
                next[i] = nullptr;
            }
            value = nullptr;
        }

        QuadNode(int key, string v) {
            for (int i = 0; i < 4; i++) {
                next[i] = nullptr;
            }
            value = new Entry(key, v);
        }

        ~QuadNode(){
            delete value;
        }

    };