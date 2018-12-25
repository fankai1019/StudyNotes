#pragma once
#include <iostream>
class String;
class StringRep {
   public:
    friend class String;
    friend std::ostream& operator<<(std::ostream& os, const StringRep& str);

    typedef char* Char_p;

    StringRep();
    StringRep(const StringRep&);
    StringRep(const char* s);
    StringRep& operator=(const StringRep& rhs);
    ~StringRep();

    int length() const;
    //    StringRep operator+(const StringRep& rhs);

   private:
    StringRep(Char_p* const pp);
    char* rep;
    int count;
};
