#include <iostream>

int main() {
    unsigned long long key;
    std::string message;

    std::cout << "Please enter message" << std::endl;
    std::cin >> message;

    std::cout << "Please enter key (64-bit number)" << std::endl;
    std::cin >> key;

    if (key < ULLONG_MAX && key > 0) {
        //Do something
    } else {
        std :: cout << "Invalid number" << std::endl;
    }
}