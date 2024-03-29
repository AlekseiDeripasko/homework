#include <iostream>
#include "first.h"
#include "second.h"

int main() {
    std::cout << "The result of the A-equation: " << first_equation() << std::endl;
    std::cout << "The result of the B-equation: " << second_equation() << std::endl;
    return 0;
}
