#pragma once
#include <iostream>
class StringRep;
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
    StringRep *rep;
};
