#ifndef DES_INTERPRETER_H
#define DES_INTERPRETER_H


#include <string>
#include <unordered_map>

class Interpreter {
public:
    Interpreter();
    enum OperationType {
        ENCODE,
        DECODE,
        HELP,
        EXIT,
    };
    int run();

private:
    std::unordered_map <std::string, OperationType > operations;
};


#endif //DES_INTERPRETER_H