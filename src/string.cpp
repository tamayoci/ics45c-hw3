#include "string.hpp"
#include <iostream>

using namespace std;

String::String(const char *s) {
    strncpy(buf, s, MAXLEN - 1);
    buf[MAXLEN - 1] = '\0';
}

