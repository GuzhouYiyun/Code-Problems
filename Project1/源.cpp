#include "bits_stdc++.h"
using namespace std;
typedef long long ll;

int p;

ll ksm(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = (ans * a) % p;
			--b;
		}
		else {
			b >>= 1;
			a = (a * a) % p;
		}
	}
	return ans;
}

ll C(ll n, ll m) {
	ll a = 1, b = 1;
	for (int i = n; i > n - m; --i) {
		a = (a * i) % p;
	}
	for (int i = m; i > 1; --i) {
		b = (b * i) % p;
	}

	return (a * ksm(b, p - 2)) % p;
}

ll lucas(ll n, ll m) {
	if (m == 0) {
		return 1;
	}

	return ((lucas(n / p, m / p) % p) * C(n % p, m % p)) % p;
}

int main(void) {

	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m >> p;

		int t = min(m, n);
		cout << lucas(n + m, t) << endl;
	}

	return 0;
}