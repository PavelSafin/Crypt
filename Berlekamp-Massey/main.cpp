#include <iostream>

using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string z;
    cin >> z;

    int *discrepancy = (int *) malloc(z.size() * sizeof(int));

    string m = "";

    string c;
    string b;
    c = b = "0";

    int r = 0;
    while (r < z.size()) {
        string t;
        m += z[r - 1];
        t = m;

        for (int j = 0; j < m.size(); ++j)
            t[j] = (m[j] == 49 && c[j] == 49 ? 49 : 48);


        int count = 0;
        for (int k = 0; k < t.size(); ++k)
            if (t[k] == 49)
                ++count;

        discrepancy[r - 1] = count & 1;

        if (!discrepancy[r - 1]) {
            b += "0";
            c = "0" + c;
        } else {
            b += "0";
            t = b;

            for (int k = c.size() - 1; k >= 0; --k)
                t[k + 1] = (c[k] == 48 && b[k + 1] == 48) || (c[k] == 49 && b[k + 1] == 49) ? 48 : 49;

            t[0] = b[0];

            b = "0" + c,
                    c = t;
        }

        ++r;
    }


    int L = 0;

    for (int i = 0; i < c.size(); ++i)
        if (c[i] == 49) {
            if (!L)
                L = c.size() - i - 1;

            if (i != c.size() - 1)
                cout << "x^" << c.size() - i - 1 << " + ";
            else
                cout << 1;
        }

    cout << endl << "L = " << L;
}