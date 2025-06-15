#include <iostream>

#include "string.hpp"

using namespace StringKlasse;

int main() {
    String a = "Hallo";
    String b = 'a';
    std::cout << a;
    std::cout << b;
    b = a;
    std::cout << b << a;
    a = a;
    std::cout << a;
    b = b;
    std::cout << b;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}