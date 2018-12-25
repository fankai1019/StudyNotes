#include <iostream>
#include "String.h"

int main() {
    std::cout << "The code below: \n"
                 "=====================================================\n"
                 "String a(\"hello world\");\n"
                 "String b(a);\n"
                 "std::cout << a << std::endl << b << std::endl;\n"
                 "std::cout << \"The reference count of a is: \" << \n"
                 "a.referenceCount()\n"
                 "          << std::endl;\n"
                 "std::cout << \"The reference count of b is: \" << \n"
                 "b.referenceCount()\n"
                 "          << std::endl;\n"
                 "=====================================================\n"
                 "outputs: \n"
              << std::endl;

    String a("hello world");
    String b(a);
    std::cout << a << std::endl << b << std::endl;
    std::cout << "The reference count of a is: " << a.referenceCount()
              << std::endl;
    std::cout << "The reference count of b is: " << b.referenceCount()
              << std::endl;

    return 0;
}
