#include "string.hpp"
#include <iostream>

using namespace std;

String::String(const char *s) {
    strncpy(buf, s, MAXLEN - 1);
    buf[MAXLEN - 1] = '\0';
}

String::String(const String &s) {
    strcpy(buf, s.buf);
}

String &String::operator=(const String &s) {
    if (this != &s) {
        strcpy(buf, s.buf);
    }
    return *this;
}

char &String::operator[](int index) {
    if (!in_bounds(index)) {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }
    return buf[index];
}

