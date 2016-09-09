#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

const int p = 2;

struct GF {
    vector<int> m;
    vector<vector<int> > F;

    GF(const vector<int> &m) {
        this->m = m;

        int n = pow(p, this->m[0]) - 1;
        vector<int> temp(1, 0);
        F.push_back(temp);

        for (int i = 1; i < n; ++i) {
            F.push_back(F[i - 1]);
            for (int j = 0; j < F[i].size(); ++j)
                ++F[i][j];

            for (int j = 0; j < F[i].size(); ++j)
                if (F[i][j] == m[0]) {
                    F[i][j] = m[1];
                    for (int q = 2; q < m.size(); ++q)
                        F[i].push_back(m[q]);

                    sort(F[i].begin(), F[i].end());
                }

            F[i] = foo(F[i]);
        }
    }

    vector<int> foo(const vector<int> &F) {
        vector<int> temp;
        temp.push_back(F[0]);

        for (int j = 1; j < F.size(); ++j) {
            if (!temp.empty()) {
                if (F[j] == temp[temp.size() - 1])
                    temp.pop_back();
                else
                    temp.push_back(F[j]);
            } else
                temp.push_back(F[j]);
        }

        return temp;
    }

    void multiply() {
        int s = F.size();

        cout << "    ";
        for (int i = 1; i < s; ++i)
            cout << setw(2) << i << " ";
        cout << endl << endl;

        for (int i = 1; i < s; ++i) {
            cout << i << "   ";
            for (int j = 1; j < s; ++j) {
                int t = 0;

                for (int q = 0; q < F[(i + j) % s].size(); ++q)
                    t += 1 << F[(i + j) % s][q];

                cout << setw(2) << t << " ";
            }
            cout << endl;
        }
    }

    vector<int> sum(vector<int> &a, vector<int> &b) {
        vector<int> res(a.size() + b.size());
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());

        res = foo(res);

        return res;
    }


    void print_field() {
        for (int i = 0; i < F.size(); ++i) {
            cout << i << "   ";
            if (i < 10)
                cout << " ";

            for (int j = 0; j < F[i].size(); ++j) {
                cout << "a^" << F[i][j];
                if (j != F[i].size() - 1)
                    cout << " + ";
            }
            cout << endl;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> m;

    int t;
    while (cin >> t)
        m.push_back(t);

    GF gf(m);
    gf.print_field();

    cout << endl;
    gf.multiply();

    int s = gf.F.size();

    for (int i = 1; i < s; ++i)
        cout << setw(2) << i << " ";
    cout << endl << endl;

    for (int i = 1; i < s; ++i) {
        cout << i << "   ";
        for (int j = 1; j < s; ++j) {
            int t = 0;
            vector<int> v = gf.sum(gf.F[i], gf.F[j]);

            for (int q = 0; q < v.size(); ++q)
                t += 1 << v[q];

            cout << setw(2) << t << " ";
        }

        cout << endl;
    }

    return 0;
}