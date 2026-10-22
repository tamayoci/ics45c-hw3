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

bool String::operator<(const String &s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>(const String &s) const {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<=(const String &s) const {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const {
    return strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String &s) const {
    String result;
    if (strlen(buf) + strlen(s.buf) >= MAXLEN) {
        std::cout << "ERROR: String Capacity Exceeded" << std::endl;
    }
    strncpy(result.buf, buf, MAXLEN - 1);
    result.buf[MAXLEN - 1] = '\0';
    strncat(result.buf, s.buf, MAXLEN - 1 - strlen(result.buf));
    return result;
}

String &String::operator+=(const String &s) {
    String temp(s);
    if (strlen(buf) + strlen(temp.buf) >= MAXLEN) {
        cout << "ERROR: String Capacity Exceeded" << endl;
    }
    strncat(buf, temp.buf, MAXLEN - 1 - strlen(buf));
    buf[MAXLEN - 1] = '\0';
    return *this;
}

void String::print(ostream &out) const {
    out << buf;
}

void String::read(istream &in) {
    in >> buf;
    buf[MAXLEN - 1] = '\0';
}

String::~String() {
}

int String::strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}

char *String::strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char *String::strncpy(char *dest, const char *src, int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src) {
    int i = 0;
    int j = strlen(dest);
    while (src[i] != '\0') {
        dest[j] = src[i];
        ++i;
        ++j;
    }
    dest[j] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *src, int n) {
    int i = 0;
    int j = strlen(dest);

    while (i < n && src[i] != '\0') {
        dest[j] = src[i];
        ++i;
        ++j;
    }

    dest[j] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right) {
    int i = 0;
    while (left[i] != '\0' && right[i] != '\0') {
        if (left[i] != right[i]) {
            return left[i] - right[i];
        }
        ++i;
    }
    return left[i] - right[i];
}

int String::strncmp(const char *left, const char *right, int n) {
    int i = 0;
    while (i < n && left[i] != '\0' && right[i] != '\0') {
        if (left[i] != right[i]) {
            return left[i] - right[i];
        }
        ++i;
    }
    if (i == n) {
        return 0;
    }
    return left[i] - right[i];
}

