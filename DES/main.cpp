#include <iostream>
#include <sstream>
#include "DES.h"

int main() {
    string key;
    string message;

    std::cout << "Please enter message" << std::endl;
    std::cin >> message;

    std::cout << "Please enter key (64-bit number)" << std::endl;
    std::cin >> key;

//    if (key < ULLONG_MAX && key > 0) {
        DES des(key);

        des.set_message(message);
        cout << des.encode_message() << endl;
//    } else {
//        std :: cout << "Invalid number" << std::endl;
//    }
}