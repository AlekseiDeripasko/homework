#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "The inscription will appear in 5 seconds" << std::endl;
    sleep(5);    
    std::cout << "Text: The program ended successfully!" << std::endl;
    return 0;
}
