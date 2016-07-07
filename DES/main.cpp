#include <iostream>
#include <sstream>
#include "DES.h"

int main() {
    string key;
    string message;

    while (true) {
        cout << ">>> ";
        string command;
        cin >> command;

        if (command == "exit") {
            break;
        } else {
            if (command == "encode") {
                cout << "Please enter password (64-bit number)" << std::endl;
                cin >> key;

                cout << "Please enter message" << std::endl;
                cin >> message;

                DES des(key);
                des.set_message(message);

                cout << des.encode_message() << endl;

                des.~DES();
            } else {
                if (command == "help") {
                    cout << "encode: Crypt your message" << endl
                    << "decode: Decrypt your message" << endl
                    << "exit: Exit from shell" << endl;
                } else {
                    cout << "Try type \"help\"";
                }
            }
        }
    }

    return 0;
}