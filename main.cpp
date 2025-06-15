#include <iostream>

#include "string.hpp"

using namespace StringKlasse;

int main() {
    String a = "Hallo";
    std::cout << a << std::endl;
    String b = a.toUpper();
    std::cout << 'A' - 'a' << std::endl;
    std::cout << b << std::endl;
    b.toLower();
    std::cout << b << std::endl;
    // std::cout << a.toLower() << std::endl;
    // String b = 'a';
    // std::cout << a;
    // std::cout << b;
    // b = a;
    // std::cout << b << a;
    // a = a;
    // std::cout << a;
    // b = b;
    // std::cout << b;
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}