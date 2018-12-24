#pragma once
#include <iostream>
class String;
class StringRep {
   public:
    friend class String;
    friend std::ostream& operator<<(std::ostream& os, const StringRep& str);
    StringRep();
    StringRep(const StringRep&);
    StringRep(const char* s);
    StringRep& operator=(const StringRep& rhs);
    ~StringRep();

    int length() const;
    StringRep operator+(const StringRep& rhs);

   private:
    char* rep;
    int count;
};
