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

static std::vector<char> ReadAllBytes(char const *filename) {
    ifstream ifs(filename, ios::binary | ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    std::vector<char> result(pos);

    ifs.seekg(0, ios::beg);
    ifs.read(&result[0], pos);

    return result;
}

int Interpreter::run() {
    ofstream out("des.out");
    DES des;
    DES des1;
    string key;
    vector <char> message;
    string temp;

    while (true) {
        string command;
        cout << ">>> ";
        cin >> command;

        switch (operations[command]) {
            case ENCODE:
                cout << "Please enter password (64-bit number)" << endl;
                cin >> key;

                message = ReadAllBytes("des.in");
                temp = string(message.begin(), message.end());

                des.set_key(key);
                des.set_message(temp);

                out << des.encode_message() << endl;
                break;
            case DECODE:
                cout << "Please enter password (64-bit number)" << endl;
                cin >> key;

                message = ReadAllBytes("des.in");
                temp = string(message.begin(), message.end());

                des1.set_key(key);
                des1.set_message(temp);

                cout << des1.decode_message() << endl;
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
