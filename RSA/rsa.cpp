#include <iostream>
#include <vector>

using namespace std;

void itoa (vector<int> &v, int n) {
	while(n != 0) {
		v.push_back(n & 1);
		n >>= 1;
	}

	reverse(v.begin(), v.end());
}

bool witness (int a, int p) {
	vector<int> bin_p;
	itoa(bin_p, p - 1);

	int d = 1;
	for (int i = bin_p.size() - 1; i >= 0; --i) {
		int x = d;
		d = (d * d) % p;
		
		if (d == 1 && x != 1 && x != p - 1)
			return true;

		if (bin_p[bin_p.size() - i - 1] == 1)
			d = (d * a) % p;
	}

	if (d != 1)
		return true;

	return false;
}

bool miller_rabin (int p, int s) {
	for (int j = 0; j < s; ++j)
	{
		int a = (rand() % (p - 1)) + 1;
		if (witness(a, p))
			return false;
	}
	return true;
}

int get_prime () {
	while(true) 
	{
    	int p = rand() % INT32_MAX;
    	if (miller_rabin(p, 6))
    		return p;
    }
}

int gcd (int a, int b, int &x, int & y) {
	if (!a) 
	{
		x = 0; y = 1;
		return b;
	}

	int x1, y1;
	int d = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;

	return d;
}

int pow (long long x, long long pw, long long mod) {
	vector<int> binary;
	itoa(binary, pw);

	long long t = x;
	for (int i = 1; i < binary.size(); ++i) 
		t = (t * t % mod) * (binary[i] == 1 ? x : 1) % mod;

	return t;
}

int euler_function(int p, int q) {
	return (p - 1) * (q - 1);
}

int main() {
    freopen("rsa.in", "r", stdin);
    freopen("rsa.out", "w", stdout);

 	int p = get_prime();
 	int q = get_prime();
 	cout << p << " " << q << endl;

 	int n = p * q;
 	int phi = euler_function(p, q);
 	
 	int e = 65537;
 	int d;
 	int y;

 	int nod = gcd(e, phi, d, y);
 	if (nod != 1)  {
 		cout << "error";
 		return 0;
 	}

 	d = ((d % phi) + phi) % phi;

 	int X;
 	cin >> X;

 	int Y = pow(X, e, n);
 	cout << Y << endl;

 	X = pow(Y, d, n);

 	cout << X;
	
    return 0;
}