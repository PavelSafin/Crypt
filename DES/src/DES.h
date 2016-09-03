#include <iostream>
#include <vector>
#include <algorithm>

#define KEY_LENGTH 64

using namespace std;

class DES {
public:
    DES ();
    DES (long long key);
    void set_message(string &message);

    string get_message();

    void set_key(long long key);

    string encode_message();

    string decode_message();

    void generate_keys();

    void crypt(vector<int> &block, vector<vector<int> > &keys);

    void initial_permutation(vector<int> &m);

    void split(vector<int> &left, vector<int> &right, vector<int> &target, int size);

    void foo(vector<int> &subblock, vector<int> &key);

    void merge(vector<int> &left, vector<int> &right, vector<int> &target, int size);

    void final_permutation(vector<int> &m);

    void expand(vector<int> &m);

    int bin_vector_to_char(vector<int> &m);

    void char_to_bin_vector(char c, vector<int> &m, int l);

    void key_permutation(vector<int> &key);

    vector<int> next_key(vector<int> &key, int n);

    ~DES();
private:
    vector<vector<int> > keys;
    string message;
    long long key;
};