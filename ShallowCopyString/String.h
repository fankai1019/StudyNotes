#pragma once
#include <iostream>
#include "StringRep.h"
// This class is used to implement reference counting for String
// All normal string operations are forwarded to StringRep class
// This class is only responsible for reference counting part
class String {
   public:
    friend std::ostream &operator<<(std::ostream &os, const String &str);
    String();
    String(const String &);
    String(const char *);
    String &operator=(const String &);
    ~String();

    String operator+(const String &);
    int referenceCount() const;

   private:
    String(StringRep::Char_p *const pp);
    StringRep *rep;
};
