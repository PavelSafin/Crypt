#include "des.h"

#define MODE "encrypt"

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector < vector <int> > keys (17);
    generate_keys(keys);
    
    string message = "", temp;
    while (cin >> temp) message += temp;
    while(message.size() % 8) message += " ";

    if (MODE == "decrypt") 
    {   
        reverse(keys.begin() + 1, keys.end());
    }

    for (int i = 0; i < message.size(); i += 8)
    {   
        vector <int> block (64);

        // for (int i = 0; i < 64; ++i)
        //     cin >> block[i];

        char_to_bin_vector(message[i], block, 7);
        char_to_bin_vector(message[i + 1], block, 15);
        char_to_bin_vector(message[i + 2], block, 23);
        char_to_bin_vector(message[i + 3], block, 31);
        char_to_bin_vector(message[i + 4], block, 39);
        char_to_bin_vector(message[i + 5], block, 47);
        char_to_bin_vector(message[i + 6], block, 55);
        char_to_bin_vector(message[i + 7], block, 63);

        crypt(block, keys);

        // for (int i = 0; i < 64; ++i)
        //     cout << block[i] << " ";

        for (int i = 0; i < 64; i += 8)
        {
            vector<int> t (block.begin() + i, block.begin() + i + 8);
            cout << char(bin_vector_to_char(t));
        }
    } 

    return 0;
}

