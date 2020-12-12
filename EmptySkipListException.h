#include <iostream>

using namespace std;

class EmptySkipListException {

private: 
    string errMsg;

public:
    EmptySkipListException(const string &err) : errMsg(err) {}
    string getError() { return errMsg; }

};