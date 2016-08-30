#include <iostream>
#include <fstream>
#include "DES.h"

int main() {

    ofstream out("des.out");
    DES des;
    string key;

    cout << "Please enter password (64-bit number)" << endl;
    cin >> key;
    des.set_key(key);


    std::ifstream ifs("des.in");
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));

    des.set_message(content);
    out << des.encode_message();
//    out << des.decode_message() << endl;

    return 0;
}

//1111111100000000111111110000000011111111000000001111111100000000