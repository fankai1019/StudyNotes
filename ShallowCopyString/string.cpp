#include "string.h"
#include "stringrep.h"

String::String() {
    rep = new StringRep();
    rep->count = 1;
}

String::String(const String& str) {
    // shallow copy here
    rep = str.rep;
    rep->count++;
}

String::String(const char* s) {
    rep = new StringRep(s);
    rep->count = 1;
}

String& String::operator=(const String& rhs) {
    if (this == &rhs) return *this;
    rhs.rep->count++;
    if (--rep->count == 0) {
        delete rep;
    }
    // shallow copy here
    rep = rhs.rep;
    return *this;
}

String::~String() {
    /*manually delete smart pointer won't delete the object when
     reference count > 1*/
    if (--rep->count == 0) delete rep;
}

String String::operator+(const String& rhs) {
    // Here we have 2 memory allocations in StringRep::operator+()
    // And 1 memory allocation in String(const char* s)
    // This can be optimized as the temp is a local variable
    // We can "move" it's value to String
    StringRep temp = *rep + *rhs.rep;
    return String(temp.rep);
}

int String::referenceCount() const { return rep->count; }

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << *str.rep;
    return os;
}

