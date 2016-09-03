#include <fstream>
#include "DES.h"

int main(int argc, char *argv[]) {

    if (argc == 1) {
        cerr << "too few arguments, expected 1" << endl;
        return 0;
    }

    ifstream in(argv[1]);
    ofstream out("des.out");

    if (!in.is_open()) {
        cerr << "File doesn't exist." << endl;
        return 0;
    }

    string input;
    cout << "Please enter password (64-bit number)" << endl;
    cin >> input;

    long long key = 0;
    try {
        key = stoll(input);
    }
    catch (const out_of_range &oor) {
        cerr << "Out of Range error: " << oor.what() << endl;
    }
    catch (const invalid_argument& ia) {
        cerr << "Invalid argument: " << ia.what() << endl;
    }
    catch (...) {
        cerr << "Unknown error" << endl;
    }

    DES des;
    des.set_key(key);

    ::string content((istreambuf_iterator<char>(in)),
                        (istreambuf_iterator<char>()));

    des.set_message(content);
    string s = des.encode_message();
    des.set_message(s);

    out << s << endl;
    out << des.decode_message() << endl;


    //des.~DES();

    return 0;
}