#include "stringrep.h"
#include <cstring>

StringRep::StringRep() {
    rep = new char[1];
    rep[0] = '\0';
}

StringRep::StringRep(const StringRep& s) {
    rep = new char[s.length() + 1];
    ::strcpy(rep, s.rep);
}

int StringRep::length() const { return std::strlen(rep); }

StringRep& StringRep::operator=(const StringRep& rhs) {
    if (this == &rhs) return *this;
    delete[] rep;
    rep = new char[rhs.length() + 1];
    ::strcpy(rep, rhs.rep);
    return *this;
}

StringRep::~StringRep() {
    // rep can't be a dangling pointer so far;
    delete[] rep;
}

StringRep::StringRep(const char* s) {
    rep = new char[::strlen(s) + 1];
    ::strcpy(rep, s);
}

StringRep StringRep::operator+(const StringRep& rhs) {
    int size = length() + rhs.length() + 1;
    char* buf = new char[size];
    ::strcpy(buf, rep);
    ::strcat(buf, rhs.rep);
    StringRep result(buf);
    delete buf;
    return result;
}

std::ostream& operator<<(std::ostream& os, const StringRep& str) {
    os << str.rep;
    return os;
}

