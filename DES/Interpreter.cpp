#include <iostream>
#include <fstream>
#include "Interpreter.h"
#include "DES.h"


Interpreter::Interpreter() {
    operations.insert(std::make_pair<std::string, OperationType>("encode", ENCODE));
    operations.insert(std::make_pair<std::string, OperationType>("decode", DECODE));
    operations.insert(std::make_pair<std::string, OperationType>("exit", EXIT));
    operations.insert(std::make_pair<std::string, OperationType>("help", HELP));
}

int Interpreter::run() {
    DES des;
    string key;
    string message;

    while (true) {
        std::string command;
        std::cout << ">>> ";
        std::cin >> command;

        switch (operations[command]) {
            case ENCODE:

                cout << "Please enter password (64-bit number)" << endl;
                cin >> key;

                cout << "Please enter message" << std::endl;
                cin >> message;

                des.set_key(key);
                des.set_message(message);

                cout << des.encode_message() << endl;
                break;
            case DECODE:
                break;
            case EXIT:
                std::cout << "Exit from interpreter";
                des.~DES();
                return 0;
            case HELP:
                std::cout << "encode: Crypt your message" << std::endl
                << "decode: Decrypt your message" << std::endl
                << "exit: Exit from interpreter" << std::endl;
                break;
            default:
                std::cout << "Try type \"help\"" << std::endl;
                break;
        }
    }
}

static std::vector<char> ReadAllBytes(char const *filename) {
    ifstream ifs(filename, ios::binary | ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    std::vector<char> result(pos);

    ifs.seekg(0, ios::beg);
    ifs.read(&result[0], pos);

    return result;
}