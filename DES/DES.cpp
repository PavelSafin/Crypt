#include "des.h"

#define MODE "encrypt"

using namespace std;

int main() {
    freopen("des.in", "r", stdin);
    freopen("des.out", "w", stdout);

    vector<vector<int> > keys(17);
    vector< vector <int> > cryptBlock;
    generate_keys(keys);

    string message = "", temp;
    while (cin >> temp) message += temp;
    while (message.size() % 8) message += " ";

    if (MODE == "decrypt") {
        reverse(keys.begin() + 1, keys.end());
    }

    for (int i = 0; i < message.size(); i += 8) {
        vector<int> block(64);

        char_to_bin_vector(message[i], block, 7);
        char_to_bin_vector(message[i + 1], block, 15);
        char_to_bin_vector(message[i + 2], block, 23);
        char_to_bin_vector(message[i + 3], block, 31);
        char_to_bin_vector(message[i + 4], block, 39);
        char_to_bin_vector(message[i + 5], block, 47);
        char_to_bin_vector(message[i + 6], block, 55);
        char_to_bin_vector(message[i + 7], block, 63);

        crypt(block, keys);

        cryptBlock.push_back(block);

        for (int q = 0; q < 64; q += 8) {

            vector<int> t;
            for (int j = q; j < q + 8; ++j) {
                t.push_back(block[j]);
            }
            //vector <int> t (block.begin() + i, block.begin() + i + 8);

            cout << char(bin_vector_to_char(t));
        }
    }

    cout << endl;

    reverse(keys.begin() + 1, keys.end());

    for (int i = 0; i < cryptBlock.size(); ++i) {
        vector<int> block = cryptBlock[i];

        crypt(block, keys);

        for (int q = 0; q < 64; q += 8) {

            vector<int> t;
            for (int j = q; j < q + 8; ++j) {
                t.push_back(block[j]);
            }
            //vector <int> t (block.begin() + i, block.begin() + i + 8);

            cout << char(bin_vector_to_char(t));
        }
    }

    return 0;
}