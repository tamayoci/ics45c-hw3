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

int String::size() const {
    return strlen(buf);
}

String String::reverse() const {
    String result;
    reverse_cpy(result.buf, buf);
    return result;
}

int String::indexOf(char c) const {
    const char *ptr = strchr(buf, c);
    if (ptr == nullptr) return -1;
    return ptr - buf;
}

int String::indexOf(const String &s) const {
    const char *ptr = strstr(buf, s.buf);
    if (ptr == nullptr) return -1;
    return ptr - buf;
}

bool String::operator==(const String &s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const {
    return strcmp(buf, s.buf) != 0;
}

